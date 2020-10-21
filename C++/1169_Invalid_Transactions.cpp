/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-01-25 03:54:47
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-25 21:17:05
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
        unordered_set<string> set;///make sure there's no duplicate items
        unordered_map<string, vector<vector<string> > > map;//dictionary using name as index
        
        for(string str: transactions)
        {
            istringstream ss(str);
            
            //name, time, amount, city
            vector<string> temp(4);
            
            int i=0;
            while(getline(ss, temp[i++], ','));//第三个参数是char
            
            for(auto s: temp)
                cout<<s<<" ";
            cout<<endl;
            
            if(stoi(temp[2])>1000) set.insert(str);
            
            for(auto v: map[temp[0]])
            {
                if(temp[3]!=v[3] && abs(stoi(temp[1])-stoi(v[1]))<=60)
                {
                    set.insert(str);
                    set.insert(v[0]+","+v[1]+","+v[2]+","+v[3]);
                }
            }
                        
            map[temp[0]].push_back(temp);
        }
        
        vector<string> ans;
        for(string s: set)  ans.push_back(s);
        
        return ans;
    }
};

int main(int argc, char* argv[])
{
//TODO

}