/*
 * Filename: /Users/yuzidong/Code/Data-Structure-and-Algorithm/17_Letter_Combinations_of_a_Phone_Number.cpp
 * Path: /Users/yuzidong/Code/Data-Structure-and-Algorithm
 * Created Date: Tuesday, May 21st 2019, 8:11:02 pm
 * Author: yuzidong
 * 
 * Copyright (c) 2019 Your Company
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    
    //Approach 1: Recursion
    //DFS
    vector<string> letterCombinations(string digits) 
    {
        //Generate all possible combinations of selected digits
        //Recursion
        vector<string> res;
        if(digits.empty())  return res;        
    
        unordered_map<int,std::string> map;
        map.insert(std::make_pair(2,"abc"));
        map.insert(std::make_pair(3,"def"));
        map.insert(std::make_pair(4,"ghi"));
        map.insert(std::make_pair(5,"jkl"));
        map.insert(std::make_pair(6,"mno"));
        map.insert(std::make_pair(7,"pqrs"));
        map.insert(std::make_pair(8,"tuv"));
        map.insert(std::make_pair(9,"wzyx"));
        
        int index=0;
        string str;
        dfs(map,index,res,digits,str);
        
        return res;
    }
    
    void dfs(unordered_map<int,std::string> map, int index, vector<string>& res, string digits, string& str)
    {
        if(index==digits.length())  
            res.push_back(str);

        string s=map[((int)(digits[index]-'0'))];

        int len=s.length();
        
        //分别取s[i]
        for(int i=0;i<len;i++)
        {
            // std::cout << "map[(int)(digits[i]-'0')]" << map[(int)(digits[i]-'0')] << std::endl;
            str.push_back(s[i]);
            std::cout << "s[i] = " << s[i] << std::endl;
            std::cout << "str = " << str << std::endl;
            //对于每个s[i]，取str[j]
            dfs(map,index+1,res,digits,str);   
            //为什么要pop_back？
            //如果不pop，会发生什么？
            str.pop_back();
        }
    }
};

//Test Stub
int main(int argc, char* argv[])
{
    if(argc<1)
        return 1;
    Solution approach_1;
    string digits;
    std::cout << "Input your digits: " << std::endl;
    std::cin >> digits;
    std::cout << std::endl;

    vector<string> res;
    res = approach_1.letterCombinations(digits);

    for(auto item:res)
        std::cout << item << " ";

    std::cout << std::endl;

    return 0;
}