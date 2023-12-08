/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-08 21:54:34
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-08 22:04:43
 * @FilePath: \LearnCPP\MultiplicationTable.cpp
 * @Description: 嵌套循环打印乘法表
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << j << "*" << i << "=" << i*j << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}
