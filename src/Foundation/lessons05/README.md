<!--
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-21 17:54:38
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-22 21:38:55
 * @FilePath: \LearnCPP\src\Foundation\lessons05\README.md
 * @Description: 
-->
# 结构体
## 1 结构体
结构体（Struct）是一种在C++中用于组织和存储多个相关数据项的数据结构。以下是关于结构体的一些基本知识点：

### 1.1 定义结构体
```cpp
struct Person
{
    char name[20];
    int age;
    float weight;
};
```
这里定义了一个名为 `Person` 的结构体，包含了姓名（char数组）、年龄（整数）、体重（浮点数）三个成员变量。

### 1.2 结构体变量的声明和初始化
```cpp
Person individual; // 声明一个Person类型的变量
``` 
可以通过以下方式初始化结构体变量：
```cpp
Person individual = {"John", 25, 68.5};
```
或者逐个成员初始化：
```cpp
Person individual;
strcpy(individual.name, "John");
individual.age = 25;
individual.weight = 68.5;
```

### 1.3 访问结构体成员
使用成员运算符 `.` 来访问结构体的成员变量：
```cpp
std::cout << "Name: " << individual.name << "\n";
std::cout << "Age: " << individual.age << "\n";
std::cout << "Weight: " << individual.weight << "\n";
```

### 1.4 结构体作为函数参数
可以将结构体作为参数传递给函数，以便在函数中操作结构体数据：
```cpp
void PrintStruct(Person* person)
{
    std::cout << "Name: " << person->name << "\n";
    std::cout << "Age: " << person->age << "\n";
    std::cout << "Weight: " << person->weight << "\n";
}
```
或者传递结构体引用：
```cpp
void PrintStruct(const Person& person)
{
    std::cout << "Name: " << person.name << "\n";
    std::cout << "Age: " << person.age << "\n";
    std::cout << "Weight: " << person.weight << "\n";
}
```

### 1.5 结构体数组：
可以创建结构体数组来存储多个相似的结构体变量：
```cpp
Person people[3] = {{"John", 25, 68.5}, {"Alice", 30, 55.0}, {"Bob", 22, 75.2}};
```
可以通过循环遍历数组中的结构体元素。

### 1.6 嵌套结构体
嵌套结构体是 C++ 中一种结构化数据的组织方式，其中一个结构体可以作为另一个结构体的成员。
- 定义嵌套结构体
    ```cpp
    // 定义Address结构体
    struct Address
    {
        char street[50];
        char city[30];
        char state[20];
        int zipCode;
    };

    // 定义Person结构体，包含了Address结构体作为其中一个成员
    struct Person
    {
        char name[50];
        int age;
        Address address; // 结构体嵌套
    };
    ```

- 初始化嵌套结构体
  - 嵌套结构体的初始化可以通过嵌套的方式进行，也可以使用逐个成员初始化的方式：
    ```cpp
    Person john = {"John", 30, {"123 Main St", "Cityville", "CA", 12345}};
    ```
    ```cpp
    Person john;
    strcpy(john.name, "John");
    john.age = 30;
    john.address = {"123 Main St", "Cityville", "CA", 12345};
    ```

- 嵌套结构体作为函数参数
  - 可以将包含嵌套结构体的结构体作为函数参数传递，或者传递嵌套结构体的引用：
    ```cpp
    void PrintPerson(const Person& person)
    {
        std::cout << "Name: " << person.name << "\n";
        std::cout << "Age: " << person.age << "\n";
        std::cout << "Address: " << person.address.street << "\n";
        std::cout << "address.city: " << person.address.city << "\n";
        std::cout << "address.state: " << person.address.state << "\n";
        std::cout << "address.zipCode: " << person.address.zipCode << "\n";
    }
    ```