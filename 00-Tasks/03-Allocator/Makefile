SRCD=.

CXX=clang++
LD=clang++

GTEST=$(SRCD)/googletest/googletest
GMOCK=$(SRCD)/googletest/googlemock

ifeq ($(OS),Windows_NT)
LDFLAGS=$(LINKER_FLAGS)
RM_COMMAND=del /F /Q /S
WARN_OPTS=-Wall -Werror -pedantic -Wno-language-extension-token -Wno-deprecated-declarations
else
LDFLAGS=-lm -lpthread $(LINKER_FLAGS)
RM_COMMAND=rm -f
WARN_OPTS=-Wall -Werror -pedantic -Wno-deprecated-declarations
endif


INCLUDES=-I$(GTEST) -I$(GTEST)/include -I$(GMOCK) -I$(GMOCK)/include

CXXFLAGS=$(WARN_OPTS) $(INCLUDES) $(COMPILER_FLAGS) \
        -std=c++14 -g

LINK_EXECUTABLE=$(LD) $(LDFLAGS) -o $@ $^

COMPILE_CXX_SRC=$(CXX) $(CXXFLAGS) -c -o $@ $^

all: public public_advanced private private_advanced check

clean:
	$(RM_COMMAND) *.o private private_advanced public public_advanced check

public: public.o gtest-all.o gtest_main.o gmock-all.o
	$(LINK_EXECUTABLE)

check: gtest-all.o gtest_main.o gmock-all.o
	$(LINK_EXECUTABLE)

public_advanced: public_advanced.o gtest-all.o gtest_main.o gmock-all.o
	$(LINK_EXECUTABLE)

private: private.o gtest-all.o gtest_main.o gmock-all.o
	$(LINK_EXECUTABLE)

private_advanced: private_advanced.o gtest-all.o gtest_main.o gmock-all.o
	$(LINK_EXECUTABLE)

gtest-all.o: $(GTEST)/src/gtest-all.cc
	$(COMPILE_CXX_SRC)

gtest_main.o: $(GTEST)/src/gtest_main.cc
	$(COMPILE_CXX_SRC)

gmock-all.o: $(GMOCK)/src/gmock-all.cc
	$(COMPILE_CXX_SRC)

public.o: $(SRCD)/public.cpp
	$(COMPILE_CXX_SRC)

public_advanced.o: $(SRCD)/public_advanced.cpp
	$(COMPILE_CXX_SRC)

private.o: $(SRCD)/private.cpp
	$(COMPILE_CXX_SRC)

private_advanced.o: $(SRCD)/private_advanced.cpp
	$(COMPILE_CXX_SRC)
