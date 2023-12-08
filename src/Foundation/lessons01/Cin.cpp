/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-08 14:19:59
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-08 14:52:09
 * @FilePath: \LearnCPP\src\Foundation\lessons01\cin.cpp
 * @Description: learn cin
 */
#include <iostream>
#include <string>

int main() {
    // 获取整数输入
    int integerValue;
    std::cout << "请输入一个整数: ";
    std::cin >> integerValue;
    std::cout << "你输入的整数是: " << integerValue << std::endl;

    // 获取字符串输入
    std::string stringValue;
    std::cout << "请输入一个字符串: ";
    std::cin.ignore();  // 忽略前一个输入中的换行符
    std::getline(std::cin, stringValue);
    std::cout << "你输入的字符串是: " << stringValue << std::endl;

    return 0;
}
