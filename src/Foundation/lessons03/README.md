# 指针

## 1 `void*`
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

## 2 const修饰指针
- **常量指针**： 无法通过指针修改指向的值，但可以修改指针本身指向的地址。它的声明方式是指针前加 const，例如 `const int* num`。
- **指针常量**： 可以通过指针修改指向的值，但无法修改指针本身指向的地址。它的声明方式是指针指向的类型前加 const，例如 `int* const num`。
- **常指针常量**： 指既不能通过指针修改指向的值，也不能修改指针本身指向的地址。它的声明方式是指针前后都加 const，例如 `const int* const num`。

## 3 内存区域
在计算机运行C++程序时，内存可以分为几个主要区域（堆、栈、全局/静态存储区、常量存储区、代码区），每个区域具有不同的作用和特性。

### 3.1 栈（Stack）：
- **作用**
  - 用于存储函数调用的**局部变量**、**函数参数**和**函数调用的返回地址**。每个线程都有自己的栈。
- **特性**
  - 栈是一种**后进先出**（LIFO）的数据结构，函数调用时会在栈上创建一个新的栈帧，包含**局部变量**、**参数**和**返回地址**。
  - 栈的大小通常受限制，由操作系统或编译器设定，一般较小。
  - 栈的内存由编译器自动分配和释放，无需手动管理。栈上的内存分配和释放是非常快速的。

### 3.2 堆（Heap）：

- **作用**
  - 用于动态分配内存，存储在堆上的内存可以在程序的任何地方使用。
- **特性**
  - 堆是一种动态分配的内存区域，大小通常比栈大得多。
  - 内存的分配和释放由程序员手动管理，通过 `new` 操作符分配内存，通过 `delete` 操作符释放内存。
  - 堆上的内存生命周期不受限制，需要程序员确保手动释放已分配的内存，否则可能导致内存泄漏。

### 3.3 全局/静态存储区（Global/Static Storage Area）：

- **作用**
  - 用于存储全局变量和静态变量。
- **特性**
  - 存储在这里的变量在整个程序运行期间都存在，其生命周期与程序的生命周期相同。
  - 全局变量在程序启动时被分配，而静态变量在首次访问时分配。

### 3.4 常量存储区（Constant Storage Area）：
- **作用**
  - 用于存储常量值，如字符串常量。
- **特性**
  - 常量存储区的内存是只读的，存储在这里的数据不能被修改。
  - 存储程序中使用的各种常量值，如字符串文字和全局 const 变量。

### 3.5 代码区（Code Area）：

- **作用**
  - 用于存储程序的机器码指令。
- **特性**
  - 代码区的内存是只读的，存储程序的执行指令。
  - 在程序加载到内存中时由操作系统加载，通常与常量存储区分开。

## 4 内存分配
### 4.1 静态内存分配
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

### 4.2 动态内存分配
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
动态内存分配的优势在于它允许程序在运行时灵活地分配和释放内存，但需要注意及时释放动态分配的内存，以避免内存泄漏。在现代C++中，更推荐使用智能指针（如 `std::unique_ptr` 和`std::shared_ptr`）来管理动态内存，以减少手动内存管理的复杂性和潜在的错误。

### 4.3 注意事项
- **及时释放内存**： 使用 `new` 分配的内存需要及时释放，以防止内存泄漏。每个 `new` 对应一个 `delete`，每个 `new[]` 对应一个 `delete[]`。
- **自动回收**： 动态分配的内存生命周期与程序相同，程序退出时，如果没有释放，系统将自动回收，
- **防止二次释放**： 确保每块内存只被释放一次。二次释放同一块内存会导致未定义行为。
- **初始化动态分配的内存**： 动态分配的内存内容是未定义的，因此在使用之前最好进行初始化。
- **使用智能指针**： 使用智能指针（如 `std::unique_ptr`、`std::shared_ptr`）可以避免手动管理内存的复杂性，减少内存泄漏和二次释放的风险。
- **注意数组和指针的区别**： 对于动态分配的数组，使用 `new[]` 和 `delete[]`，而不是 `new` 和 `delete`。
- **避免内存泄漏**： 谨慎处理指针的所有权，确保在不再需要使用动态分配的内存时释放它。
- **考虑异常安全性**： 在动态分配内存时，考虑代码的异常安全性，以确保即使发生异常，也能正确地释放已分配的内存。

## 5 二级指针
**二级指针**（double pointer）是指指向指针的指针，或者说是存储指针地址的指针。在 C++ 中，通常使用指向指针的指针来实现多级指针的概念，但这种用法更常见于 C 语言。

### 5.1 定义和声明
在声明和定义二级指针时，需要使用两个星号 **。
```cpp
int main() {
    int value = 42;
    int* ptr = &value;     // 指针
    int** doublePtr = &ptr; // 二级指针

    // 通过二级指针访问数据
    std::cout << "Value: " << **doublePtr << std::endl;

    return 0;
}
```

