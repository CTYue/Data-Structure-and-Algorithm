/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-12 21:08:43
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-12 21:17:13
 * @Description: To be added.
 */
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int i=42;
    const int &val=42;
    const int &val2=i+1;//const reference can be binded to a r-value(literal)
    try
    {
        int &val3=i+1;//regular referrence cannot be binded to r-value
    }
    
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    cout<<val<<endl;
    cout<<val2<<endl;
    
    return 1;
}