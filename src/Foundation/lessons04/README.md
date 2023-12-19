<!--
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-19 13:45:51
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-19 21:17:01
 * @FilePath: \LearnCPP\src\Foundation\lessons04\README.md
 * @Description: 
-->
# 数组相关内容
## 1 数组
### 声明和定义
- 声明一维数组：
  - 在声明数组时，需要指定数组的类型和名称，但不包括数组的大小。
    ```cpp
    int myArray[];
    ```
- 定义一维数组：
  - 在定义数组时，需要指定数组的类型、名称和大小。
    ```cpp
    int myArray[5]; // 定义一个包含5个整数的数组
    ```
### 数组元素的访问
- 数组中的元素通过索引（下标）进行访问，索引从0开始。
    ```cpp
    myArray[0] = 10; // 设置数组第一个元素的值为10
    int value = myArray[2]; // 获取数组第三个元素的值
    ```
### 数组的初始化
- 在定义时初始化
  - 使用花括号 `{}` 在定义数组时初始化元素。
    ```cpp
    int myArray[] = {1, 2, 3, 4, 5}; // 自动推断数组大小
    ```
- 在定义后初始化
  - 分配数组后，可以通过逐个元素赋值来初始化。
    ```cpp
    int myArray[5];
    myArray[0] = 1;
    myArray[1] = 2;
    // ...
    ```

### 数组的特性
- 数组是连续的内存块：
  - 数组的元素在内存中是相邻的，可以通过指针和索引进行高效的访问。

- 数组的大小是固定的：
  - 一旦数组定义，其大小是固定的，不能在运行时改变。
  
### 数组和指针的关系
- 数组名可以看作是指向数组首元素的指针。
    ```cpp
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr; // 数组名 arr 等价于 &arr[0]
    ```

### 数组作为函数参数
- 数组可以作为函数参数传递，但在函数内部失去了大小信息。
    ```cpp
    void printArray(int arr[], int size) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    ```

### 多维数组
- 一维数组是多维数组的基础，可以用于构建更复杂的数据结构，如二维数组。
    ```cpp
    int matrix[3][4]; // 定义一个3行4列的二维数组
    ```

### 标准库中的数组类型：
- C++11 引入了 `std::array` 类模板，提供了更安全、方便的数组类型。
    ```cpp
    #include <array>
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};
    ```

### 动态分配内存注意事项
- 动态创建的数组没有数组名，不能用 `sizeof` 运算符。
- 可以用数组表示法和指针表示法两种方式使用动态创建的数组。
- 必须使用 `delete[]` 来释放动态数组的内存（不能只用 `delete`, `delete`只能释放第0个元素空间）
- 不要用 `delete[]` 来释放不是 `new[]` 分配的内存。
- 不要用 `deletel[]` 释放同一个内存块两次（否则等同于操作野指针）。
- 对空指针用 `deletel[]` 是安全的（释放内存后，应该把指针置空 `nullptr` ）。
- 声明普通数组的时候，数组长度可以用变量，相当于在栈上动态创建数组，并且不需要释放。
- 如果内存不足，调用 `new` 会产生异常，导致程序中止；如果在 `new` 关键字后面加 `(std:nothrow)` 选项，则返回 `nullptr` ,不会产生异常。
- 使用 `delete[]` 释放动态分配的数组时，不需要指定数组的大小


## 2 qsort函数
qsort 函数是C标准库中提供的用于对数组进行快速排序的函数。它是一个通用的排序函数，可以根据用户提供的比较函数对数组进行排序。

### 函数原型
```cpp
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
```
- 参数说明：
  - `base`：指向待排序数组的指针，数组中的元素将按照指定的比较函数进行排序。
  - `nmemb`：数组中元素的数量。
  - `size`：每个元素的大小（以字节为单位）。
  - `compar`：比较函数的指针，用于指定元素之间的比较规则。

### 比较函数 `compar`
比较函数 `compar` 是用户提供的函数，用于定义数组元素之间的比较规则。其原型如下：
```cpp
int compar(const void *a, const void *b);
```
- 如果 `a` 小于 `b`，则返回一个负整数。
- 如果 `a` 等于 `b`，则返回零。
- 如果 `a` 大于 `b`，则返回一个正整数。

### 注意事项：
- `qsort` 函数是原址排序（in-place sorting）的，因此它直接修改传入的数组。
- `qsort` 不提供稳定排序，即相等元素的相对顺序在排序后可能发生改变。
- 注意在比较函数中正确处理指针类型的转换，以避免类型不匹配的问题。
- 当使用 `qsort` 时，确保提供正确的数组元素大小和比较函数。

## 3 二维数组
二维数组是一种多维数组，它可以看作是一个表格，包含行和列。

