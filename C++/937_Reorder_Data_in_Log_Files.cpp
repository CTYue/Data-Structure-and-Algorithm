/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-01-31 23:01:16
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-31 23:10:26
 * @Description: To be added
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        if(logs.size()<=1)  return logs;
        
        vector<string> res;
        vector<pair<string, string> > letters;
        vector<string> numbers;
        //这里最好不要用unordered_map，因为hashmap无法traverse，无法按照key_value排序?
        // unordered_map<string, string> map;//unordered_map和map的区别还没复习呢！
        
        for(auto str: logs)
        {
            //C++如何分割string？
            istringstream ss(str);
            string temp;
            getline(ss, temp, ' ');
            int pos=temp.length();
            // cout<<"temp == "<<temp<<endl;
            // cout<<"str[pos+1] == "<<str[pos+1]<<endl;
            if(isalpha(str[pos+1]))   letters.push_back({temp, str.substr(pos+1)});
            else numbers.push_back(str);
        }
        
        //lambda表达式再看一下
        std::sort(letters.begin(), letters.end(), [](auto& a, auto& b)
                  {
                       // 比较的规则，题目已经说清楚了。先比较logs，如果tie的话再比较identifier
                      return a.second==b.second?a.first<b.first : a.second<b.second;
                  }
                 );
        
        for(auto p: letters) res.push_back(p.first+" "+p.second);
        for(auto n: numbers) res.push_back(n);
        
        return res;
    }
};

int main(int argc, char** argv)
{
    //TODO
    return 1;
}