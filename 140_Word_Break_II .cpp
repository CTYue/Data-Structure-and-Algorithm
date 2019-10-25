/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-24 22:39:51
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-24 22:41:39
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>


using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        // std::cout << "wordDict.size() = " << wordDict.size() << std::endl;
        
        unordered_map<int, vector<string>> memo;
        unordered_set<string> dict;
        for(auto word: wordDict)
        {
            dict.insert(word);
        }
        // std::cout << "dict.size() = " << dict.size() << std::endl;
        
        return dfs(s,0,dict,memo);
    }
    
    vector<string> dfs(string& s, int index, unordered_set<string>& dict, unordered_map<int, vector<string>>& memo)
    {
        vector<string> res={};
        if(index==s.length())   return res;
        if(memo.find(index)!=memo.end())    return memo[index];

        //对每个sub_str进行分词
        for(int i=index;i<s.length();i++)
        {
            // std::cout << "count" << std::endl;
            //注意，这里的s和index也会迭代
            string sub_str=s.substr(index, i-index+1);//
            //sub_str怎么处理?
            
            //如果这个词组没有被处理过，则继续
            if(dict.find(sub_str)==dict.end()) continue;
            
            //如果该词组已经被处理过，则向右递归
            vector<string> right=dfs(s, i+1, dict, memo);
            
            if(i==(s.length()-1))   res.push_back(sub_str);
            else 
            {
                for(string &s2: right)  
                {
                    std::cout << sub_str+" "+s2 << std::endl;
                    res.push_back(sub_str+" "+s2);
                }
            }
        }
        
        // std::cout << "res.size() = " << res.size() << std::endl;
        memo[index]=res;
        return memo[index];
    }  
};


int main(int argc, char* argv[])
{
    //TODO


    return 1;
}