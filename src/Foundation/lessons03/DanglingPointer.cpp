/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-14 21:19:42
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-14 21:50:44
 * @FilePath: \LearnCPP\src\Foundation\lessons03\DanglingPointer.cpp
 * @Description: 野指针
 */
#include <iostream>

int* func1(void);

int main(int argc, char const *argv[])
{
    int* ptr = new int(20);
    std::cout << "ptr: " << ptr << "\t*ptr: " << *ptr << std::endl;
    // 释放内存之后，ptr成为野指针
    delete ptr;

    std::cout << "ptr: " << ptr << "\t*ptr: " << *ptr << std::endl;

    std::cout << std::endl;

    
    int* pfunc1 = func1();
    std::cout << "pfunc1: " << pfunc1 << std::endl;
    return 0;
}


// func1中的num内存分配在栈中，函数调用完成之后内存被系统收回，导致返回的num地址无效
int* func1(void){
    int num = 100;
    std::cout << "&num:" << &num << "\tnum:" << num << std::endl;
    return &num;
}
