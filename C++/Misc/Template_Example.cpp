/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-15 05:11:47
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-15 16:33:40
 * @Description: This file uses a few examples
 * to introduce C++ template programming feature.
 * @Reference:  https://en.wikipedia.org/wiki/Template_metaprogramming
 */

#include <iostream>
#include <vector>

using namespace std;

//Class Template
template<typename T>
class List
{
public:
    List(T x):val(x){};
private:
    T val;
};

//Variable Template(C++14)
template<typename T>
T val=0;

//Alias template(C++ 11)
template<typename T>
using Container=std::vector<T>;


//Template MetaProgramming
//Metaprogramming functions execute at 
//compile-time.
template<int N>
class Func
{
public:
    enum{ res=N * Func<N-1>::res};
};

//Add a specialization template as stopping state
template<>
class Func<0>
{
public:
    enum{res=1};
};

//Must use const data member in template Metaprogramming
//
template<int N>
class Func_new
{
public:
//Static means the variable belongs to the class, not
//instances.
    static const long res = N * Func_new<N - 1>::res;
};

//Specialization (Stopping state)
template<>
class Func_new<0>
{
public:
    static const long res = 1;
};

//Metaprogramming with inline function


int main(int argc, char* argv[])
{        
    std::cout << "MetaProgramming: " << std::endl;
    std::cout << Func<20>::res << std::endl;
    std::cout << Func_new<20>::res << std::endl;

    return 1;
}