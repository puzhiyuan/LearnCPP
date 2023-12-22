/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-22 22:12:07
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-22 22:16:06
 * @FilePath: \LearnCPP\src\Foundation\lessons05\Union.cpp
 * @Description: 共同体
 */
#include <iostream>


union udata
{
    int num1;
    double num2;
    char string[21];
};


int main(int argc, char const *argv[])
{
    // 共同体所占空间大小为最大的成员变量类型的大小
    // 由于存在空间对齐，所以这里的结果是24
    std::cout << "sizof(udata): " << sizeof(udata) << std::endl;
    return 0;
}
