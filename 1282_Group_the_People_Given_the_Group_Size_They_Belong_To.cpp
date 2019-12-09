/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-08 21:19:24
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-08 21:22:50
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
// class Solution {
// public:
    
//     vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
//     {
//         vector<vector<int>> res;
//         //意思是：在given vector中的每一个数字，都代表其所在子vec的size，
//         //当这个子vec被装满时，相同的数字要存到另外的子vec中。
//         //子vec中存储的是原数字的index
//         map<int, vector<int>> map;//<number, array of its indexes>
//         int n=groupSizes.size();
        
//         //代码还有问题？
//         for(int i=0;i<n;i++)
//         {
//             int curr=groupSizes[i];
//             vector<int> temp={};
//             if(map.find(groupSizes[i])!=map.end()) temp=map[curr];
            
//             //if key is not in the map
//             else
//             {
//                 temp.push_back(i);
//                 map.insert(pair<int, vector<int>>(curr,temp));
//             }
            
//             //这里有点巧妙
//             if(temp.size()==curr)
//             {
//                 res.push_back(temp);
//                 map.erase(curr);
//             }
//         }
    
//         return res;
//     }
// };


//没理解
class Solution {
public:
    vector<vector<int> > groupThePeople(vector<int>& groupSizes) 
    {
        map<int,vector<int> > group;
        vector<vector<int> > res;
        
        for(int i = 0;i < groupSizes.size(); ++i){
            group[groupSizes[i]].push_back(i);
        }
        for(auto & it : group){
            for(auto curr = it.second.begin(); curr != it.second.end(); curr += it.first){
                res.push_back(vector<int>(curr,curr+it.first));
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    //TODO
    return 1;
}