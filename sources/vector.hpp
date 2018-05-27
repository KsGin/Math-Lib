/*
 * File   : vector
 * Author : KsGin 
 * Date   : 2018/5/23
 */

#ifndef MATHLIB_VECTOR_HPP
#define MATHLIB_VECTOR_HPP

#include <cmath>
#include "matrix.hpp"

namespace Math {

    /**
     *  Vector2 向量类
     */
    class Vector2 {

    public:
        /**
         * 数值定义
         */
        float x, y;

        /**
         * 空构造方法
         */
        Vector2() {}

        /**
         * 值构造方法
         */
        Vector2(const float _x, const float _y) {
            x = _x;
            y = _y;
        }

        /**
         * 对象拷贝方法
         */
        Vector2(const Vector2 &v2) {
            x = v2.x;
            y = v2.y;
        }

        /**
         * 重载 =
         */
        Vector2 &operator=(const Vector2 &v2) {
            x = v2.x;
            y = v2.y;
            return *this;
        }

        /**
         * 重载 +
         */
        Vector2 operator+(const Vector2 &v2) const {
            return Vector2(x + v2.x, y + v2.y);
        }

        /**
         * 重载 -
         */
        Vector2 operator-(const Vector2 &v2) const {
            return Vector2(x - v2.x, y - v2.y);
        }

        /**
         * 判断相等
         */
        bool operator==(const Vector2 &v2) const {
            return x == v2.x && y == v2.y;
        }

        /**
         * 取负
         */
        Vector2 &negate() {
            x = -x;
            y = -y;
            return *this;
        }

        /**
         * 缩放
         */
        Vector2 &scale(float scaleX, float scaleY) {
            x *= scaleX;
            y *= scaleY;
            return *this;
        }

        /**
         * 求长度
         */
        float length() {
            return sqrt(x * x + y * y);
        }

        /**
         * 归一化
         */
        Vector2 &normalize() {
            auto length = this->length();
            if (length == 0) return *this;
            x /= length;
            y /= length;
            return *this;
        }

        /**
         * 变换
         */
        static Vector2 transfrom(Vector2& v , Matrix transMat){
            float x = v.x * transMat.m[0] + v.x * transMat.m[4];
            float y = v.y * transMat.m[1] + v.y * transMat.m[5];
            return Vector2(x , y);
        }

    };

    /**
     * Vector3 类
     */
    class Vector3 {
    public:
        float x, y, z;

        /**
         * 空构造方法
         */
        Vector3() {}

        /**
         * 值构造方法
         */
        Vector3(float _x, float _y, float _z) {
            x = _x;
            y = _y;
            z = _z;
        }

        /**
         * 拷贝构造
         */
        Vector3(const Vector3 &v3) {
            x = v3.x;
            y = v3.y;
            z = v3.z;
        }

        /**
         * 重载 =
         */
        Vector3 &operator=(const Vector3 &v3) {
            x = v3.x;
            y = v3.y;
            z = v3.z;
            return *this;
        }

        /**
         * 重载 +
         */
        Vector3 operator+(const Vector3 &v3) {
            return Vector3(x + v3.x, y + v3.y, z + v3.z);
        }

        /**
         * 重载 -
         */
        Vector3 operator-(const Vector3 &v3) {
            return Vector3(x - v3.x, y - v3.y, z - v3.z);
        }

        /**
         * 重载 ==
         */
        bool operator==(const Vector3 &v3) const {
            return x == v3.x && y == v3.y && z == v3.z;
        }

        /**
         * 取负
         */
        Vector3 &negate() {
            x = -x;
            y = -y;
            z = -z;
            return *this;
        }

        /**
         * 缩放
         */
        Vector3 &scale(float scaleX, float scaleY, float scaleZ) {
            x *= scaleX;
            y *= scaleY;
            z *= scaleZ;
            return *this;
        }

        /**
         * 求长度
         */
        float length() {
            return sqrt(x * x + y * y + z * z);
        }

        /**
         * 归一化
         */
        Vector3 &normalize() {
            auto length = this->length();
            if (length == 0) return *this;
            x /= length;
            y /= length;
            z /= length;
            return *this;
        }

        /*
         * 变化
         */
        static Vector3 transform(const Vector3& v3 , const Matrix& transMat){
            
        }

        /*
         * 齐次变换
         */
        static Vector3 transformCoordinates(const Vector3& v3 , const Matrix& transMat){

        }

    };

    /**
     * Vector4 类
     */
    class Vector4 {

    };
}

#endif //MATHLIB_VECTOR_HPP
