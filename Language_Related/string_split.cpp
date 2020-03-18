/*
 * Filename: /Users/yuzidong/Code/Notes/Language/spliter_in_cplusplus.cpp
 * Path: /Users/yuzidong/Code/Notes/Language
 * Created Date: Friday, March 1st 2019, 9:23:28 am
 * Author: Zidong Yu
 * Description:
 * C++ lacks elegant ways to split string 
 * This is quite disappointing
 * Here I provide a few options for
 * string splitting.
 */
#include<iostream>
#include<string>
#include <vector>
#include <sstream>
#include <list>
//这两个库有问题？
#include <stdio.h>  //
#include <string.h> //

using namespace std;
//SoundHound Tech View
//不能使用strok()和getline()
//test case:
//  "aa,bb,ccc" => "aa" "bb" "ccc"
//  *    "a123,,X"   => "a123" "" "X"
//  *    "aAa,bBb,"  => "aAa" "bBb"
//
std::list<std::string> split(const std::string& inStr, char sep)
{
    std::list<std::string> res;
    if(inStr=="")   return res;
    if(inStr.find(sep)==std::string::npos) res.push_back(inStr);

    std::string str="";
    if(inStr.find_last_of(sep)!=inStr.size()-1) str=inStr+sep;
    else str=inStr;

    size_t pos=str.find(sep);
    if(pos==std::string::npos) return res;

    while(pos!=std::string::npos)
    {
        res.push_back(str.substr(0,pos));
        //Update pos
        str=str.substr(pos+1);
        pos=str.find(sep);
    }

    return res;
}

std::list<std::string> split_getline(const std::string& inStr, char sep)
{
    std::list<std::string> res;
    std::string temp="";
    // stringstream in(inStr);
    istringstream in(inStr);

    //getline的第一个参数必须是Xstream类型的
    while(std::getline(in, temp, sep))
    {
        res.push_back(temp);
    }

    return res;
}

//strok()
// char * strtok ( char * str, const char * delimiters );
std::list<std::string> split_strok(const std::string& inStr, char sep)
{
    //是strtok而不是strok
    std::list<std::string> res;
    int size=inStr.size();
    char str[size];
    for(size_t i=0;i<size;++i)  str[i]=inStr[i];

    //How to cast string to char* ???
    //左边是C语言的char array，右边是???
    char* res_str=strtok(str ,&sep);
    for(int i=0;i<5;++i) cout<<res_str[i]<<" ";
    cout<<endl;

    //如何确定res_str的大小？貌似不容易


    return res;
}

//Test Stub
int main()
{
    /*<---Test case--->*/
    string test1="aa,bb,ccc";
    string test2="a123,,X";
    string test3="aAa,bBb,";
    char sep=',';

    auto res=split_strok(test1,',');
    for(auto item: res) cout<<"["<<item<<"]"<<" ";
    cout<<endl;
    res=split(test2, sep);
    for(auto item: res) cout<<"["<<item<<"]"<<" ";
    cout<<endl;
    res=split(test3, sep);
    for(auto item: res) cout<<"["<<item<<"]"<<" ";
    cout<<endl;


    return 0;
}