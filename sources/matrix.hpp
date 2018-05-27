/*
 * File   : matrix
 * Author : KsGin 
 * Date   : 2018/5/23
 */

#ifndef MATHLIB_MATRIX_HPP
#define MATHLIB_MATRIX_HPP

namespace Math {
    /**
     * 矩阵类
     */
    class Matrix {

        /*
         * 空构造函数 禁止使用 禁止重写
         */
        Matrix() {}

    public:


        /*
         * 值构造函数
         */
        Matrix(float m1, float m2, float m3, float m4,
               float m5, float m6, float m7, float m8,
               float m9, float m10, float m11, float m12,
               float m13, float m14, float m15, float m16) {
            _m = new float[16];
            if (_m) {
                _m[0] = m1;
                _m[1] = m2;
                _m[2] = m3;
                _m[3] = m4;
                _m[4] = m5;
                _m[5] = m6;
                _m[6] = m7;
                _m[7] = m8;
                _m[8] = m9;
                _m[9] = m10;
                _m[10] = m11;
                _m[11] = m12;
                _m[12] = m13;
                _m[13] = m14;
                _m[14] = m15;
                _m[15] = m16;
            }
        }

        /*
         * 引用构造函数
         */
        Matrix(const Matrix &mat) {
            _m = new float[16];
            if (_m && mat._m)
                for (int i = 0; i < 16; ++i)
                    _m[i] = mat._m[i];
        }

        /*
         * 析构函数
         */
        ~Matrix() {
            delete[] _m;
        }

        /*
         * 数据指针
         */
        float *_m;

        /*
         * 重载 =
         */
        Matrix operator=(const Matrix& mat){
            return Matrix(mat);
        }

        /*
         * 重载 +
         */
        Matrix operator+(const Matrix &mat) {
            float tm[16];
            for (int i = 0; i < 16; ++i) {
                tm[i] = _m[i] + mat._m[i];
            }
            return Matrix(
                    tm[0], tm[1], tm[2], tm[3],
                    tm[4], tm[5], tm[6], tm[7],
                    tm[8], tm[9], tm[10], tm[11],
                    tm[12], tm[13], tm[14], tm[15]
            );
        }

        /*
         * 重载 -
         */
        Matrix operator-(const Matrix &mat) {
            float tm[16];
            for (int i = 0; i < 16; ++i) {
                tm[i] = _m[i] - mat._m[i];
            }
            return Matrix(
                    tm[0], tm[1], tm[2], tm[3],
                    tm[4], tm[5], tm[6], tm[7],
                    tm[8], tm[9], tm[10], tm[11],
                    tm[12], tm[13], tm[14], tm[15]
            );
        }

        /*
         *  获得单位矩阵
         */
        static Matrix identity() {
            return Matrix(
                    1, 0, 0, 0,
                    0, 1, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1);
        }

    };
}

#endif //MATHLIB_MATRIX_HPP
