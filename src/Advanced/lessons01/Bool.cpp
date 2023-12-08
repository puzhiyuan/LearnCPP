/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-11-28 21:54:22
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-11-28 22:09:34
 * @FilePath: \LearnCPP\src\lessons01\Bool.cpp
 * @Description: bool类型
 */
#include <iostream>
using namespace std;

// 自己将int类型定义成BOOL，与C++自带的bool类型对比
typedef int BOOL;

int main(int argc, char const *argv[])
{
    BOOL value0 = (5 < 3);
    bool value1 = (3 < 5);
    cout << "loc: " << &value0 << "\tsize: " << sizeof(value0) << "\tvalue: " << value0 << endl;
    cout << "loc: " << &value1 << "\tsize: " << sizeof(value1) << "\tvalue: " << value1 << endl;
    return 0;
}
