/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-16 15:35:09
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-16 16:11:34
 * @Description: To be added.
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>


using namespace std;
class Solution {
public:
    //DP
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> dict;
        for(auto word: wordDict)    
        {
            if(dict.find(word)==dict.end()) dict.insert(word);
        }
        
        //标记访问过的sub_str???
        //降低时间复杂度
        //可不可以不用这个hashset?
        unordered_set<int> hashset;
        
        return dfs(s,0,dict,hashset);
    }
    
    bool dfs(string s, int index, unordered_set<string> dict, unordered_set<int>& hashset)
    {
        //Base case
        if(index==s.length())   return true;
        
        //Check Memory
        //如果这个index已被访问过，则返回.
        if(hashset.count(index)>0) return false;
    
        //Recursion
        //每次recursion，需要在index的基础上向右移动
        for(int i=index+1;i<=s.length();i++)
        {
            
            //这里为什么是i-index而不是i-index+1???
            string sub_str=s.substr(index, i-index);
                        
            //如果dict中存在sub_str,则递归
            //否则，则直接返回false
            if(dict.find(sub_str)!=dict.end())
            {
                std::cout << "sub_str = " << sub_str << std::endl;
                if(dfs(s, i, dict, hashset)==true)    return true;
                else hashset.insert(i);
            }
        }
        
        hashset.insert(index);
        return false;
    }
};


int main(int argc, char* argv[])
{
    //Test stub
    return 1;
}