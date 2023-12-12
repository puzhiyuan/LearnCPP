/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-12 21:45:11
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-12 21:57:12
 * @FilePath: \LearnCPP\src\Foundation\lessons03\DynamicallyAllocateMemory.cpp
 * @Description: 动态分配内存
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    // 动态分配一个整数大小的内存，p 指向这块内存，并用括号初始化为零。
    int *p = new int();
    // 动态分配一个整数大小的内存，q 指向这块内存，未初始化。
    int *q = new int;
    // 动态分配一个整数大小的内存，r 指向这块内存，并初始化为 10。
    int *r = new int(10);

    std::cout << "*p->" << *p << std::endl;
    std::cout << "*q->" << *q << std::endl;
    std::cout << "*r->" << *r << std::endl << std::endl;

    *p = 12;
    *q = 18;
    *r = 20;
    std::cout << "*p->" << *p << std::endl;
    std::cout << "*q->" << *q << std::endl;
    std::cout << "*r->" << *r << std::endl;
    
    // 下一行写法不可行
    // delete p, q, r;
    
    delete p;
    delete q;
    delete r;

    return 0;
}
