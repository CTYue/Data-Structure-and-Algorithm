/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-14 11:21:55
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-14 11:31:18
 * @Description: To be added.
 */

#include <iostream>       // std::cout
#include <exception>      // std::exception

using namespace std;

struct myException: std::exception
{
    //在函数名后面加const，表明该方法不会改变类的data members.
    const char* what() const noexcept 
    {return "Something wrong!\n";}
};

int main(int argc, char** argv)
{
    try
    {
        throw myException();
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 1;
}