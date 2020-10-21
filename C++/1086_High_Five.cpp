/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-24 00:21:12
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-09-07 22:26:22
 * @Description: To be added.
 * @AC: Yes
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) 
    {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> hash;
        
        for(auto item:items)
        {
            if(hash.find(item[0])==hash.end())  hash[item[0]]=vector<int>();
            if(hash[item[0]].size()<5)  hash[item[0]].push_back(item[1]);
            else
            {
                int index=0;
                //这是什么意思?
                for(int i=1;i<5;i++)
                    if(hash[item[0]][i]<hash[item[0]][index])   index=i;
                //这又是什么意思?
                if(hash[item[0]][index]<item[1])    hash[item[0]][index]=item[1];//
            }
        }
        
        for(auto it=hash.begin();it!=hash.end();it++)
        {
            int id=it->first;
            vector<int> scores=it->second;
            double average=0;
            for(int i=0;i<5;i++)    average+=scores[i];
            average/=5.0;
            std::cout << "id = " << id << std::endl;
            std::cout << "average = " << average << std::endl;
            vector<int> student;
            student.push_back(id);
            student.push_back(average);
            res.push_back(student);
        }
        
        std::sort(res.begin(),res.end());
        return res;
    }
};

int main(int argc, char* argv[])
{

    
    return 1;
}