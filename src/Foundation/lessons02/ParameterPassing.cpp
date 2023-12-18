/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-10 15:25:15
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-18 19:11:13
 * @FilePath: \LearnCPP\src\Foundation\lessons02\ParameterPassing.cpp
 * @Description: 参数传递
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