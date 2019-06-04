/*
 * Filename: /Users/yuzidong/Code/Data-Structure-and-Algorithm/49_Group_Anagrams.cpp
 * Path: /Users/yuzidong/Code/Data-Structure-and-Algorithm
 * Created Date: Friday, May 31st 2019, 8:41:34 pm
 * Author: yuzidong
 * 
 * Copyright (c) 2019 Your Company
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        //All characters will be in lower case.
        //Time complexity: ???
        //Space complexity: ???
        vector<vector<string>> res;
        std::hash<char> hash;
        if(strs.size()==0)  return res;
        if(strs.size()==1)  
        {
            res.push_back(strs);
            return res;
        }
        
        unordered_map<string,vector<string>> map={};
        int i=0;
        
        for(string str:strs)
        {
            int count=0;
            string sorted_str=str;
            
            // sort(sorted_str.begin(),sorted_str.end());
            
            sorted_str=sort_by_count(str);//You can also use std::sort, with even better performance.
            // std::cout << "str: " << str << ": " << count << std::endl;
            
            if(map.find(sorted_str)!=map.end())
            {
                // std::cout << "str: " << str << ": " << count << std::endl;                                
                map[sorted_str].push_back(str);            
            }
            
            //If similar str is not in the map
            else
            {
                vector<string> temp={};
                temp.push_back(str);
                map.insert(std::make_pair(sorted_str,temp));
            }
        }
        
        unordered_map<string,vector<string>>::iterator it;
        for(it=map.begin();it!=map.end();it++)
        {
            std::cout << "it->first = " << it->first << std::endl;
            for(string item:it->second)
                std::cout <<"  it->second = "<< item << std::endl;
            
            res.push_back(it->second);
        }
        
        return res;
    }
    
    string sort_by_count(string str)
    {
        int count[26]={0};
        for(char ch : str)
            count[ch -'a']++;
        
        string t;
        for(int i=0;i<26;i++)
            t+=string(count[i],i+'a');
        
        return t;
    }
};


int main(int argc, char* argv[])
{
    if(argc<1) return 1;

    vector<string> input;
    




}