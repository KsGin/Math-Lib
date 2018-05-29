/*
 * File   : vector_test
 * Author : KsGin 
 * Date   : 2018/5/23
 */

#include "../sources/vector.hpp"
#include "../sources/matrix.hpp"
#include <gtest.h>


using namespace Math;

///////////////////////////////////////////// Vector2 Test Case /////////////////////////////////////////////

/**
 * Vector2 构造方法测试
 */
TEST(Vector2, Constructor) {

    Vector2 *v1 = new Vector2(1, 1);
    ASSERT_TRUE(v1 && v1->_x == 1 && v1->_y == 1);

    Vector2 *v2 = new Vector2(*v1);
    ASSERT_TRUE(v2 && v1->_x == 1 && v1->_y == 1);

    delete v1;
    delete v2;

    Vector2 v3 = Vector2(1, 10);
    ASSERT_TRUE(v3._x == 1 && v3._y == 10);

    Vector2 v4 = Vector2(v3);
    ASSERT_TRUE(v4._x == 1 && v4._y == 10);
}

/**
 * Vector2 add() 方法测试
 */
TEST(Vector2, Add) {
    EXPECT_EQ(Vector2(1, 1) + Vector2(2, 2), Vector2(3, 3));
    EXPECT_EQ(Vector2(1.5, 1) + Vector2(2, 2), Vector2(3.5, 3));
    EXPECT_EQ(Vector2(1, 1.5) + Vector2(2, 2), Vector2(3, 3.5));
    EXPECT_EQ(Vector2(1.5, 1) + Vector2(2.5, 2), Vector2(4, 3));
}

/**
 * Vector2 sub() 方法测试
 */
TEST(Vector2, Sub) {
    EXPECT_EQ(Vector2(3, 3) - Vector2(2, 2), Vector2(1, 1));
    EXPECT_EQ(Vector2(3.5, 3) - Vector2(2, 2), Vector2(1.5, 1));
    EXPECT_EQ(Vector2(3, 3.5) - Vector2(2, 2), Vector2(1, 1.5));
    EXPECT_EQ(Vector2(4, 3) - Vector2(2.5, 2), Vector2(1.5, 1));
}

/**
 * Vector2 length() 方法测试
 */
TEST(Vector2, Length) {
    EXPECT_LE(fabs(Vector2(1, 1).length() - sqrt(2)), 0.001);
    EXPECT_LE(fabs(Vector2(2, 2).length() - sqrt(8)), 0.001);
    EXPECT_LE(fabs(Vector2(5, 6).length() - sqrt(pow(5, 2) + pow(6, 2))), 0.001);
    EXPECT_LE(fabs(Vector2(1.6, 1.7).length() - sqrt(pow(1.6, 2) + pow(1.7, 2))), 0.001);
    EXPECT_LE(fabs(Vector2(12.9, 1.1).length() - sqrt(pow(12.9, 2) + pow(1.1, 2))), 0.001);
}

/**
 * Vector2 negate() 方法测试
 */
TEST(Vector2, Negate) {
    EXPECT_EQ(Vector2(1, 1).negate(), Vector2(-1, -1));
    EXPECT_EQ(Vector2(1, -1).negate(), Vector2(-1, 1));
    EXPECT_EQ(Vector2(0, 1).negate(), Vector2(0, -1));
}

/**
 * Vector2 normalize() 方法测试
 */
TEST(Vector2, Normalize) {
    EXPECT_LE(fabs(Vector2(1, 1).normalize().length() - 1), 0.001);
    EXPECT_LE(fabs(Vector2(11.2, 12.1).normalize().length() - 1), 0.001);
    EXPECT_LE(fabs(Vector2(13, 21).normalize().length() - 1), 0.001);
    EXPECT_LE(fabs(Vector2(111.11, 123.1).normalize().length() - 1), 0.001);
    EXPECT_LE(fabs(Vector2(1.1, 109).normalize().length() - 1), 0.001);
}

/**
 * Vector2 scale() 方法测试
 */
TEST(Vector2, Scale) {
    EXPECT_EQ(Vector2(2, 2).scale(1, 0.5), Vector2(2, 1));
    EXPECT_EQ(Vector2(2, 2).scale(0.5, 0.5), Vector2(1, 1));
}

/*
 * Vector2 transform() 方法测试
 */
TEST(Vector2, Transform) {
    Matrix transMat = Matrix::identity();
    EXPECT_EQ(Vector2::transfrom(Vector2(1, 2), transMat), Vector2(1, 2));
    EXPECT_EQ(Vector2::transfrom(Vector2(3, 2), transMat), Vector2(3, 2));
}

////////////////////////////////////////////// Vector3 Test Case //////////////////////////////////////////

/**
 * Vector3 construct() 方法测试
 */
TEST(Vector3, Constructor) {
    Vector3 *v1 = new Vector3(1, 1, 1);
    ASSERT_TRUE(v1 && v1->_x == 1 && v1->_y == 1 && v1->_z == 1);

    Vector3 *v2 = new Vector3(*v1);
    ASSERT_TRUE(v2 && v2->_x == 1 && v2->_y == 1 && v2->_z == 1);

    delete v1;
    delete v2;

    Vector3 v3 = Vector3(1, 1, 1);
    ASSERT_TRUE(v3._x == 1 && v3._y == 1 && v3._z == 1);
    Vector3 v4 = Vector3(v3);
    ASSERT_TRUE(v4._x == 1 && v4._y == 1 && v4._z == 1);
}

