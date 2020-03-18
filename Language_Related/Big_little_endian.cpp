/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-18 11:34:13
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-18 18:15:12
 * @Description: To be added.
 */
#include <iostream>
#include <string>
using namespace std;

//Union都是从低地址开始存放
//我们要的是？
union big_little
{
    char arr[2];
};


int main(int argc, char** argv)
{
    big_little t;
    //???

    t.arr[0]='a';
    t.arr[1]='b';

    cout<<t.x<<" "<<endl; //???
    cout<<t.y<<" "<<endl; //???

    return 1;
}