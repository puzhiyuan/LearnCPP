/*
 * @Author: ��puzhiyuan�� ��puzhiyuan185489643@gmail.com��
 * @Date: 2023-12-08 14:19:59
 * @LastEditors: ��puzhiyuan�� ��puzhiyuan185489643@gmail.com��
 * @LastEditTime: 2023-12-17 21:58:20
 * @FilePath: \LearnCPP\src\Foundation\lessons01\Cin.cpp
 * @Description: learn cin(ʹ��GB 2312��ʽ��)
 */
#include <iostream>
#include <string>

int main() {
    // ��ȡ��������
    int integerValue;
    std::cout << "������һ������: ";
    std::cin >> integerValue;
    std::cout << "�������������: " << integerValue << std::endl;

    // ��ȡ�ַ�������
    std::string stringValue;
    std::cout << "������һ���ַ���: ";
    std::cin.ignore();  // ����ǰһ�������еĻ��з�
    std::getline(std::cin, stringValue);
    std::cout << "��������ַ�����: " << stringValue << std::endl;

    return 0;
}
