/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-22 20:55:39
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-22 21:37:38
 * @FilePath: \LearnCPP\src\Foundation\lessons05\StructAndPointer.cpp
 * @Description: 结构体和指针
 */
#include <iostream>
#include <string.h>
struct Person{
    char name[21];
    int age;
    int* date;
};

int main(int argc, char const *argv[])
{
    Person john;
    
    memset(&john, 0, sizeof(Person));

    john.age = 23;
    strcpy(john.name, "john");
    john.date = new int[100]{123,1232,3,434,3,4,5,6556,3,34,23};
    std::cout << "name: " << john.name << "\tage: " << john.age << "\tdata: " << john.date << "\t*data: " << *john.date << std::endl;
    
    // 这里清空结构体不能用下一行代码，会将结构体里面的指针清零，而不是指针所指的内容清零
    // memset(&john, 0, sizeof(Person));

    // 需要用以下语句清零结构体
    memset(john.name, 0, sizeof(john.name));
    john.age = 0;
    memset(john.date, 0, 100*sizeof(int));

    std::cout << "name: " << john.name << "\tage: " << john.age << "\tdata: " << john.date << "\t*data: " << *john.date << std::endl;

    delete[] john.date;
    return 0;
}
