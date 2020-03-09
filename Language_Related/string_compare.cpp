/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-21 00:50:36
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-21 18:04:22
 * @Description: Examples for std::compare().
 */
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string str1("green apple");
    string str2("red apple");
    string str3("apple");
    string str4("/a/b/c");
    string str5("/a/b");
	string str6("/a/aaaa");
    //
    //std::compare return values:
	//0	They compare equal
    //<0	Either the value of the first character that does not match is lower in the compared string, or all compared characters match but the compared string is shorter.
    //>0	Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer.

    // cout<<str4.compare(0, str4.length(), str5, 0, str5.length())<<endl;
    // if(str4.compare(0, str4.length(), str5, 0, str5.length())==0)   cout<<"str4 == str5"<<endl;
    if(str4.compare(0, str4.length(), str5, 0, str5.length())>0)  
    {
        cout<<"return = " <<str4.compare(0, str4.length(), str5, 0, str5.length())<<endl;
        cout<<"str4 containes str5"<<endl;
    }  
    // if(str5.compare(0, str5.length(), str4, 0, str4.length())<0)    cout<<"str4 containes str5"<<endl;
    // cout<<str5.compare(0, str5.length(), str4, 0, str4.length())<<endl;
    cout<<str6.compare(0,str6.length(),str5,0,str5.length())<<endl;
    
}