/**
 * Vector3 add() 方法测试
 */
TEST(Vector3, Add) {
    EXPECT_EQ(Vector3(1, 1, 1) + Vector3(2, 2, 2), Vector3(3, 3, 3));
    EXPECT_EQ(Vector3(1.5, 1, 1) + Vector3(2.5, 2, 2), Vector3(4, 3, 3));
    EXPECT_EQ(Vector3(1, 2, 1) + Vector3(2, 2, 2), Vector3(3, 4, 3));
}

/**
 * Vector3 sub() 方法测试
 */
TEST(Vector3, Sub) {
    EXPECT_EQ(Vector3(5, 3, 3) - Vector3(1.5, 2, 2), Vector3(3.5, 1, 1));
    EXPECT_EQ(Vector3(5, 3.5, 3) - Vector3(1.5, 2, 2), Vector3(3.5, 1.5, 1));
    EXPECT_EQ(Vector3(5, 3, 3.5) - Vector3(1.5, 2, 2), Vector3(3.5, 1, 1.5));
    EXPECT_EQ(Vector3(5, 4, 3) - Vector3(1.5, 2.5, 2), Vector3(3.5, 1.5, 1));
}


/**
 * Vector3 length() 方法测试
 */
TEST(Vector3, Length) {
    EXPECT_LE(fabs(Vector3(1, 1, 1).length() - sqrt(3)), 0.001);
    EXPECT_LE(fabs(Vector3(2, 2, 2).length() - sqrt(12)), 0.001);
    EXPECT_LE(fabs(Vector3(1, 5, 6).length() - sqrt(pow(1, 2) + pow(5, 2) + pow(6, 2))), 0.001);
    EXPECT_LE(fabs(Vector3(1, 1.6, 1.7).length() - sqrt(pow(1, 2) + pow(1.6, 2) + pow(1.7, 2))), 0.001);
    EXPECT_LE(fabs(Vector3(1, 12.9, 1.1).length() - sqrt(pow(1, 2) + pow(12.9, 2) + pow(1.1, 2))), 0.001);
}

/**
 * Vector3 negate() 方法测试
 */
TEST(Vector3, Negate) {
    EXPECT_EQ(Vector3(1, 1, 1).negate(), Vector3(-1, -1, -1));
    EXPECT_EQ(Vector3(1, -1, 1).negate(), Vector3(-1, 1, -1));
    EXPECT_EQ(Vector3(0, 1, 1).negate(), Vector3(0, -1, -1));
}

/**
 * Vector3 normalize() 方法测试
 */
TEST(Vector3, Normalize) {
    EXPECT_LE(fabs(Vector3(10.5, 1, 1).normalize().length() - 1), 0.001);
    EXPECT_LE(fabs(Vector3(110, 11.2, 12.1).normalize().length() - 1), 0.001);
    EXPECT_LE(fabs(Vector3(10, 13, 21).normalize().length() - 1), 0.001);
    EXPECT_LE(fabs(Vector3(11.2, 111.11, 123.1).normalize().length() - 1), 0.001);
    EXPECT_LE(fabs(Vector3(10, 1.1, 109).normalize().length() - 1), 0.001);
}

/**
 * Vector3 scale() 方法测试
 */
TEST(Vector3, Scale) {
    EXPECT_EQ(Vector3(2, 2, 2).scale(0.5, 1, 0.5), Vector3(1, 2, 1));
    EXPECT_EQ(Vector3(2, 2, 2).scale(0.5, 0.5, 0.5), Vector3(1, 1, 1));
}

/*
 * Vector3 transform() 方法测试
 */
TEST(Vector3, Transform) {
    Matrix transMat = Matrix::identity();
    EXPECT_EQ(Vector3::transform(Vector3(1, 2, 3), transMat), Vector3(1, 2, 3));
    EXPECT_EQ(Vector3::transform(Vector3(1, 2, 3), transMat), Vector3(1, 2, 3));
}

/*
 * Vector3 transformCoordinates() 方法测试
 */
TEST(Vector3, TransformCoordinates) {
    Matrix transMat = Matrix::identity();
    EXPECT_EQ(Vector3::transformCoordinates(Vector3(1, 2, 3), transMat), Vector3(1, 2, 3));
    EXPECT_EQ(Vector3::transformCoordinates(Vector3(1, 2, 3), transMat), Vector3(1, 2, 3));
}

/*
 * Vector3 dot() 方法测试
 */
TEST(Vector3, Dot) {
    EXPECT_EQ(Vector3::dot(Vector3(1, 1, 1), Vector3(2, 2, 2)), 6);
    EXPECT_EQ(Vector3::dot(Vector3(1, 2, 3), Vector3(3, 2, 3)), 16);
}

/*
 * Vector3 cross() 方法测试
 */
TEST(Vector3, Cross) {
    EXPECT_EQ(Vector3::cross(Vector3(1, 1, 1), Vector3(2, 2, 2)), Vector3(0, 0, 0));
    EXPECT_EQ(Vector3::cross(Vector3(1, 2, 3), Vector3(2, 2, 2)), Vector3(-2, 4, -2));
    EXPECT_EQ(Vector3::cross(Vector3(1, 0, 0), Vector3(0, 0, 1)), Vector3(0, -1, 0));
}