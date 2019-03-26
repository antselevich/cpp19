#!/usr/bin/python3
import argparse
import contextlib
import enum
import logging
import os
import shutil
import subprocess
import sys
import tarfile
import tempfile
import zipfile
from distutils.dir_util import copy_tree
from urllib.request import urlopen

log = logging.getLogger(__name__)


class Platform(enum.Enum):
    MACOS = 'Mac'
    LINUX = 'Linux_x64'
    WINDOWS = 'Win'


class ExitCode(enum.Enum):
    SUCCESS = 0
    OTHER_ERRORS = 1
    TESTS_ERRORS = 3


def _unpack_file(archive, dst_dir):
    log.debug('Unpacking archive to {}'.format(dst_dir))
    tmp_dir = tempfile.mkdtemp()

    if tarfile.is_tarfile(archive):
        with tarfile.open(archive) as tar:
            tar.extractall(tmp_dir)
    elif zipfile.is_zipfile(archive):
        with zipfile.ZipFile(archive) as zip_archive:
            zip_archive.extractall(tmp_dir)
    else:
        raise RuntimeError('Unknown archive type. Must be valid tar or zip archive')

    copy_tree(tmp_dir, dst_dir)


@contextlib.contextmanager
def temporary_file(**tempfile_args):
    file_ = tempfile.NamedTemporaryFile(delete=False, **tempfile_args)
    try:
        file_.close()
        yield file_.name
    finally:
        os.remove(file_.name)


def _subprocess_call(command, env=None):
    log.debug('Command:\n{}\nEnvironment:\n{}'.format(command, env))
    try:
        out = subprocess.check_output(command, stderr=subprocess.STDOUT, env=env, universal_newlines=True)
        log.debug('Output:\n{}'.format(out))
        return out
    except subprocess.CalledProcessError as e:
        raise RuntimeError('FAILED.\nCommand:{}\nExitcode: {}. Output:\n{}'.format(
            command,
            e.returncode,
            e.output),
        )


def _download_file(url, target):
    log.debug('Downloading archive from {} to {}'.format(url, target))
    with urlopen(url, timeout=120) as f:
        data = f.read()

    with open(target, 'wb') as fd:
        fd.write(data)


def _download_archive(url, target):
    log.debug('Downloading archive from {} and unpack to {}'.format(url, target))
    with temporary_file() as archive_file:
        _download_file(url, archive_file)
        _unpack_file(archive_file, target)


def _find_makefile_dir(start_directory):
    content = os.listdir(start_directory)
    if 'Makefile' in content:
        return start_directory

    if len(content) != 1:
        return None

    next_dir = os.path.join(start_directory, content[0])
    if 'Makefile' in os.listdir(next_dir):
        return next_dir

    return None


def _has_only_archive(directory):
    content = os.listdir(directory)
    if len(content) != 1:
        return False

    archive_file = os.path.join(directory, content[0])
    if tarfile.is_tarfile(archive_file) or zipfile.is_zipfile(archive_file):
        return True

    return False


