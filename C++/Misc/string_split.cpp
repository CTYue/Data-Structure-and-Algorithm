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
#include <typeinfo>
#include<string>
#include <vector>
#include <sstream>
#include <list>

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

    while(std::getline(in, temp, sep))
    {
        res.push_back(temp);
    }

    return res;
}

//strtok()
//char * strtok ( char * str, const char * delimiters );
std::list<std::string> split_strtok(std::string& inStr, char sep, const char* sep_ptr)
{
    std::list<std::string> res;
    char* str=(char*)inStr.c_str();
    //strtok is NOT thread-safe!
    cout<<"sep == "<<sep<<endl;
    cout<<"*sep == "<<*sep_ptr<<endl;
    cout<<"strlen(sep) == "<<strlen(&sep)<<endl;//
    cout<<"strlen(sep_ptr) == "<<strlen(sep_ptr)<<endl;
    char* str_ptr="1234";
    char* test=".";
    cout<<"strlen(str_ptr) == "<<strlen(str_ptr)<<endl;
    cout<<"strlen(test) == "<<strlen(test)<<endl<<endl;

    //注意：当split_strok的第二个参数使用char型时，split结果正确
    //当split_strtok的第二个参数为char*时，split结果错误
    //原因是？？？
    // char* res_str=std::strtok(str, &sep);
    char* res_str=std::strtok(str, sep_ptr);
    
    // res_str=std::strtok(NULL, &sep);
    // cout<<"res_str == "<<res_str<<endl;


    while(res_str!=NULL)
    {
        res.push_back(res_str);
        //pass NULL to make strtok continue tokenizing previous C string we just passed to it.
        //by giving NULL, strtok will continue tokenizing the C string until terminator
        res_str=strtok(NULL, &sep);
    }

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

    //问题：第二个参数为什么不能传指针？
    auto res=split_strtok(test1, sep, &sep);

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