/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-21 17:59:59
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-21 20:23:13
 * @FilePath: \LearnCPP\src\Foundation\lessons05\Struct.cpp
 * @Description: 结构体
 */
#include <iostream>

struct Person
{
    char name[20];
    int age;
    float weight;
};

void PrintStruct(const Person* person);
void PrintStruct(Person person);

int main(int argc, char const *argv[])
{
    Person Zhangsan={"张三", 23, 60.5};
    PrintStruct(&Zhangsan); // 传入结构体指针
    PrintStruct(Zhangsan); // 传入结构体

    Person Lisi;
    // 未初始化的结构体变量存在垃圾值
    PrintStruct(Lisi);

    // 初始化
    Person Wangwu{};
    Person Zhaoliu({});
    PrintStruct(Wangwu);
    PrintStruct(Zhaoliu);


    // Zhaoliu.name = "赵六";
    memcpy(Zhaoliu.name, "赵六", sizeof(Zhaoliu.name));
    Zhaoliu.age = 34;
    Zhaoliu.weight = 77.7;
    PrintStruct(Zhaoliu);

    Person* Xiaoming = new Person();
    PrintStruct(Xiaoming);
    Xiaoming->age = 32;
    Xiaoming->weight = 66.66;
    memcpy(Xiaoming->name, "小明", sizeof(Xiaoming->name));
    PrintStruct(Xiaoming);

    delete Xiaoming;
    return 0;
}


// 结构体指针作为参数
void PrintStruct(const Person* person){
    std::cout << "PrintStruct(Person* person)" << std::endl;
    // const修饰，无法修改，编译报错
    // person->age = 99;
    std::cout << "name: " << person->name << "\tage: " << person->age << "\tweight: " << person->weight << std::endl;
}

// 结构体变量作为参数
void PrintStruct(Person person){
    std::cout << "PrintStruct(Person person)" << std::endl;
    std::cout << "name: " << person.name << "\tage: " << person.age << "\tweight: " << person.weight << std::endl;
}