class BaseChecker:
    def __init__(self, sources, task_name, cash_dir):
        self._check_system_dir = cash_dir
        self._sources = sources
        self._task_name = task_name
        self._workdir = tempfile.mkdtemp()

        if sys.platform.startswith('darwin'):
            self._platform = Platform.MACOS
        elif sys.platform.startswith('linux'):
            self._platform = Platform.LINUX
        elif sys.platform.startswith('win32') or sys.platform.startswith('cygwin'):
            self._platform = Platform.WINDOWS
        else:
            raise RuntimeError('Unknown platform: {}'.format(sys.platform))

        self._clang_dir = os.path.join(self._check_system_dir, 'clang')
        self._llvm_code_coverage = os.path.join(self._check_system_dir, 'llvm-code-coverage')
        self._libcxx_dir = os.path.join(self._check_system_dir, 'libc++.so')
        self._gtest = os.path.join(self._check_system_dir, 'googletest')

        if self._platform == Platform.WINDOWS:
            self._make_dir = os.path.join(self._check_system_dir, 'make')
            self._make_bin = os.path.join(self._make_dir, 'bin', 'make.exe')
        else:
            self._make_dir = None
            self._make_bin = 'make'

        self._cxx_path = os.path.join(self._clang_dir, 'bin', 'clang++')
        self._profdata_path = os.path.join(self._llvm_code_coverage, 'bin', 'llvm-profdata')
        self._cov_path = os.path.join(self._llvm_code_coverage, 'bin', 'llvm-cov')

        if self._platform == Platform.LINUX:
            self._sanitizers = ('address', 'undefined',)  # 'memory')
        else:
            # TODO: add libclang_rt.ubsan_osx_dynamic.dylib to Mac archive
            self._sanitizers = ('address',)

    def get_workdir(self):
        return self._workdir

    def set_up(self):
        if not os.path.exists(self._clang_dir):
            log.debug('CLang downloading')
            _download_archive(
                'https://urgu.org/chromium-browser-clang/{}/clang-346388-4.tgz'.format(self._platform.value),
                self._clang_dir,
            )

        if not os.path.exists(self._llvm_code_coverage):
            log.debug('LLVM Code Coverage downloading')
            _download_archive(
                'https://urgu.org/chromium-browser-clang/{}/llvm-code-coverage-346388-4.tgz'.format(
                    self._platform.value,
                ),
                self._llvm_code_coverage,
            )

        if not os.path.exists(self._gtest):
            log.debug('GTEST downloading')
            _download_archive('https://github.com/google/googletest/archive/release-1.8.1.tar.gz', self._gtest)

        if self._platform == Platform.WINDOWS and not os.path.exists(self._make_dir):
            log.debug('Make downloading')
            _download_archive(
                'https://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81-bin.zip/download',
                self._make_dir,
            )
            _download_archive(
                'https://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81-dep.zip/download',
                self._make_dir,
            )

        self._prepare_workdir()

        if self._task_name:
            script_directory = os.path.dirname(os.path.abspath(__file__))
            if os.path.exists(os.path.join(script_directory, 'tests')):
                tests_dir = os.path.join(script_directory, 'tests', self._task_name)
                if os.path.exists(tests_dir):
                    shutil.copy(os.path.join(tests_dir, 'private.cpp'), os.path.join(self._workdir, 'private.cpp'))
                    shutil.copy(os.path.join(tests_dir, 'private_advanced.cpp'), os.path.join(self._workdir, 'private_advanced.cpp'))
                    shutil.copy(os.path.join(tests_dir, 'public.cpp'), os.path.join(self._workdir, 'public.cpp'))
                    shutil.copy(os.path.join(tests_dir, 'public_advanced.cpp'), os.path.join(self._workdir, 'public_advanced.cpp'))

    def _save_makefile_dir(self, directory):
        makefile_dir = _find_makefile_dir(directory)
        if makefile_dir is not None:
            copy_tree(makefile_dir, self._workdir)
        else:
            raise RuntimeError('`Makefile` could not be found')

    def _prepare_workdir(self):
        if _has_only_archive(self._sources):
            log.debug('Unpack sources archive')
            with tempfile.TemporaryDirectory() as tmp_dir:
                _unpack_file(
                    os.path.join(self._sources, os.listdir(self._sources)[0]),
                    tmp_dir,
                )
                self._save_makefile_dir(tmp_dir)
        else:
            self._save_makefile_dir(self._sources)

    def _make(self, target, flags=''):
        make_command = [
            self._make_bin,
            '--no-print-directory',
            '-j',
            'CXX={}'.format(self._cxx_path),
            'LD={}'.format(self._cxx_path),
            'GTEST={}'.format(os.path.join(self._gtest, 'googletest-release-1.8.1', 'googletest')),
            'GMOCK={}'.format(os.path.join(self._gtest, 'googletest-release-1.8.1', 'googlemock')),
            'COMPILER_FLAGS={}'.format(flags),
            'LINKER_FLAGS={}'.format(flags),
            '-C', self._workdir,
            target,
        ]

        return _subprocess_call(make_command)

    def _run_target(self, target, only_warnings=False):
        env = os.environ
        env['PATH'] += os.pathsep + os.path.join(self._clang_dir, 'bin')
        if self._platform == Platform.MACOS:
            env['DYLD_LIBRARY_PATH'] = os.path.join(self._clang_dir, 'lib', 'clang', '8.0.0', 'lib', 'darwin')

        try:
            out = _subprocess_call([os.path.join(self._workdir, target), '--gtest_color=no'], env=env)
        except RuntimeError as e:
            if only_warnings:
                log.warning('{}: {}'.format(target, e))
            else:
                raise RuntimeError('{}: {}'.format(target, e))
        else:
            log.debug(out)

    def run_unittests(self):
        log.debug('Run local unit tests')

        for sanitizer in self._sanitizers:
            log.debug('Run with {} sanitizer'.format(sanitizer))

            self._make('clean')
            self._make('all', '-fsanitize={}'.format(sanitizer))

            self._run_target('check')

    def run_with_coverage(self, cov_format='report'):
        if self._platform == Platform.WINDOWS:
            log.info('No coverage for Windows')
            return

        log.debug('Run tests with coverage')

        profraw_file = os.path.join(self._workdir, 'check.profraw')
        profdata_file = os.path.join(self._workdir, 'check.profdata')
        coverage_flags = '-fprofile-instr-generate={} -fcoverage-mapping'.format(profraw_file)

        self._make('clean', coverage_flags)
        self._make('all', coverage_flags)

        _subprocess_call([os.path.join(self._workdir, 'check')])
        _subprocess_call([self._profdata_path, 'merge', '-sparse', profraw_file, '-o', profdata_file])
        out = _subprocess_call([
            self._cov_path,
            cov_format,
            '--ignore-filename-regex={}'.format(self._gtest),
            '-instr-profile={}'.format(profdata_file),
            os.path.join(self._workdir, 'check')
        ])
        log.info('Coverage results:\n{}'.format(out))

    def run_tests(self):
        for sanitizer in self._sanitizers:
            log.info('Run tests with {} sanitizer'.format(sanitizer))

            self._make('clean')
            self._make('all', '-fsanitize={}'.format(sanitizer))

            self._run_target('public')
            self._run_target('public_advanced', True)
            self._run_target('private')
            self._run_target('private_advanced', True)

    def remove_workdir(self):
        if os.path.exists(self._workdir):
            log.debug('Remove working directory: {}'.format(self._workdir))
            shutil.rmtree(self._workdir)


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', '--debug', action='store_true', help='Enable debug mode')
    parser.add_argument('-s', '--save-state', action='store_true', help='Save building files')
    parser.add_argument('-c', '--coverage-format', default='report', choices=['report', 'show'])
    parser.add_argument('-a', '--cash-dir', default=os.path.abspath(os.path.dirname(__file__)),
                        help='Directory for uploading CLang, Google Test and LLVM')
    parser.add_argument('task_name', nargs='?', help='Name of task at anytask.org')
    parser.add_argument('sources', help='Directory with sources or archive')

    args = parser.parse_args()
    return args


def main():
    args = parse_args()
    logging.basicConfig(level=logging.DEBUG if args.debug else logging.INFO)

    checker = BaseChecker(args.sources, args.task_name, args.cash_dir)

    try:
        checker.set_up()

        checker.run_unittests()
        checker.run_with_coverage(args.coverage_format)
        checker.run_tests()

        log.info('SUCCESS')
        exitcode = ExitCode.SUCCESS
    except RuntimeError as e:
        log.error(e)
        exitcode = ExitCode.TESTS_ERRORS
    except Exception as e:
        log.exception(e)
        exitcode = ExitCode.OTHER_ERRORS
    finally:
        if not args.save_state:
            checker.remove_workdir()
        else:
            log.info('Building state saved in {}'.format(checker.get_workdir()))

    sys.exit(exitcode.value)


if __name__ == '__main__':
    sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    main()
