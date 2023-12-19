/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-19 19:50:41
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-19 20:58:17
 * @FilePath: \LearnCPP\src\Foundation\lessons04\Matrix.cpp
 * @Description: 二位数组
 */
#include <iostream>
void PrintMatrix(int p[][2], int row, int col);
int main(int argc, char const *argv[])
{
    int matrix[][2] = {0,1,2,3,4,5};
    
    // 打印二维数组
    std::cout << "main:" << std::endl;
    for (size_t i = 0; i < sizeof(matrix)/sizeof(*matrix); i++)
    {
        for (size_t j = 0; j < sizeof(*matrix)/sizeof(**matrix); j++)
        {
            std::cout << "  matrix["<< i <<"][" << j << "]=" << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // 调用打印函数
    std::cout << "PrintMatrix:" << std::endl;
    PrintMatrix(matrix, sizeof(matrix)/sizeof(*matrix), sizeof(*matrix)/sizeof(**matrix));
    std::cout << std::endl;
    
    

    // 定义行指针指向二维数组
    int (*p)[2] = matrix;
    // 
    std::cout << "p = " << p << "\tp+1 = " << p+1 << std::endl;
    // std::cout << "*p = " << *p << "\t*(p+1) = " << *(p+1) << std::endl;
    std::cout << "**p = " << **p << "\t**(p+1) = " << **(p+1) << std::endl;
    std::cout << "p[0] = " << p[0] << "\tp[1] = " << p[1] << std::endl;
    std::cout << "p[0][0] = " << p[0][0] << "\tp[1][0] = " << p[1][0] << std::endl << std::endl;

    std::cout << "int (*p)[2]:" << std::endl;
    for (size_t i = 0; i < sizeof(matrix)/sizeof(*p); i++)
    {
        for (size_t j = 0; j < sizeof(*p)/sizeof(**p); j++)
        {
            std::cout << "  matrix["<< i <<"][" << j << "]=" << p[i][j];
        }
        std::cout << std::endl;
    }


    return 0;
}

void PrintMatrix(int p[][2], int row, int col){
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            std::cout << "  matrix["<< i <<"][" << j << "]=" << p[i][j];
        }
       std::cout << std::endl;
    }
    
}