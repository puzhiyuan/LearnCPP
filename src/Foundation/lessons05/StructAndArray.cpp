/*
 * @Author: ��puzhiyuan�� ��puzhiyuan185489643@gmail.com��
 * @Date: 2023-12-21 19:43:11
 * @LastEditors: ��puzhiyuan�� ��puzhiyuan185489643@gmail.com��
 * @LastEditTime: 2023-12-22 19:56:53
 * @FilePath: \LearnCPP\src\Foundation\lessons05\StructAndArray.cpp
 * @Description: �ṹ������� 
 */
#include <iostream>
#include <string.h>

struct Pet{
    char name[21];
    int age;
};

struct Person
{
    char name[21];
    int age;
    float weight;
    struct Pet pet;
};


void PrintStruct(Person person);


int main(int argc, char const *argv[])
{
    Person person[3];
    strcpy(person[0].name, "һ��");
    strcpy(person[1].name, "����");
    strcpy(person[2].name, "����");
    for (size_t i = 0; i < 3; i++)
    {
        person[i].age = 20 + i;
        person[i].weight = 60.2 + i;
    }

    strcpy(person[0].pet.name, "С��");
    strcpy(person[1].pet.name, "���");
    strcpy(person[2].pet.name, "С��");

    person[0].pet.age = 3;
    person[1].pet.age = 4;
    person[2].pet.age = 5;

    for (size_t i = 0; i < 3; i++)
    {
        PrintStruct(person[i]);
    }       
    return 0;
}


void PrintStruct(Person person){
    std::cout << "name: " << person.name << "\tage: " << person.age << "\tweight: " << person.weight << "\tper.name: " << person.pet.name << "\tpet.age: " << person.pet.age << std::endl;
}
