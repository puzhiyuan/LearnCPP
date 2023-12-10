#include<iostream>  
#include <limits>
using namespace std;

int main()
{
    cout << "type: \t\t" << " size"<< endl << endl;  
    cout << "bool: \t\t" << "size:" << sizeof(bool) << endl;  

    cout << "char: \t\t" << "size:" << sizeof(char) << endl;  

    cout << "signed char: \t" << "size:" << sizeof(signed char) << endl;  

    cout << "unsigned char: \t" << "size:" << sizeof(unsigned char) << endl;  

    cout << "wchar_t: \t" << "size:" << sizeof(wchar_t) << endl;  

    cout << "short: \t\t" << "size:" << sizeof(short) << endl;  

    cout << "int: \t\t" << "size:" << sizeof(int) << endl;  

    cout << "unsigned: \t" << "size:" << sizeof(unsigned) << endl;  

    cout << "long: \t\t" << "size:" << sizeof(long) << endl;  

    cout << "unsigned long: \t" << "size:" << sizeof(unsigned long) << endl;  

    cout << "double: \t" << "size:" << sizeof(double) << endl;  

    cout << "long double: \t" << "size:" << sizeof(long double) << endl;  

    cout << "float: \t\t" << "size:" << sizeof(float) << endl;  

    cout << "size_t: \t" << "size:" << sizeof(size_t) << endl;  

    cout << "string: \t" << "size:" << sizeof(string) << endl;  
    return 0;  
}