/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-19 02:30:02
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-02-19 02:38:55
 * @Description: To be added.
 */
#include<iostream>
#include<vector>

using namespace std;
void foo(int& x)
{
   x=666;
}

void bar(int *x)
{
   *x=888;
}

// void foo(vector<int>& arr)
// {
//   cout<<"arr.size() = "<<arr.size<<endl;
// }

// void bar(vector<int>* arr)
// {
//   cout<<"arr.size() = "<<arr->size()<<endl;
// }

int main()
{
    int x=666;
    int y=888;
    cout<<"x="<<x<<endl<<"y="<<y<<endl;
    int& ref=x;
    cout<<"ref = "<<ref<<endl;
    ref=y;
    cout<<"ref = "<<ref<<endl;
    int z=999;
    const int& test=z;
    cout<<"test = "<<test<<endl;
    
    //int&&&不合法，不能使用多级引用!
    int&&& test_again=z;
    cout<<"test_again = "<<test_again<<endl;

    return 1;
}
