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
            m = new float[16];
            if (m) {
                m[0] = m1;
                m[1] = m2;
                m[2] = m3;
                m[3] = m4;
                m[4] = m5;
                m[5] = m6;
                m[6] = m7;
                m[7] = m8;
                m[8] = m9;
                m[9] = m10;
                m[10] = m11;
                m[11] = m12;
                m[12] = m13;
                m[13] = m14;
                m[14] = m15;
                m[15] = m16;
            }
        }

        /*
         * 引用构造函数
         */
        Matrix(const Matrix &mat) {
            m = new float[16];
            if (m && mat.m)
                for (int i = 0; i < 16; ++i)
                    m[i] = mat.m[i];
        }

        /*
         * 析构函数
         */
        ~Matrix() {
            delete[] m;
        }

        /*
         * 数据指针
         */
        float *m;

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
                tm[i] = m[i] + mat.m[i];
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
                tm[i] = m[i] - mat.m[i];
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
