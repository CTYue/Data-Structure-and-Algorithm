/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-15 18:48:49
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-15 22:29:34
 * @Description: Number conversion using Stack and Queue.
 */

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

//Convert Decimal number to Octal number.
//Using stack.
//Review the first OJ solution I wrote in 2011.
//Time Complexity: O(n) (Input size related)
//Space Complexity: ???
int DecToOct(int num)
{
    std::cout << "Input = " << num << std::endl;
    // if(num==0 || num>=INT_MAX)  return 0;
    if(num==0)  return 0;
    // if(num>=INT_MAX) return EXIT_FAILURE;
    if(num>=65535)  return EXIT_FAILURE;

    //First come last out
    std::stack<std::string> stack;
    int remainder=0, num_digits=0;
    int temp=num;
    while(temp!=0)
    {
        temp/=10;
        num_digits++;
    }
    std::cout << "num_digits = " << num_digits << std::endl;
    
    while(num!=0 && num_digits>0 )
    {
        remainder = num%8;
        num /= 8;
        // std::cout << "remainder = " << remainder << std::endl;
        stack.push(std::to_string(remainder));
    }

    while(!stack.empty())
    {
        std:cout << stack.top();
        stack.pop();
    }
    std::cout << std::endl;

    return 1;
}


int main(int argc, char* argv[])
{
    if(argc<1) return 0;
    std::cout << "INT_MAX = " << INT_MAX << std::endl;

    // DecToOct(1);
    // DecToOct(10);
    // DecToOct(111);
    // DecToOct(65535);
    // DecToOct(996);
    DecToOct(65536);

    return 1;
}