### 声明和初始化二维数组
```cpp
// 声明一个3行4列的整数二维数组
int matrix[3][4];

// 初始化二维数组
int matrix2[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```
### 访问二维数组元素
```cpp
// 访问二维数组元素
int value = matrix[1][2]; // 获取第2行第3列的元素值（下标从0开始）

// 修改二维数组元素的值
matrix[0][1] = 10;
```

### 多维数组和内存存储
二维数组在内存中是按行存储的。例如，`matrix[2][3]` 在内存中的位置可以计算为 `&matrix[0][0] + 2 * 4 + 3`，其中 `4` 是每行的元素个数。

### 传递二维数组给函数
```cpp
void printMatrix(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// 调用函数
printMatrix(matrix2, 2, 3);
```

### 动态分配二维数组
```cpp
// 动态分配3行4列的整数二维数组
int** dynamicMatrix = new int*[3];
for (int i = 0; i < 3; ++i) {
    dynamicMatrix[i] = new int[4];
}

// 访问和修改动态分配的二维数组元素
dynamicMatrix[1][2] = 42;

// 释放动态分配的内存
for (int i = 0; i < 3; ++i) {
    delete[] dynamicMatrix[i];
}
delete[] dynamicMatrix;
```

### 使用vector实现动态二维数组
```cpp
#include <vector>

// 声明一个3行4列的整数二维数组
std::vector<std::vector<int>> dynamicMatrix(3, std::vector<int>(4, 0));

// 访问和修改动态二维数组元素
dynamicMatrix[1][2] = 42;
```
使用 `vector` 可以更方便地管理动态二维数组，它自动处理内存分配和释放。

### 数组与指针的关系
```cpp
int arr[3][4];
int (*ptr)[4] = arr; // ptr是指向包含4个整数的数组的指针
```

## 4 三维数组
三维数组是数组的一种，它包含三个维度，每个维度都是一个数组。

### 定义和声明
```cpp
// 定义一个3x3x3的三维数组
int threeDArray[3][3][3];
```

### 初始化
```cpp
// 使用循环初始化三维数组
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
            threeDArray[i][j][k] = i + j + k;
        }
    }
}
```

### 访问元素
```cpp
int element = threeDArray[1][2][0];
```

### 迭代访问
```cpp
// 使用嵌套循环迭代访问三维数组的所有元素
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
            std::cout << threeDArray[i][j][k] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
```
### 动态分配
```cpp
// 动态分配一个3x3x3的三维数组
int*** dynamicThreeDArray = new int**[3];
for (int i = 0; i < 3; ++i) {
    dynamicThreeDArray[i] = new int*[3];
    for (int j = 0; j < 3; ++j) {
        dynamicThreeDArray[i][j] = new int[3];
    }
}

// 访问元素
int element = dynamicThreeDArray[1][2][0];

// 释放内存
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        delete[] dynamicThreeDArray[i][j];
    }
    delete[] dynamicThreeDArray[i];
}
delete[] dynamicThreeDArray;
```

### 使用std::vector
如果想要更方便、灵活地处理多维数组，可以使用`std::vector`嵌套
```cpp
#include <iostream>
#include <vector>

int main() {
    // 定义一个3x3x3的三维vector
    std::vector<std::vector<std::vector<int>>> threeDVector(3, std::vector<std::vector<int>>(3, std::vector<int>(3, 0)));

    // 初始化
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                threeDVector[i][j][k] = i + j + k;
            }
        }
    }

    // 访问元素
    int element = threeDVector[1][2][0];

    // 迭代访问
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                std::cout << threeDVector[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
```
使用`std::vector`有助于动态管理内存，并且能够轻松地获取数组的大小等信息。

### 数组名和指针
在多维数组中，数组名可以看作是指向数组首元素的指针。对于三维数组，这个指针的类型是一个指向二维数组的指针。
```cpp
int threeDArray[3][3][3];

// 数组名threeDArray可以看作是指向二维数组的指针
int (*p)[3][3] = threeDArray;
```
在上面的例子中，`p` 是一个指向二维数组的指针，而 `threeDArray` 是一个三维数组的数组名，它可以隐式地转换为指向二维数组的指针。

### 指针的解引用
指针解引用可以用来访问数组元素。对于三维数组，解引用操作会得到一个二维数组的指针，然后再进行二维数组的解引用。
```cpp
int (*p)[3][3] = threeDArray;

// 解引用得到二维数组的指针
int (*q)[3] = *p;

// 访问二维数组的元素
int element = q[1][2];
```

### 动态分配
可以使用指针来动态分配多维数组的内存。例如，可以使用三个嵌套的循环来动态分配三维数组。
```cpp
int ***dynamicThreeDArray = new int**[3];
for (int i = 0; i < 3; ++i) {
    dynamicThreeDArray[i] = new int*[3];
    for (int j = 0; j < 3; ++j) {
        dynamicThreeDArray[i][j] = new int[3];
    }
}
```