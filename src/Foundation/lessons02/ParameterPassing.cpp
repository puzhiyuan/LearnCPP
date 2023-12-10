/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-10 15:25:15
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-10 16:07:45
 * @FilePath: \LearnCPP\src\Foundation\lessons02\ParameterPassing.cpp
 * @Description: 参数传递
 */


/*
    值传递： 通过复制参数的值传递给函数，对参数的修改不会影响原始变量。
    引用传递： 通过引用传递参数，直接操作原始变量，对参数的修改会影响原始变量。(引用传递实际上是传递变量的别名)
    地址传递： 通过指针传递参数的地址，函数通过指针操作原始变量，对参数的修改会影响原始变量。
*/


#include <iostream>

void func1(std::string name);
void func2(std::string &name);
void func3(std::string *name);

int main(int argc, char const *argv[])
{
    std::string name = "xiaoer";

    std::cout << "main-> " << "name:" << name  << "    address:" << &name <<std::endl;

    func1(name);
    std::cout << "main-> " << "name:" << name  << "    address:" << &name <<std::endl;

    func2(name);
    std::cout << "main-> " << "name:" << name  << "    address:" << &name <<std::endl;

    func3(&name);
    std::cout << "main-> " << "name:" << name  << "    address:" << &name <<std::endl;

    return 0;
}

// 值传递
void func1(std::string name){
    std::cout << "func1-> " << "name:" << name  << "    address:" << &name << std::endl;

    name = "zhangsan";

    std::cout << "func1-> " << "name:" << name  << "    address:" << &name << std::endl;
}

// 引用传递
void func2(std::string &name){
    std::cout << "func2-> " << "name:" << name  << "    address:" << &name << std::endl;

    name = "lisi";

    std::cout << "func2-> " << "name:" << name  << "    address:" << &name << std::endl;
}

// 地址传递
void func3(std::string *name){
    std::cout << "func3-> " << "name:" << *name  << "    address:" << name << std::endl;
    *name = "wangwu";

    std::cout << "func3-> " << "name:" << *name  << "    address:" << name << std::endl;
}