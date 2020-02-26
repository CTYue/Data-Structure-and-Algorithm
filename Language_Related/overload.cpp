/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-24 03:38:45
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-02-24 03:40:36
 * @Description: To be added.
 */

#include <iostream>

using namespace std;

int foo(int x)
{
    return x;
};

double foo(double x)
{
    return x;
};

int main(int argc, char** argv)
{
    int x=123;
    cout<<foo(x)<<endl;
    double gpa=3.17;
    cout<<foo(gpa)<<endl;

    return 1;
}