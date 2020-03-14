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

using namespace std;
//Approach 0:
//Split function written with stringstream provided by C++
std::vector<std::string> split_0(const std::string &source, const char* pattern)
{
    std::vector<std::string> res;
    std::stringstream input(source);
    std::string temp;
    while(getline(input, temp, *pattern))
    {       
        res.push_back(temp);
    }
    return res;
}


//Approach 1:
//Using strok(), this is a C-type solution
std::vector<std::string> split_1(const std::string &str, const string &pattern)
{
    char * strc = new char[strlen(str.c_str())+1];
    strcpy(strc, str.c_str()); 
    std::vector<std::string> res;
    char* tmp = strtok(strc, pattern.c_str());
    while(tmp != nullptr)
    {
        res.push_back(std::string(tmp));
        tmp = strtok(nullptr, pattern.c_str());
    }
    delete[] strc;
    return res;
}

//Approach 2:
std::vector<std::string> split_2(const std::string &str, const std::string &pattern)
{
    std::vector<std::string> res;
    if(str == "")
        return res;

    //Add separator in each sub string
    std::string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while(pos != strs.npos)
    {
        std::string temp = strs.substr(0, pos);
        res.push_back(temp);
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

//Test Stub
int main()
{
    /*<---Test case--->*/
    string records="Zidong,Male,12/27/1992,Syracuse";
    auto res=split_0(records, ",");
    for(auto item: res) cout<<item<<" ";
    cout<<endl;

    vector<int> v1={6,4,3,2,5,8,7,1,9,0};
    // auto fun=[](int& a, int& b){return a>b;};//non-anonymous lambda function

    // sort(v1.begin(), v1.end(), fun);
    sort(v1.begin(), v1.end(), [](const int a, const int b){return a>b;});//anonymous lambda function

    for(auto i: v1) cout<<i<<" ";
    cout<<endl;

    return 0;
}