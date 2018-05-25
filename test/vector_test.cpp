/*
 * File   : vector_test
 * Author : KsGin 
 * Date   : 2018/5/23
 */

#include "../headers/vector.hpp"
#include <gtest.h>

using namespace Math;

/**
 * Vector2 construct() test function
 */
TEST(Vector2 , Construct){
    Vector2 *v1 = new Vector2(1 , 1);
    ASSERT_TRUE(v1 != nullptr);

    Vector2 *v2 = new Vector2(*v1);
    ASSERT_TRUE(v2 != nullptr);

    delete v1;
    delete v2;
}

/**
 * Vector2 add() test function
 */
TEST(Vector2 , Add){
    EXPECT_EQ(Vector2(1 , 1) + Vector2(2 , 2) , Vector2(3 , 3));
    EXPECT_EQ(Vector2(1.5 , 1) + Vector2(2 , 2) , Vector2(3.5 , 3));
    EXPECT_EQ(Vector2(1 , 1.5) + Vector2(2 , 2) , Vector2(3 , 3.5));
    EXPECT_EQ(Vector2(1.5 , 1) + Vector2(2.5 , 2) , Vector2(4 , 3));
}

/**
 * Vector2 sub() test function
 */
TEST(Vector2 , Sub){
    EXPECT_EQ(Vector2(3 , 3) - Vector2(2 , 2) , Vector2(1 , 1));
    EXPECT_EQ(Vector2(3.5 , 3) - Vector2(2 , 2) , Vector2(1.5 , 1));
    EXPECT_EQ(Vector2(3 , 3.5) -Vector2(2 , 2) , Vector2(1 , 1.5));
    EXPECT_EQ(Vector2(4 , 3) - Vector2(2.5 , 2) , Vector2(1.5 , 1));
}

/**
 * Vector2 length() test function
 */
TEST(Vector2 , Length){
    EXPECT_LE(fabs(Vector2(1 , 1).length() - sqrt(2)) , 0.001);
    EXPECT_LE(fabs(Vector2(2 , 2).length() - sqrt(8)), 0.001);
    EXPECT_LE(fabs(Vector2(5 , 6).length() - sqrt(pow(5 , 2) + pow(6 , 2))) , 0.001);
    EXPECT_LE(fabs(Vector2(1.6 , 1.7).length() - sqrt(pow(1.6 , 2) + pow(1.7 , 2))) , 0.001);
    EXPECT_LE(fabs(Vector2(12.9 , 1.1).length() - sqrt(pow(12.9 , 2) + pow(1.1 , 2))) , 0.001);
}

/**
 * Vector2 negate() test function
 */
TEST(Vector2 , Negate){
    EXPECT_EQ(Vector2(1 , 1).negate() , Vector2(-1  , -1));
    EXPECT_EQ(Vector2(1 , -1).negate() , Vector2(-1  , 1));
    EXPECT_EQ(Vector2(0 , 1).negate() , Vector2(0  , -1));
}

/**
 * Vector2 normalize() test function
 */
TEST(Vector2 , Normalize){
    EXPECT_LE(fabs(Vector2(1 , 1).normalize().length() - 1) , 0.001);
    EXPECT_LE(fabs(Vector2(11.2 , 12.1).normalize().length() - 1) , 0.001);
    EXPECT_LE(fabs(Vector2(13 , 21).normalize().length() - 1) , 0.001);
    EXPECT_LE(fabs(Vector2(111.11 , 123.1).normalize().length() - 1) , 0.001);
    EXPECT_LE(fabs(Vector2(1.1 , 109).normalize().length() - 1) , 0.001);
}