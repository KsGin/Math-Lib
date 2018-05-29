#### 自用 c++ 数学库

描述

&emsp;&emsp;简单的 c++ 向量及矩阵库，包含矩阵运算，向量运算，以及透视投影等特殊矩阵，直接拷贝 `matrix.hpp` 和 `vector.hpp` 文件即可。

API 结构

 + `class vector2` 
 
    + `operator+()` ：+
    + `operator-()` ：-
    + `negate()` ：取负
    + `scale()` ：缩放
    + `length()` ：长度
    + `normalize()` ：归一化（正规化）
    
 + `class vector3` 
     
    + `operator+()` ：+
    + `operator-()` ：-
    + `negate()` ：取负
    + `scale()` ：缩放
    + `length()` ：长度
    + `normalize()` ： 归一化（正规化）
    + `dot()` ：求点积
    + `cross()` ： 求叉积
    
 + `class matrix`
 
    + `operator+()` ：+
    + `operator-()` ：-
    + `operator*()` ：*
    + `multiply()` ： *
    + `identity()` ：生成标准矩阵
    + `zero()` ：生成 0 矩阵
    + `scale()` ：生成缩放矩阵
    + `translate()` ：生成平移矩阵
    + `rotationX()` ：生成绕 x 轴旋转矩阵
    + `rotationY()` ：生成绕 y 轴旋转矩阵
    + `rotationZ()` ：生成绕 z 轴旋转矩阵
    + `transpose()` : 矩阵转置
    + `lookAtLH()` ：生成观察矩阵
    + `perspectiveFovLH()` ：生成透视矩阵
    + `transform()` ：矩阵变换
    + `transformCoordinates()` ：矩阵齐次变换

文件结构

1. `sources`
    
    + `matrix.hpp` : 矩阵类，包含矩阵基本运算以及变换
    + `vector.hpp` : 向量类，包含 Vector2 和 Vector3 两个向量以及其基本运算
    
2. `test`

    + `matrix_test.cpp` : 使用 `google test` 对 `matrix` 类的方法进行测试
    + `vector_test.cpp` : 使用 `google test` 对 `vector2` 和 `vector3` 类进行测试