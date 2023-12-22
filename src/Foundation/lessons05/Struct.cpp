/*
 * @Author: ��puzhiyuan�� ��puzhiyuan185489643@gmail.com��
 * @Date: 2023-12-21 17:59:59
 * @LastEditors: ��puzhiyuan�� ��puzhiyuan185489643@gmail.com��
 * @LastEditTime: 2023-12-21 20:23:13
 * @FilePath: \LearnCPP\src\Foundation\lessons05\Struct.cpp
 * @Description: �ṹ��
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
    Person Zhangsan={"����", 23, 60.5};
    PrintStruct(&Zhangsan); // ����ṹ��ָ��
    PrintStruct(Zhangsan); // ����ṹ��

    Person Lisi;
    // δ��ʼ���Ľṹ�������������ֵ
    PrintStruct(Lisi);

    // ��ʼ��
    Person Wangwu{};
    Person Zhaoliu({});
    PrintStruct(Wangwu);
    PrintStruct(Zhaoliu);


    // Zhaoliu.name = "����";
    memcpy(Zhaoliu.name, "����", sizeof(Zhaoliu.name));
    Zhaoliu.age = 34;
    Zhaoliu.weight = 77.7;
    PrintStruct(Zhaoliu);

    Person* Xiaoming = new Person();
    PrintStruct(Xiaoming);
    Xiaoming->age = 32;
    Xiaoming->weight = 66.66;
    memcpy(Xiaoming->name, "С��", sizeof(Xiaoming->name));
    PrintStruct(Xiaoming);

    delete Xiaoming;
    return 0;
}


// �ṹ��ָ����Ϊ����
void PrintStruct(const Person* person){
    std::cout << "PrintStruct(Person* person)" << std::endl;
    // const���Σ��޷��޸ģ����뱨��
    // person->age = 99;
    std::cout << "name: " << person->name << "\tage: " << person->age << "\tweight: " << person->weight << std::endl;
}

// �ṹ�������Ϊ����
void PrintStruct(Person person){
    std::cout << "PrintStruct(Person person)" << std::endl;
    std::cout << "name: " << person.name << "\tage: " << person.age << "\tweight: " << person.weight << std::endl;
}