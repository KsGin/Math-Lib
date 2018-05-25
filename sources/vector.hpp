/*
 * File   : vector
 * Author : KsGin 
 * Date   : 2018/5/23
 */

#ifndef MATHLIB_VECTOR_HPP
#define MATHLIB_VECTOR_HPP

#include <cmath>

namespace Math {

    /**
     *  Class Vector2
     */
    class Vector2 {

    public:
        /**
         * x , y value
         */
        float x, y;

        /**
         * empty constructor
         */
        Vector2() {}

        /**
         * value copy constructor
         * @param _x x value
         * @param _y y value
         */
        Vector2(const float _x, const float _y) {
            x = _x;
            y = _y;
        }

        /**
         * object copy constructor
         * @param v2 vector object reference
         */
        Vector2(const Vector2 &v2) {
            x = v2.x;
            y = v2.y;
        }

        /**
         * copy constructor
         * @param v2 object
         * @return
         */
        Vector2 &operator=(const Vector2 &v2) {
            x = v2.x;
            y = v2.y;
            return *this;
        }

        /**
         * add function
         * @param v2 vector object reference
         * @return result
         */
        Vector2 operator+(const Vector2 &v2) const {
            return Vector2(x + v2.x, y + v2.y);
        }

        /**
         * sub function
         * @param v2 vector object reference
         * @return result
         */
        Vector2 operator-(const Vector2 &v2) const {
            return Vector2(x - v2.x, y - v2.y);
        }

        /**
         * equal function
         * @param v2 vector object reference
         * @return result (ture or flase)
         */
        bool operator==(const Vector2 &v2) const {
            return x == v2.x && y == v2.y;
        }

        /**
         * negate function
         * @return reslut
         */
        Vector2 &negate() {
            x = -x;
            y = -y;
            return *this;
        }

        /**
         * scale function
         * @param scale scale value
         * @return result
         */
        Vector2 &scale(float scaleX, float scaleY) {
            x *= scaleX;
            y *= scaleY;
            return *this;
        }

        /**
         * length function
         * @return result
         */
        float length() {
            return sqrt(x * x + y * y);
        }

        /**
         * normalize function
         * @return result
         */
        Vector2 &normalize() {
            auto length = this->length();
            if (length == 0) return *this;
            x /= length;
            y /= length;
            return *this;
        }

    };

    /**
     * Class Vector3
     */
    class Vector3 {
    public:
        /**
         * x , y , z value define
         */
        float x, y, z;

        /**
         * empty construct
         */
        Vector3() {}

        /**
         * value copy construct
         * @param _x x value
         * @param _y y value
         * @param _z z value
         */
        Vector3(float _x, float _y, float _z) {
            x = _x;
            y = _y;
            z = _z;
        }

        /**
         * object copy construct
         * @param v3 object reference
         */
        Vector3(const Vector3 &v3) {
            x = v3.x;
            y = v3.y;
            z = v3.z;
        }

        /**
         * copy constructor
         * @param v3 object reference
         * @return result
         */
        Vector3 &operator=(const Vector3 &v3) {
            x = v3.x;
            y = v3.y;
            z = v3.z;
            return *this;
        }

        /**
         * add function
         * @param v3 object reference
         * @return result
         */
        Vector3 operator+(const Vector3 &v3) {
            return Vector3(x + v3.x, y + v3.y, z + v3.z);
        }

        /**
         * sub function
         * @param v3 object reference
         * @return result
         */
        Vector3 operator-(const Vector3 &v3) {
            return Vector3(x - v3.x, y - v3.y, z - v3.z);
        }

        /**
         * equal function
         * @param v3 object reference
         * @return
         */
        bool operator==(const Vector3 &v3) const {
            return x == v3.x && y == v3.y && z == v3.z;
        }

        /**
         * negate function
         * @return reslut
         */
        Vector3 &negate() {
            x = -x;
            y = -y;
            z = -z;
            return *this;
        }

        /**
         * scale function
         * @param scale scale value
         * @return result
         */
        Vector3 &scale(float scaleX, float scaleY, float scaleZ) {
            x *= scaleX;
            y *= scaleY;
            z *= scaleZ;
            return *this;
        }

        /**
         * length function
         * @return result
         */
        float length() {
            return sqrt(x * x + y * y + z * z);
        }

        /**
         * normalize function
         * @return result
         */
        Vector3 &normalize() {
            auto length = this->length();
            if (length == 0) return *this;
            x /= length;
            y /= length;
            z /= length;
            return *this;
        }
    };

    /**
     * Class Vector4
     */
    class Vector4 {

    };
}

#endif //MATHLIB_VECTOR_HPP
