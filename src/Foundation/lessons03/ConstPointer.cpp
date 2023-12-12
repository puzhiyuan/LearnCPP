/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-12 19:31:06
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-12 19:55:32
 * @FilePath: \LearnCPP\src\Foundation\lessons03\ConstPointer.cpp
 * @Description: const修饰指针
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    int a = 1, b = 2, c = 3;
    int num = 64;

    // 常量指针，不允许通过指针修改变量的值
    const int* pa = &a;
    // 下一行代码无法运行，编译错误
    // *pa = 12;

    // 指针常量，不允许改变指针指向的地址
    int* const pb = &b;
    // 下一行代码无法运行，编译错误
    // pb = &num;

    // 常指针常量，不允许修改指针指向的地址和通过指针修改变量的值
    const int* const pc = &c;
    // 下两行代码无法运行，编译错误
    // *pc = 12;
    // pc = &num;

    std::cout << "a:" << a << "\tpa:" << pa << std::endl;
    std::cout << "b:" << b << "\tpb:" << pb << std::endl;
    std::cout << "c:" << c << "\tpc:" << pc << std::endl;
    
    return 0;
}
