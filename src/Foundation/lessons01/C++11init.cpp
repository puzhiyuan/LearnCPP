/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-08 15:16:00
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-17 21:51:39
 * @FilePath: \LearnCPP\src\Foundation\lessons01\C++11init.cpp
 * @Description: c11标准的初始化
 */

#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

int main() {
    // 传统初始化(C++03)
    int a = 10;
    int b(10); 

    //花括号初始化(C++11)
    int c = {10};
    int d{10};

    // 初始化列表
    std::vector<int> values = {1, 2, 3};
    int array[] = {4, 5, 6};

    // 对象的花括号初始化
    Point p1 = {1, 2};  // 传统的聚合类型初始化
    Point p2{3, 4};     // 统一的花括号初始化

    // 输出每个变量的值
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    for (const auto& value : values) {
        std::cout << "Vector element: " << value << std::endl;
    }

    for (const auto& element : array) {
        std::cout << "Array element: " << element << std::endl;
    }

    std::cout << "Point p1: (" << p1.x << ", " << p1.y << ")" << std::endl;
    std::cout << "Point p2: (" << p2.x << ", " << p2.y << ")" << std::endl;

    return 0;
}