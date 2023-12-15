/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-13 18:33:11
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-14 19:04:03
 * @FilePath: \LearnCPP\src\Foundation\lessons03\PointersToPointers.cpp
 * @Description: 二级指针(此程序编写时在终端执行，程序需要输出中文，因此改变了该文件的编码格式为（GB 2312）)
 */
#include <iostream>

void ChangeValueP2P(int **ptr);
void ChangeValueP(int *ptr);
void PrintMatrix(int **matrix, int rows, int cols);

int main(int argc, char const *argv[])
{
    // 二级指针的创建
    int num = 12;
    int *pnum = &num;
    int **ppnum = &pnum;

    std::cout << "num: " << num << "\taddr: " << &num << std::endl;
    std::cout << "pnum: " << pnum << "\taddr: " << &pnum << std::endl;
    std::cout << "ppnum: " << ppnum << "\taddr: " << &ppnum << std::endl;
    std::cout << std::endl;
    
    // 使用二级指针创建二维数组
    const int rows = 3;
    const int cols = 4;

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]{1, 2, 3, 4};
    }

    matrix[0][0] = 99;

    PrintMatrix(matrix, rows, cols);
    std::cout << std::endl;

    // 释放内存
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    ChangeValueP2P(ppnum);
    std::cout << "num: " << num << std::endl;

    ChangeValueP(pnum);
    std::cout << "num: " << num << std::endl;
    std::cout << std::endl;

    int *p = new int(2);
    // 通过指针无法改变指针的值
    {
        std::cout << "通过指针无法改变指针的值：" << std::endl;
        int *pp = p;      // 此时指针变量pp和指针变量p指向同一内存

        std::cout << "pp: " << pp << "\t*pp: " << *pp << std::endl;
        std::cout << "p: " << p << "\t*p: " << *p << std::endl;

        pp = new int(12); // pp指向了新分配的内存，而p所指向的内存却没有改变
        std::cout << "pp: " << pp << "\t*pp: " << *pp << std::endl;

        delete pp;
    }
    std::cout << "p: " << p << "\t*p: " << *p << std::endl;
    std::cout << std::endl;

    // 通过二级指针改变指针的值
    {
        std::cout << "通过二级指针改变指针的值：" << std::endl;
        int **pp = &p;  // 二级指针pp指向指针p的地址

        std::cout << "pp: " << pp << "\t*pp: " << *pp << "\t**pp: " << **pp << std::endl;
        std::cout << "p: " << p << "\t*p: " << *p << std::endl;

        *pp = new int(20);
        std::cout << "pp: " << pp << "\t*pp: " << *pp << "\t**pp: " << **pp << std::endl;
    }
    std::cout << "p: " << p << "\t*p: " << *p << std::endl;
    
    delete p;
    return 0;
}

// 通过二级指针改变数值
void ChangeValueP2P(int **ptr)
{
    std::cout << "ChangeValueP2P: " << **ptr << std::endl;
    **ptr = 234;
}

// 通过指针改变数值
void ChangeValueP(int *ptr)
{
    std::cout << "ChangeValueP: " << *ptr << std::endl;
    *ptr = 888;
}

// 打印二维数组
void PrintMatrix(int **matrix, int rows, int cols)
{
    std::cout << "matrix:" << std::endl;
    std::cout << "[";
    for (int i = 0; i < rows; i++)
    {
        if (i == 0)
        {
            std::cout << "[";
        }
        else
        {
            std::cout << " [";
        }

        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j];
            if (j != cols - 1)
            {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i == rows - 1)
        {
            std::cout << "]" << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }
}