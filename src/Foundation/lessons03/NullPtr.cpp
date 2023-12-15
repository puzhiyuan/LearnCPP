/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-14 20:40:20
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-14 21:17:57
 * @FilePath: \LearnCPP\src\Foundation\lessons03\NullPtr.cpp
 * @Description: 空指针判断
 */
#include <iostream>
void Print(int* ptr);
int main(int argc, char const *argv[])
{
    int* num = nullptr;
    Print(num);
    int* val = new int(20);
    Print(val);
    delete val;
    return 0;
}


void Print(int* ptr){
    // 判断指针是否为空
    if (ptr == nullptr){
        return;
    }
    std::cout << "num:" << *ptr << std::endl;
}