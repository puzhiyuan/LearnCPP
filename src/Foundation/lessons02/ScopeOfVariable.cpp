/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-10 14:48:55
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-10 15:20:54
 * @FilePath: \LearnCPP\src\Foundation\lessons02\ScopeOfVariable.cpp
 * @Description: 变量的作用域
 */
#include <iostream>

/*
    1.全局变量和静态局部变量自动初始化为0。
    2.局部变量不会自动初始化，其值是不确定的，程序中应该有初始化局部变量的代码，否则编译可能会报错（不同的编译器不一样）。
    3.局部变量和全局变量的名称可以相同，在某函数或语句块内部，如果局部变量名与全局变量名相同，就会屏蔽全局变量而使用局部变量，如果想使用全局变量，可以在变量名前加两个冒号(::)。
*/


// 全局变量，具有全局作用域
int globalVar = 10;
void func1();

int main() {
    // 局部变量，具有局部作用域，只在 main 函数内可见
    int localVarMain = 20;

    std::cout << "Inside main function:" << std::endl;
    std::cout << "globalVar: " << globalVar << std::endl;
    std::cout << "localVarMain: " << localVarMain << std::endl;

    // 块作用域
    {
        // 局部变量，具有块作用域，只在当前块内可见
        int localVarBlock = 30;

        std::cout << "\nInside a block:" << std::endl;
        std::cout << "globalVar: " << globalVar << std::endl;
        std::cout << "localVarMain: " << localVarMain << std::endl;
        std::cout << "localVarBlock: " << localVarBlock << std::endl;
    }

    // localVarBlock 在这里不可见，因为它超出了其作用域
    // std::cout << "localVarBlock: " << localVarBlock << std::endl;

    std::cout << "\nInside main function after redeclaration:" << std::endl;
    std::cout << "globalVar: " << globalVar << std::endl;
    std::cout << "localVarMain (outer): " << localVarMain << std::endl;


    func1();
    func1();


    return 0;
}


void func1(){
    int a = 10;
    // 静态局部变量，生命周期为整个程序运行期间，只初始化一次
    static int b = 10;

    std::cout << "a: " << a++ << std::endl;
    std::cout << "b: " << b++ << std::endl;
}