### 5.2 使用场景
- **动态分配多维数组**
    ```cpp
    int main() {
        int rows = 3;
        int cols = 4;

        // 动态分配二维数组
        int** matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }

        // 使用二维数组
        matrix[1][2] = 10;

        // 释放内存
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

        return 0;
    }
    ```

- **函数参数传递**： 可以使用二级指针作为函数参数，以在函数内修改指针指向的值。
    ```cpp
    void modifyValue(int** ptr) {
        **ptr = 100;
    }

    int main() {
        int value = 42;
        int* ptr = &value;

        // 通过二级指针传递指针
        modifyValue(&ptr);

        std::cout << "Value: " << value << std::endl;

        return 0;
    }
    ```

### 5.3 注意事项
- **避免混淆**：多级指针可能容易引起混淆，特别是在使用动态内存分配时，要确保正确释放分配的内存，避免内存泄漏。

- **谨慎使用**：在实际编程中，多级指针的使用相对较少，更推荐使用标准库中的容器（如 `std::vector` 或 `std::vector<std::vector<int>>`）来管理多维数据结构。

## 6 空指针和野指针
### 6.1 空指针（Null Pointer）：
- **定义**
  - 空指针是指未指向任何有效内存地址的指针。

- **表示**
  - 在 C++ 中，可以使用 nullptr 来表示空指针。

    ```cpp
    int *ptr = nullptr;
    ```

- **用途**
  - 在初始化指针时，可以将其设置为空指针，表示它当前不指向任何有效的内存地址。
  - 用于条件检查，以确保指针在使用之前已经被初始化。
- **检查空指针**
    ```cpp
    int *ptr = nullptr;
    if (ptr == nullptr) {
        // 执行相应的操作，避免在未初始化的指针上操作
    }
    ```

### 6.2 野指针（Dangling Pointer）：
- **定义**
  - 野指针是指指向已经被释放或无效的内存地址的指针。

- **原因**
  - 指针没有被初始化，但被引用。
  - 指针指向的内存已经被释放，但指针仍然保留了该地址。

- **危害**
  - 访问野指针可能导致程序崩溃或产生不可预测的结果。
  - 由于野指针引用的内存已经被释放，可能会影响其他正在使用该内存的部分。
  
- **避免野指针**
  - 在释放内存后，将指针设置为 nullptr 或 NULL，以避免成为野指针。
  - 避免使用未初始化的指针。

    ```cpp
    int *ptr = new int; // 分配动态内存
    delete ptr;        // 释放内存
    // 后续操作中 ptr 仍然存在，但指向的内存已经被释放，ptr 变成了野指针
    ```

## 7 函数指针和回调函数
### 6.1 函数指针（Function Pointers）
函数指针是指向函数的指针，它存储函数的地址。使用函数指针可以动态地选择要调用的函数，这在实现回调函数、函数表等场景中非常有用。

- **声明和定义函数指针**                                            
  ```cpp
  typedef int (*FuncPtr)(int, int);  // 声明一个函数指针类型

  int Sum(int a, int b) {
      return a + b;
  }

  int Subtract(int a, int b) {
      return a - b;
  }

  int main() {
      FuncPtr operation = Sum;  // 初始化指针，指向 Sum 函数
      int result = operation(5, 3);  // 调用 Sum 函数
      operation = Subtract;  // 改变指针，指向 Subtract 函数
      result = operation(5, 3);  // 调用 Subtract 函数
      return 0;
  }
  ```

- **函数指针作为参数**
  ```cpp
  int Calculate(int a, int b, int (*operation)(int, int)) {
      return operation(a, b);
  }

  int main() {
      int result = Calculate(5, 3, Sum);  // 传递 Sum 函数指针
      result = Calculate(5, 3, Subtract);  // 传递 Subtract 函数指针
      return 0;
  }
  ```

### 6.2 回调函数（Callback Functions）
回调函数是一个通过函数指针传递给其他函数的函数，用于在某个事件发生时被调用。回调函数通常用于实现灵活的、可定制的行为，例如在事件处理、异步操作等场景中。

- **声明和使用回调函数**
  ```cpp
  // 声明回调函数类型
  typedef void (*Callback)(int);

  // 接受回调函数作为参数的函数
  void PerformOperation(int value, Callback callback) {
      // 执行某些操作
      // 调用回调函数
      callback(value);
  }

  // 回调函数
  void PrintValue(int value) {
      std::cout << "Value: " << value << std::endl;
  }

  int main() {
      // 使用回调函数
      PerformOperation(42, PrintValue);

      return 0;
  }
  ```

- **Lambda 表达式作为回调**

  使用 C++11 引入的 Lambda 表达式，可以更方便地定义匿名的回调函数。
  ```cpp
  #include <functional>

  void PerformOperation(int value, std::function<void(int)> callback) {
      callback(value);
  }

  int main() {
      PerformOperation(42, [](int value) {
          std::cout << "Value: " << value << std::endl;
      });
      return 0;
  }
  ```
