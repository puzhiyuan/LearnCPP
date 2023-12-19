/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-19 14:12:57
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-19 15:19:21
 * @FilePath: \LearnCPP\src\Foundation\lessons04\Array.cpp
 * @Description: 数组
 */
#include <iostream>
#include <string.h>
void PrintArray(int arr[], int size);
int main(int argc, char const *argv[])
{
    int arr1[5];
    for (int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++)
    {
        arr1[i] = i + 1;
    }
    std::cout << "arr1:" << std::endl;
    PrintArray(arr1, sizeof(arr1)/sizeof(arr1[0]));
    
    int arr2[sizeof(arr1)/sizeof(arr1[0])];

    // memcpy(arr2, arr, sizeof(arr)/sizeof(int));
    // 注意这里的第三个参数是字节数
    memcpy(arr2, arr1, sizeof(arr1));
    std::cout << "arr2:" << std::endl;
    PrintArray(arr2, sizeof(arr2)/sizeof(arr2[0]));

    // 数组清0
    memset(arr2, 0, sizeof(arr2));
    std::cout << "arr2(set 0):" << std::endl;
    PrintArray(arr2, sizeof(arr2)/sizeof(arr2[0]));


    return 0;
}

void PrintArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "] = " << arr[i] << std::endl;
    }
}
