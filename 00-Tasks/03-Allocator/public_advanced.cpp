#include "entry_point.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace Task03 {

    class PublicAdvanced : public ::testing::Test {
    protected:

        std::vector<void *> Fill(Allocator a, size_t element_size) {
            std::vector<void *> pointers;
            void *ptr;
            for (;;) {
                try {
                    ptr = a.Allocate(element_size);
                }
                catch (const NotEnoughMemory &e) {
                    break;
                }
                pointers.push_back(ptr);
            }
            return pointers;
        }

        double RunPerformanceTest(size_t memory_size) {
            auto memory = malloc(memory_size);
            Allocator a(memory, memory_size);

            clock_t begin = clock();
            auto pointers = Fill(a, 10);
            clock_t end = clock();

            free(memory);

            return double(end - begin) / CLOCKS_PER_SEC;  // elapsed seconds
        }

        double RunMemoryOverheadTest(size_t memory_size, size_t element_size) {
            auto memory = malloc(memory_size);
            Allocator a(memory, memory_size);

            auto pointers = Fill(a, element_size);
            double elements_total_size = element_size * pointers.size();

            free(memory);

            return elements_total_size / memory_size;
        }
    };

    TEST_F(PublicAdvanced, AllocateIsFast) {
        size_t initial_size = 100000;
        double x = RunPerformanceTest(initial_size);
        double y = RunPerformanceTest(initial_size * 10);

        ASSERT_LE(y / x, 30);  // Not O(N) for each allocation, at least
    }

    TEST_F(PublicAdvanced, OverheadFor1ByteObjects) {
        ASSERT_GE(RunMemoryOverheadTest(10000, 1), 0.6);
    }

    TEST_F(PublicAdvanced, OverheadFor8ByteObjects) {
        ASSERT_GE(RunMemoryOverheadTest(10000, 8), 0.6);
    }

    TEST_F(PublicAdvanced, OverheadFor16ByteObjects) {
        ASSERT_GE(RunMemoryOverheadTest(10000, 16), 0.6);
    }

    TEST_F(PublicAdvanced, OverheadFor64ByteObjects) {
        ASSERT_GE(RunMemoryOverheadTest(10000, 64), 0.6);
    }

    TEST_F(PublicAdvanced, OverheadFor1KByteObjects) {
        ASSERT_GE(RunMemoryOverheadTest(1024*1024, 1024), 0.6);
    }
}
