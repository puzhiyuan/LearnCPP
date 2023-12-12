/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-12 16:25:59
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-12 19:00:45
 * @FilePath: \LearnCPP\src\Foundation\lessons03\Pointer.cpp
 * @Description: 指针相关内容
 */
#include <iostream>

int main(int argc, char const *argv[])
{
    char a = 'b';
    int b = 123;
    std::string c = "hello";
    double d = 12.12;

    char *pa = &a;
    int *pb = &b;
    std::string *pc = &c;
    double *pd = &d;

    std::cout << "a->addr:" << (void *)&a << std::endl;
    std::cout << "b->addr:" << &b << std::endl;
    std::cout << "c->addr:" << &c << std::endl;
    std::cout << "d->addr:" << &d << std::endl << std::endl;

    std::cout << "a->addr:" << (void *)pa << std::endl;      
    std::cout << "b->addr:" << pb << std::endl;  
    std::cout << "c->addr:" << pc << std::endl;  
    std::cout << "d->addr:" << pd << std::endl;      

    return 0;
}
