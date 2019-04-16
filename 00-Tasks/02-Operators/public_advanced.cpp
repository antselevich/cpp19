#include "entry_point.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace Task02 {
    TEST(PublicAdvanced, InitializerList) {
        EXPECT_NO_THROW({
                            Vector v({1, 2, 3});
                        });

        EXPECT_NO_THROW({
                            Matrix m({
                                             {1, 2, 3},
                                             {4, 5, 6},
                                             {7, 8, 9},
                                     });
                        });
    }

    TEST(PublicAdvanced, InitializerList_RangeChecking) {
        EXPECT_THROW({
                            Vector v({1, 2, 3, 4});
                     },
                     OutOfBoundException);
        EXPECT_THROW({
                        Matrix m({
                                         {1, 2, 3, 4}
                                 });
                     },
                     OutOfBoundException);
    }

    TEST(PublicAdvanced, OutputToStream) {
        Matrix m(1.234567f);
        std::ostringstream stream;

        stream << m;
        ASSERT_STREQ(stream.str().c_str(), "((1.235,1.235,1.235),(1.235,1.235,1.235),(1.235,1.235,1.235))");

        Vector v(3.141592);
        std::ostringstream stream2;

        stream2 << v;
        ASSERT_STREQ(stream2.str().c_str(), "(3.142,3.142,3.142)");
    }

    TEST(PublicAdvanced, InputFromStream) {
        Matrix m;
        std::istringstream stream("0 1 2 0 0 0 0 0 0");

        stream >> m;
        ASSERT_FLOAT_EQ(m[0][0], 0.0f);
        ASSERT_FLOAT_EQ(m[0][1], 1.0f);
        ASSERT_FLOAT_EQ(m[0][2], 2.0f);

        Vector v;
        std::istringstream stream2("0 1 2");

        stream2 >> v;
        ASSERT_FLOAT_EQ(v[0], 0.0f);
        ASSERT_FLOAT_EQ(v[1], 1.0f);
        ASSERT_FLOAT_EQ(v[2], 2.0f);
    }
}
