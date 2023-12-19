/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-19 18:39:14
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-19 18:54:01
 * @FilePath: \LearnCPP\src\Foundation\lessons04\Use_qsort.cpp
 * @Description: qsort函数的使用
 */
#include <iostream>
int CompareASC(const void* p1, const void* p2);
int CompareDESC(const void* p1, const void* p2);
int main(int argc, char const *argv[])
{
    int arr[] = {3,4,6,8,9,0,1,2,7,5};
    std::cout << "src:" << std::endl;
    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        std::cout << "arr[" << i << "]:" << arr[i] << std::endl;       
    }

    // 使用qsort函数对数组进行排序
    qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), CompareASC);
    std::cout << "asc:" << std::endl;
    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        std::cout << "arr[" << i << "]:" << arr[i] << std::endl;       
    }
    
    qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), CompareDESC);
    std::cout << "desc:" << std::endl;
    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        std::cout << "arr[" << i << "]:" << arr[i] << std::endl;       
    }
    return 0;
}

// 升序排序回调函数
int CompareASC(const void* p1, const void* p2){
    return *((int*)p1) - *((int*)p2);
}

// 降序排序回调函数
int CompareDESC(const void* p1, const void* p2){
    return  *((int*)p2) - *((int*)p1);
}
