# LESSONS03

## 1. void*
`void*` 是C++中的一种特殊类型的指针，称为“**无类型指针**”（void pointer）。`void*` 的主要特点是它可以指向任何类型的数据，因为它没有指定数据类型。它是一种通用的指针类型，用于在不考虑具体数据类型的情况下处理内存地址。

- **通用性**： `void*` 是一种通用指针，可以指向任何类型的数据，包括基本数据类型（例如整数、浮点数）、自定义数据类型（例如结构体、类）以及函数等。

- **类型安全性**： 尽管 `void*` 具有通用性，但它是一种不安全的指针类型，因为它不提供对指向数据的类型信息。在使用 `void*` 时，编程者需要确保在解引用指针之前进行适当的类型转换，以防止未定义的行为。

- **类型转换**： 在使用 `void*` 指针时，通常需要将其转换为具体的类型，以便进行操作。类型转换使用 reinterpret_cast 或者 C 风格的类型转换。
    ```cpp
    int intValue = 42;
    void* voidPtr = &intValue;

    // 使用 reinterpret_cast 进行类型转换
    int* intPtr = reinterpret_cast<int*>(voidPtr);

    // 访问具体类型的数据
    std::cout << "Value: " << *intPtr << std::endl;
    ```

- **动态内存分配**： `void*` 在动态内存分配和管理中经常用到。例如，malloc 函数返回的是 `void*`，然后可以通过类型转换将其转为特定类型的指针。
    ```cpp
    int* dynamicInt = static_cast<int*>(malloc(sizeof(int)));
    *dynamicInt = 123;

    // 使用动态分配的内存

    free(dynamicInt);  // 释放动态分配的内存
    ```

- **函数参数**： 有时在函数中需要传递任意类型的指针，这时可以使用 void* 参数。
    ```cpp
    void processData(void* data, size_t dataSize) {
    // 处理数据的逻辑
    }
    ```

## 2. const修饰指针
- **常量指针**： 无法通过指针修改指向的值，但可以修改指针本身指向的地址。它的声明方式是指针前加 const，例如 `const int* num`。
- **指针常量**： 可以通过指针修改指向的值，但无法修改指针本身指向的地址。它的声明方式是指针指向的类型前加 const，例如 `int* const num`。
- **常指针常量**： 指既不能通过指针修改指向的值，也不能修改指针本身指向的地址。它的声明方式是指针前后都加 const，例如 `const int* const num`。

## 3. 内存分配
### 3.1静态内存分配
静态内存分配是指在编译时分配内存，由编译器在程序运行之前完成。这种内存分配主要包括：
- **全局变量和静态变量**： 存储在全局区或静态区，程序运行期间一直存在。
    ```cpp
    int globalVar;             // 全局变量
    static int staticVar = 42; // 静态变量
    ```
- **常量数据**： 字符串常量、常量变量等，存储在常量区。
    ```cpp
    const char* str = "Hello"; // 字符串常量
    ```
- **局部静态变量**： 在函数内部声明的静态变量，其生命周期贯穿整个程序运行。
    ```cpp
    void exampleFunction() {
        static int localVar = 10; // 局部静态变量
    }
    ```
### 3.2动态内存分配
动态内存分配是指在程序运行时根据需要分配内存，由程序员手动管理。C++ 提供了 new 操作符用于动态分配内存，以及 delete 操作符用于释放动态分配的内存。
- **动态分配单个变量**
    ```cpp
    int* dynamicVar = new int; // 动态分配一个整数大小的内存
    // 使用 dynamicVar
    delete dynamicVar; // 释放动态分配的内存
    ```
- **动态分配数组**
    ```cpp
    int* dynamicArray = new int[5]; // 动态分配一个包含5个整数的数组
    // 使用 dynamicArray
    delete[] dynamicArray; // 释放动态分配的数组内存
    ```
- **动态分配对象**
    ```cpp
    class MyClass {
        // 类定义
    };

    MyClass* obj = new MyClass; // 动态分配一个 MyClass 对象
    // 使用 obj
    delete obj; // 释放动态分配的对象内存

    ```
动态内存分配的优势在于它允许程序在运行时灵活地分配和释放内存，但需要注意及时释放动态分配的内存，以避免内存泄漏。在现代C++中，更推荐使用智能指针（如 `std::unique_ptr` 和 `std::shared_ptr`）来管理动态内存，以减少手动内存管理的复杂性和潜在的错误。