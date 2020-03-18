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
    stringstream in(inStr);

    //
    while(std::getline(in, temp, sep))
    {
        res.push_back(temp);
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

    auto res=split_getline(test1,',');
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