/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-24 00:21:12
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-24 00:22:53
 * @Description: To be added.
 * @AC: Yes
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    vector<vector<int> > highFive(vector<vector<int> >& items) 
    {
        vector<vector<int> > res;
        map<int, vector<int> > map;
        for(auto& v: items) map[v[0]].push_back(v[1]);
        for(auto& [i,v]: map)//[i, v] is a C++ 17 feature, don't use it in interview!
        {
            partial_sort(v.begin(), v.begin()+5, v.end(), greater<int>());//最后一个参数怎么理解？
            res.push_back({i, (v[0] + v[1] + v[2] + v[3] + v[4]) / 5 });
        }
        return res;
    }
};
