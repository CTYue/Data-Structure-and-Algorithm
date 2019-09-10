/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-09-10 02:58:45
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-09-10 02:58:45
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution {
private: unordered_set<string> set;
         unordered_map<string, string> hash;
public:
    string makeAbbr(string word, int k)
    {
        //if word is shorter than 3???
        // if(word.length()-2-k<=0)//Error
        if(word.length()-2<=k)//Why???
        {
            std::cout << "word = " << word << std::endl; 
            return word;
        }
        
        else
        {
            string abbr=word.substr(0,k)+to_string(word.length()-1-k)+word.back();
            return abbr;
        }
    }
    
    vector<string> wordsAbbreviation(vector<string>& dict) 
    {
        //return the same order as input
        vector<string> res={};
        vector<int> prefix;//干吗用的?
        if(dict.size()==0)  return res;
        
        //为每个单词生成缩写
        for(string word:dict)
        {
            prefix.push_back(1);//Why???
            res.push_back(makeAbbr(word,1));//
        }
        
        for(int i=0;i<dict.size();i++)
        {
            while(true)
            {
                unordered_set<int> set;//记录缩写相同的词的位置
                for(int j=i+1;j<dict.size();j++) 
                    if(res[j]==res[i]) set.insert(j);//记录缩写重复的词所在的位置
                
                if(set.empty()) break;//为什么???
                set.insert(i);//
                // for(int k: set) res[k]=makeAbbr(dict[k], ++prefix[k]);
                for(int k: set) res[k]=makeAbbr(dict[k], ++prefix[k]);
            }
        }
        
        return res;
    }
};