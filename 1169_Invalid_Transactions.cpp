/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-01-25 03:54:47
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-25 03:56:07
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        // vector<string> res;
        unordered_set<string> res;
        unordered_map<string, vector<vector<string> > > map;
        
        for(auto str: transactions)
        {
            istringstream ss(str);//istringstream用于输入
            
            vector<string> s(4, "");
            int i=0;
            
            while(getline(ss, s[i++], ','));//istream& getline (istream&  is, string& str, char delim); delim是指截断符
            //Find out amount>1000
            if(stoi(s[2])>1000) res.insert(str);
            //Find out time difference >= 60 min and in different cities
            for(auto j:map[s[0]])
            {
                //当前项与map中已有项进行对比
                //在不同的城市且时间相差60分钟以
                if((j[3]!=s[3]) && abs(stoi(j[1])-stoi(s[1]))<=60)   
                {
                    res.insert(j[0]+","+j[1]+","+j[2]+","+j[3]);
                    if(res.count(str)==0) res.insert(str);//为什么要这句代码? 要将不合格的所有项都写进去！                          
                }
            }
            
            map[s[0]].push_back({s[0],s[1],s[2],s[3]});
        }
        
        vector<string> ans;
        for(auto d: res)    ans.push_back(d);
        
        return ans;
    }
    
    
};

int main(int argc, char* argv[])
{
//TODO

}