/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-12 20:21:50
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-12 21:41:46
 * @Description: To be added.
 */
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    //判断一个字符串是否为float型
    
    // if(std::stof())
    // cout<<std::stof(f)<<endl;
    // cout<<std::stof(nf)<<endl;

    // auto res=std::stof(f);
    //Solution 1
    string f="3.1415926";
    string nf="hello";

    try
    {
        // auto res=std::stof(nf);
        auto res=std::stof(nf);
        cout<<res<<endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //
    //用shell删除一个文件的前50个字符


    return 1;
}