#include <iostream>
void Add(int a, int b);
void Sub(int a, int b);

int main(int argc, char const *argv[])
{
    // 定义函数指针
    void (*ptr)(int, int);
    int a = 5, b =3;
    std::cout << "a = " << a << "\tb = " << b << std::endl;

    // 将函数指针指向Add函数
    ptr = Add;
    ptr(a, b);

    // 将函数指针指向Sub函数
    ptr = Sub;
    ptr(a, b);
    return 0;
}

void Add(int a, int b){
    std::cout << "Add: a + b = " << a + b << std::endl;
}

void Sub(int a, int b){
    std::cout << "Sub: a - b = " << a - b << std::endl;
}