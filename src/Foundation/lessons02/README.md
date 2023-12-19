# 变量、函数

## 1 变量
C++ 的变量是程序中用于存储和操作数据的基本单元。在C++中，变量具有类型，这意味着它们可以存储不同类型的数据，如整数、浮点数、字符等。

### 变量的声明和定义
- 声明变量
  - 变量声明是告诉编译器有一个变量存在，但并不为其分配内存。
  - 语法：`extern int x`;
- 定义变量：
  - 变量定义不仅声明了变量，还为其分配了内存空间。
  - 语法：`int x = 42`;

### 变量的类型
- 整数类型：
  - `int`: 整数类型，通常表示32位整数。
  - `short`: 短整数类型，通常表示16位整数。
  - `long`: 长整数类型，通常表示64位整数。
  - `long long`: 长长整数类型，通常表示至少64位整数。

- 浮点数类型：
  - `float`: 单精度浮点数。
  - `double`: 双精度浮点数。
  - `long double`: 扩展精度浮点数。

- 字符类型：
  - `cha`r: 单个字符类型。
  - `wchar_t`: 宽字符类型。
  - `char16_t`、`char32_t`: Unicode字符类型。

- 布尔类型：
  - `bool`: 逻辑类型，只能取 `true` 或 `false`。

- 自定义类型：
  - 使用 `struct`、`class` 关键字创建自定义类型，如结构体和类。

### 变量的作用域和生存期
- 作用域：
  - 变量的作用域是其在程序中可见的区域。
  - 局部变量在定义它的代码块内可见，全局变量在整个文件中可见。
- 
- 生存期：
  - 变量的生存期是指变量存在的时间。
  - 局部变量在其定义的代码块执行期间存在，全局变量在程序执行期间存在。
### 初始化变量
- 默认初始化：
  - 变量声明时如果没有显式初始化，将会被默认初始化。
  - 整数类型默认为`0`，浮点数类型默认为`0.0`，指针默认为`nullptr`，其他类型没有默认值。

- 列表初始化：
  - 使用大括号 `{}` 进行初始化，提供了统一的初始化语法。
  - `int x{42};` 或 `int x = {42};`
  
- 直接初始化和拷贝初始化：
  - 直接初始化使用圆括号 `( )` 进行初始化，如 `int x(42);`。
  - 拷贝初始化使用等号 `=` 进行初始化，如 `int x = 42;`。

### 常量和修饰符
- `const` 关键字：
  - 用于声明常量，一旦初始化就不能修改。
  - `const int MAX_VALUE = 100;`

- `constexpr` 关键字：
  - 用于声明常量表达式，编译时求值。
  - `constexpr int square(int x) { return x * x; }`

- `volatile` 关键字：
  - 声明变量为 `volatile` 表示它可能会在程序未明确要求的情况下被修改。


## 2 函数
函数是C++程序中的基本构建块，用于封装一组相关的代码以执行特定的任务。

### 函数的定义和声明
- 函数声明
  - 用于告诉编译器函数的存在和如何调用，但不提供具体实现。
  - 语法：`returnType functionName(parameterType1, parameterType2, ...);`
  ```cpp
  int add(int a, int b); // 函数声明
  ```
- 函数定义：
  - 提供函数的实现，包括函数体内的具体语句。
  - 语法：`returnType functionName(parameterType1 paramName1, parameterType2 paramName2, ...) { /* 函数体 */ }`
  ```cpp
  int add(int a, int b) { // 函数定义
    return a + b;
  }
  ```

### 函数参数与返回值
- 参数传递
  - 函数可以接受零个或多个参数，参数类型和数量在声明和定义中指定。
  - 传递参数的值或引用。

  ```cpp
  void printMessage(std::string message) {
    std::cout << message << std::endl;
  } 
  ```

- 返回值
  - 函数可以返回一个值，返回类型在声明和定义中指定。
  - 使用 `return` 语句返回值。
  ```cpp
  int square(int x) {
    return x * x;
  }
  ```

### 函数调用
- 在程序中通过函数名和实际参数列表来调用函数。
  ```cpp
  int result = add(3, 4); // 调用 add 函数
  ```

### 函数重载
- 允许定义多个具有相同名称但参数列表不同的函数。
  ```cpp
  int add(int a, int b);
  double add(double a, double b);
  ```
### 默认参数
- 允许在函数声明中为某些参数提供默认值。
  ```cpp
  void printRepeatedMessage(std::string message, int times = 1) {
    for (int i = 0; i < times; ++i) {
        std::cout << message << std::endl;
    }
  }
  ```
### 函数模板
- 允许编写通用的函数，能够处理多种数据类型。
  ```cpp
  template <typename T>
  T add(T a, T b) {
      return a + b;
  }
  ```
### 返回多个值
- 使用引用或指针，或者通过返回结构体或类来实现返回多个值。
  ```cpp
  void getMinMax(int arr[], int size, int& min, int& max) {
    // 实现获取最小值和最大值的逻辑
  }
  ```

### 函数作用域
- 函数内部声明的变量具有局部作用域，仅在函数内可见。

### 函数的生命周期
- 函数在调用时创建，执行完毕后销毁。
- 局部变量在函数调用时分配内存，在函数结束时释放。

### 函数指针
- 指向函数的指针，可以在运行时动态选择调用哪个函数。
  ```cpp
  int (*ptr)(int, int) = add; // 声明一个指向 add 函数的指针
  ```
  
### 内联函数
- 使用 `inline` 关键字声明的函数，建议编译器在调用处展开函数代码，提高执行效率。
  ```cpp
  inline int multiply(int a, int b) {
    return a * b;
  }
  ```

### Lambda 表达式
- 允许在代码中定义匿名函数，提高代码的简洁性和可读性。
  ```cpp
  auto sum = [](int a, int b) -> int {
    return a + b;
  };
  ```