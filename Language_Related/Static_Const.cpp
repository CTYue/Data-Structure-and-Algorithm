/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-15 07:04:56
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-15 19:01:56
 * @Description: Examples for static keyword in C++.
 */

#include <iostream>

static int a = 666;
using namespace std;

class A
{
public:
//static member belongs to the class, not 
//instances.
    static int a;
};

class B
{
public:
    static const int a=888;//Must be const if initialized here.
};

int main(int argc, char* argv[])
{
    // A a_0;
    // a_0.a=999;
    // std::cout << "a_0.a = " << a_0.a << std::endl;
    // std::cout << "A::a = " << A::a << std::endl;//Problem here, a was not initialized.
    // A a_1;
    // std::cout << "a_1.a = " << a_1.a << std::endl;

    B b_0;
    // b_0.a=1234;
    std::cout << "B::a = " << B::a << std::endl;

    return 1;
}