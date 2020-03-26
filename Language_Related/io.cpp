/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-12 21:32:22
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-12 21:43:29
 * @Description: To be added.
 */

#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    string input;
    //
    while(cin>>input)//cannot teminate elegantly
    // while(getline(cin, input))//getline eats all "\n"
    {

        if(input=="\n") return 0;
        cout<<input<<" ";
    }
    cout<<endl;

    return 1;
}