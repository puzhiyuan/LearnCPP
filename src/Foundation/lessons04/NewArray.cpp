/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-19 18:09:34
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-19 18:25:30
 * @FilePath: \LearnCPP\src\Foundation\lessons04\NewArray.cpp
 * @Description: 动态分配数组空间
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    // 编译错误
    // int* arr = new int[10000000000];
    
    // 内存不足的情况下，使用（std::nothrow）调用new会返回nullptr,不会导致程序终止
    // int* arr = new (std::nothrow) int[10000000000];
    int* arr = new (std::nothrow) int[100];
    if (arr == nullptr)
        std::cout << "arr is nullptr..." << std::endl;
    else{
        std::cout << "arr: " << arr << std::endl;
        delete[] arr;
    }
    return 0;
}
