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
        float x , y;

        /**
         * empty construct
         */
        Vector2(){}

        /**
         * value copy construct
         * @param _x x value
         * @param _y y value
         */
        Vector2(float _x , float _y){
            x = _x;
            y = _y;
        }

        /**
         * object copy construct
         * @param v2 vector object reference
         */
        Vector2(Vector2& v2){
            x = v2.x;
            y = v2.y;
        }

        /**
         * add function
         * @param v2 vector object reference
         * @return result
         */
        Vector2& operator+(const Vector2& v2){
            x += v2.x;
            y += v2.y;
            return *this;
        }

        /**
         * sub function
         * @param v2 vector object reference
         * @return result
         */
        Vector2& operator-(const Vector2& v2){
            x -= v2.x;
            y -= v2.y;
            return *this;
        }

        /**
         * equal function
         * @param v2 vector object reference
         * @return result (ture or flase)
         */
        bool operator==(const Vector2& v2) const {
            return x == v2.x && y == v2.y;
        }

        /**
         * negate function
         * @return reslut
         */
        Vector2& negate(){
            x = -x;
            y = -y;
            return *this;
        }

        /**
         * scale function
         * @param scale scale value
         * @return result
         */
        Vector2& scale(float scale){
            x *= scale;
            y *= scale;
            return *this;
        }

        /**
         * length function
         * @return result
         */
        float length(){
            return sqrt(x * x + y * y);
        }

        /**
         * normalize function
         * @return result
         */
        Vector2& normalize(){
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

    };

    /**
     * Class Vector4
     */
    class Vector4 {

    };
}

#endif //MATHLIB_VECTOR_HPP
