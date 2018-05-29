/*
 * File   : matrix_test
 * Author : KsGin 
 * Date   : 2018/5/23
 */

#include "../sources/vector.hpp"
#include "../sources/matrix.hpp"
#include <gtest.h>

using namespace Math;

/*
 * Matrix Add() 方法测试
 */
TEST(Matrix, Add) {
    EXPECT_EQ(Matrix(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1) +
              Matrix(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
              Matrix(2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2));
    EXPECT_EQ(Matrix(1, 1, 1, 5, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1.5, 1, 1) +
              Matrix(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
              Matrix(2, 2, 2, 6, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2.5, 2, 2));
}

/*
 * Matrix Sub() 方法测试
 */
TEST(Matrix, Sub) {
    EXPECT_EQ(Matrix(2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2) -
              Matrix(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
              Matrix(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1));
    EXPECT_EQ(Matrix(2, 2, 2, 6, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2.5, 2, 2) -
              Matrix(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1),
              Matrix(1, 1, 1, 5, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1.5, 1, 1));
}

/*
 * Matrix multiply() 方法测试
 */
TEST(Matrix, multiply) {
    EXPECT_EQ(
            Matrix(1, -5, 3, 0, 0, -2, 6, 0, 7, 2, -4, 0, 0, 0, 0, 0).multiply(
                    Matrix(-8, 6, 1, 0, 7, 0, -3, 0, 2, 4, 5, 0, 0, 0, 0, 0)
            ),
            Matrix(-37, 18, 31, 0, -2, 24, 36, 0, -50, 26, -19, 0, 0, 0, 0, 0)
    );
}

/*
 * Matrix Zero() 方法测试
 */
TEST(Matrix, Zero) {
    Matrix zeroMat = Matrix::zero();
    for (int i = 0; i < 16; ++i) {
        EXPECT_EQ(zeroMat._m[i], 0);
    }
}

/*
 * Matrix Identity() 方法测试
 */
TEST(Matrix, Identity) {
    Matrix identityMatrix = Matrix::identity();

    EXPECT_EQ(identityMatrix._11, 1);
    EXPECT_EQ(identityMatrix._22, 1);
    EXPECT_EQ(identityMatrix._33, 1);
    EXPECT_EQ(identityMatrix._44, 1);

    float sum = 0;
    for (int i = 0; i < 16; ++i) {
        sum += identityMatrix._m[i];
    }

    EXPECT_EQ(sum, 4);
}

/*
 * Matrix scale() 方法测试
 */
TEST(Matrix, Scale) {
    Matrix scaleMat = Matrix::scale(5, 4, 3);
    EXPECT_EQ(scaleMat._11, 5);
    EXPECT_EQ(scaleMat._22, 4);
    EXPECT_EQ(scaleMat._33, 3);

    float sum = 0;
    for (int i = 0; i < 16; ++i) {
        sum += scaleMat._m[i];
    }

    EXPECT_EQ(sum, 13);
}

/*
 * Matrix translate() 方法测试
 */
TEST(Matrix, Translate) {
    Matrix translateMat = Matrix::translate(3, 2, 2);
    EXPECT_EQ(translateMat._41, 3);
    EXPECT_EQ(translateMat._42, 2);
    EXPECT_EQ(translateMat._43, 2);

    float sum = 0;
    for (int i = 0; i < 16; ++i) {
        sum += translateMat._m[i];
    }

    EXPECT_EQ(sum, 11);
}

/*
 * Matrix roration() 方法测试
 */
TEST(Matrix, Rotation) {
    float angle = 30;
    Matrix identityMat = Matrix::identity();
    EXPECT_EQ(identityMat.multiply(Matrix::rotationX(angle)).multiply(Matrix::rotationX(-angle)), identityMat);
    EXPECT_EQ(identityMat.multiply(Matrix::rotationY(angle)).multiply(Matrix::rotationY(-angle)), identityMat);
    EXPECT_EQ(identityMat.multiply(Matrix::rotationZ(angle)).multiply(Matrix::rotationZ(-angle)), identityMat);
}

/*
 * Matrix transpose() 方法测试
 */
TEST(Matrix, Transpose) {
    Matrix translateMat = Matrix::translate(1, 14, 13);
    translateMat = translateMat.multiply(Matrix::rotationX(16)).multiply(Matrix::rotationY(15));
    EXPECT_EQ(Matrix::transpose(Matrix::transpose(translateMat)), translateMat);
}

/*
 * Matrix lookAtLH() 方法测试
 */
TEST(Matrix, LookAtLH) {
    Vector3 eye = Vector3(0, 0, 5);
    Vector3 target = Vector3(0, 0, 0);
    Vector3 up = Vector3(0, 1, 0);
    Matrix viewMat = Matrix::lookAtLH(eye, target, up);

    EXPECT_EQ(viewMat._11, -1);
    EXPECT_EQ(viewMat._22, 1);
    EXPECT_EQ(viewMat._33, -1);
    EXPECT_EQ(viewMat._43, -5);
    EXPECT_EQ(viewMat._44, 1);
}

/*
 * Matrix perspectiveFovLH() 方法测试
 */
TEST(Matrix, PerspectiveFovLH) {
    float fov = 90;
    float aspect = 4 / 3;
    float near = 0.01;
    float far = 1000;
    Matrix projectionMat = Matrix::perspectiveFovLH(fov, aspect, near, far);

    EXPECT_LE(projectionMat._11 - 1 / (tan(fov * 0.5)) / aspect, 0.0001);
    EXPECT_LE(projectionMat._22 - 1 / (tan(fov * 0.5)), 0.0001);
    EXPECT_LE(projectionMat._33 - -far / (near / far), 0.0001);
    EXPECT_LE(projectionMat._43 - near * far / (near - far), 0.0001);
}

/*
 * transform() 方法测试
 */
TEST(Matrix, Transform) {
    Matrix transMat = Matrix::identity();
    EXPECT_EQ(Matrix::transfrom(Vector2(1, 2), transMat), Vector2(1, 2));
    EXPECT_EQ(Matrix::transfrom(Vector2(3, 2), transMat), Vector2(3, 2));
    EXPECT_EQ(Matrix::transform(Vector3(1, 2, 3), transMat), Vector3(1, 2, 3));
    EXPECT_EQ(Matrix::transform(Vector3(1, 2, 3), transMat), Vector3(1, 2, 3));
}

/*
 * Vector3 transformCoordinates() 方法测试
 */
TEST(Matrix, TransformCoordinates) {
    Matrix transMat = Matrix::identity();
    EXPECT_EQ(Matrix::transformCoordinates(Vector3(1, 2, 3), transMat), Vector3(1, 2, 3));
    EXPECT_EQ(Matrix::transformCoordinates(Vector3(1, 2, 3), transMat), Vector3(1, 2, 3));
}