#include "entry_point.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace Task02 {
    TEST(Public, VectorConstructAndAssign) {
        Vector v;
        ASSERT_FLOAT_EQ(v[0], float{});

        Vector v2(3.1f);
        ASSERT_FLOAT_EQ(v2[0], 3.1f);

        v2[0] = v2[1] = 4.2f;
        ASSERT_FLOAT_EQ(v2[0], 4.2f);

        const Vector v3 = v2;
        ASSERT_FLOAT_EQ(v3[0], 4.2f);

        v2 = v;
        ASSERT_FLOAT_EQ(v2[0], float{});

        v = v2 = v3;
        ASSERT_FLOAT_EQ(v2[0], 4.2f);
        ASSERT_FLOAT_EQ(v[0], 4.2f);
    }

    TEST(Public, VectorOutOfBound) {
        Vector v;
        EXPECT_THROW(v[Vector::Size()], OutOfBoundException);

        try {
            v[Vector::Size() + 1] = 4;
        } catch (const std::exception& ex) {
            ASSERT_STREQ("Index is out of bounds", ex.what());
        }
    }

    TEST(Public, VectorOperatorBool) {
        Vector v;
        ASSERT_FALSE(v);
    }

    TEST(Public, VectorUnaryMinus) {
        Vector a(1);

        Vector b = -a;
        ASSERT_FLOAT_EQ(b[0], -1.0f);

        b = - -a;
        ASSERT_FLOAT_EQ(b[0], 1.0f);
    }

    TEST(Public, VectorMinusVector) {
        Vector a(1), b(2);

        a -= b;
        ASSERT_FLOAT_EQ(a[0], -1.0f);

        Vector c = a -= b;
        ASSERT_FLOAT_EQ(a[0], -3.0f);
        ASSERT_FLOAT_EQ(c[0], -3.0f);

        c = a - b;
        ASSERT_FLOAT_EQ(c[0], -5.0f);
    }

    TEST(Public, VectorPlusVector) {
        Vector a(1), b(2);

        a += b;
        ASSERT_FLOAT_EQ(a[0], 3.0f);

        Vector c = a += b;
        ASSERT_FLOAT_EQ(a[0], 5.0f);
        ASSERT_FLOAT_EQ(c[0], 5.0f);

        c = a + b;
        ASSERT_FLOAT_EQ(c[0], 7.0f);
    }

    TEST(Public, VectorMultVector) {
        Vector a(2.f), b(2.f);

        a *= b;
        ASSERT_FLOAT_EQ(a[0], 4.0f);
        ASSERT_FLOAT_EQ(a[1], 4.0f);
        ASSERT_FLOAT_EQ(a[2], 4.0f);

        Vector c = a * b;
        ASSERT_FLOAT_EQ(c[0], 8.0f);
        ASSERT_FLOAT_EQ(c[1], 8.0f);
        ASSERT_FLOAT_EQ(c[2], 8.0f);
    }

    TEST(Public, MatrixConstructAndAssign) {
        Matrix m;
        ASSERT_FLOAT_EQ(m[0][0], float{});

        m[2][1] = m[1][2] = 4.1f;
        ASSERT_FLOAT_EQ(m[1][2], 4.1f);
        ASSERT_FLOAT_EQ(m[2][1], 4.1f);

        auto& row = m[1];
        ASSERT_FLOAT_EQ(row[2], 4.1f);

        row[2] = 2.2f;
        ASSERT_FLOAT_EQ(m[1][2], 2.2f);

        Matrix m2 = m;
        ASSERT_FLOAT_EQ(m2[1][2], 2.2f);
        ASSERT_FLOAT_EQ(m2[2][1], 4.1f);

        Matrix m3;
        m2 = m3;
        ASSERT_FLOAT_EQ(m2[1][2], float{});
        ASSERT_FLOAT_EQ(m2[2][1], float{});

        const auto& row2 = m[2];
        ASSERT_FLOAT_EQ(row2[1], 4.1f);

        m = m2 = m3;
        ASSERT_FLOAT_EQ(row[1], float{});
    }

    TEST(Public, MatrixOutOfBound) {
        Matrix m;
        EXPECT_THROW(m[Matrix::RowsSize()], OutOfBoundException);
    }

    TEST(Public, MatrixOperatorBool) {
        Matrix m;
        ASSERT_FALSE(m);
    }

    TEST(Public, MatrixDeterminant) {
        Matrix m(1);
        ASSERT_FLOAT_EQ(~m, 0.0f);

        Matrix e;
        e[0][0] = e[1][1] = e[2][2] = 1.0f;
        ASSERT_FLOAT_EQ(~e, 1.0f);

        Matrix h;
        h[0][0] = 2.0f;
        h[0][1] = 1.0f;
        h[0][2] = 5.0f;
        h[1][0] = 4.0f;
        h[1][1] = 3.0f;
        h[1][2] = 4.0f;
        h[2][0] = 5.0f;
        h[2][1] = 2.0f;
        h[2][2] = 1.0f;

        ASSERT_FLOAT_EQ(~h, -29.0f);
    }

    TEST(Public, MatrixUnaryMinus) {
        Matrix a(1);

        Matrix result = -a;
        ASSERT_FLOAT_EQ(result[0][0], -1.0f);

        result = - -a;
        ASSERT_FLOAT_EQ(result[0][0], 1.0f);
    }

    TEST(Public, MatrixMinusMatrix) {
        Matrix a(1), b(2);

        Matrix result = a - b;
        ASSERT_FLOAT_EQ(result[0][0], -1.0f);

        result -= b;
        ASSERT_FLOAT_EQ(result[0][0], -3.0f);

        result = result -= b;
        ASSERT_FLOAT_EQ(result[0][0], -5.0f);
    }


    TEST(Public, MatrixPlusMatrix) {
        Matrix a(1), b(2);

        Matrix result = a + b;
        ASSERT_FLOAT_EQ(result[0][0], 3.0f);

        result += b;
        ASSERT_FLOAT_EQ(result[0][0], 5.0f);

        result = result += b;
        ASSERT_FLOAT_EQ(result[0][0], 7.0f);
    }

    TEST(Public, MatrixMultMatrix) {
        Matrix a(2), b;
        b[0][0] = b[1][1] = b[2][2] = 2.0f;

        Matrix product = a * b;
        ASSERT_FLOAT_EQ(product[0][0], 4.0f);

        product *= b;
        ASSERT_FLOAT_EQ(product[0][0], 8.0f);
    }

    TEST(Public, MatrixMultVector) {
        Matrix a(2);
        Vector v(2);

        Vector result = a * v;  // 3x1
        ASSERT_FLOAT_EQ(result[0], 12.0f);
    }

    TEST(Public, MatrixMultFloat) {
        Matrix a(2);

        a *= 2.0f;
        ASSERT_FLOAT_EQ(a[0][0], 4.0f);

        Matrix c = a *= 2.0f;
        ASSERT_FLOAT_EQ(c[0][0], 8.0f);
        ASSERT_FLOAT_EQ(a[0][0], 8.0f);

        Matrix result = a * 2.0f;
        ASSERT_FLOAT_EQ(result[0][0], 16.0f);

        result = 2.0f * a;
        ASSERT_FLOAT_EQ(result[0][0], 16.0f);
    }

    TEST(Public, SizeConstexpr) {
        Matrix x(4.f);
        float v[x.RowsSize()][x.ColsSize()];

        for (size_t i = 0; i < x.RowsSize(); ++i) {
            for (size_t j = 0; j < x.RowsSize(); ++j) {
                v[i][j] = x[i][j];
            }
        }
    }
}
