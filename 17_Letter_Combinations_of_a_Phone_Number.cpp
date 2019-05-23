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
        if(digits.length()==0)
            return res;

        unordered_map<int,string> map;
        map.insert(std::make_pair(2,"abc"));
        map.insert(std::make_pair(3,"def"));
        map.insert(std::make_pair(4,"ghi"));
        map.insert(std::make_pair(5,"jkl"));
        map.insert(std::make_pair(6,"mno"));
        map.insert(std::make_pair(7,"pqrs"));
        map.insert(std::make_pair(8,"tuv"));
        map.insert(std::make_pair(9,"wxyz"));

        string str;
        dfs(map,digits,str,res,0);
        
        return res;
    }
    
    //DFS
    void dfs(unordered_map<int,string> map,string digits, string& str,vector<string>& res, int index)
    {
        if(index==digits.length())
            res.push_back(str);
        
        string s = map[(int)(digits[index]-'0')];

        int len=s.length();
        for(int i=0;i<len;i++)
        {
            // std::cout << "map[(int)(digits[i]-'0')]" << map[(int)(digits[i]-'0')] << std::endl;
            str.push_back(s[i]);
            std::cout << "s[i] = " << s[i] << std::endl;
            //对于每个
            dfs(map,index+1,res,digits,str);   
            str.pop_back();//为什么要pop_back？
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