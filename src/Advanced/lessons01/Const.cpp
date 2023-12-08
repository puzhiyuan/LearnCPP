/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-11-28 22:09:46
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-06 19:30:27
 * @FilePath: \LearnCPP\src\lessons01\Const.cpp
 * @Description: 
 */
#include <iostream>

// 宏定义在编译的时候不进行类型检查
// #define PI 3.14

const float PI = 3.14f;

int main(int argc, char const *argv[])
{
    float r = 1;
    float size = PI * r *r;
    printf("size: %f", size);
    return 0;
}
