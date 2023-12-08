/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-08 15:16:00
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-08 22:11:34
 * @FilePath: \LearnCPP\src\Foundation\lessons01\C++11init.cpp
 * @Description: 花括号初始化（Braced Initialization）在 C++11 引入，并在后续标准中得到加强。这种初始化方式有一些优势，使得它成为推荐的初始化方式：

                一致性： 花括号初始化对于各种类型（基本类型、结构体、数组等）都是一致的，这提供了一种统一的初始化语法，不同于其他初始化方式的不一致性。

                防止窄化（Narrowing）： 花括号初始化在设计上避免了窄化问题，即不允许发生精度损失或溢出的初始化。这有助于提高代码的安全性。

                int x = 1000.5;      // 合法但存在窄化
                int y{1000.5};       // 编译错误，避免了窄化问题
                初始化列表支持： 花括号初始化支持初始化列表，使得初始化更为灵活。这对于容器、数组等数据结构的初始化非常方便。

                std::vector<int> values = {1, 2, 3};   // 使用初始化列表初始化容器
                int array[] = {1, 2, 3};               // 使用初始化列表初始化数组
                对于聚合类型的统一支持： 花括号初始化在 C++11 中引入了对聚合类型（包括数组、结构体等）的统一初始化支持。这进一步提高了初始化的一致性。

                struct Point {
                    int x;
                    int y;
                };

                Point p1 = {1, 2};  // 传统的聚合类型初始化
                Point p2{1, 2};     // 统一的花括号初始化
                花括号初始化提供了更一致、更安全、更灵活的初始化语法，而且在 C++ 标准的发展中得到了持续加强。因此，推荐在现代 C++ 中使用花括号初始化。
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