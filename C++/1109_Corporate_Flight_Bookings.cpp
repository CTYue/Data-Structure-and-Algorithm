/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-08 11:06:50
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-08 14:27:26
 * @Description: To be added.
 * @AC: NO
 * @Related: 370@Leetcode
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    //这道题有时间复杂度要求！
    //时间复杂度必须小于O(n^2)
    //使用线段树解决???
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        vector<int> res;
        if(n==0) return res;
        if(n==1) 
        {
          res.push_back(bookings[0][2]);
          return res;
        }

        res.resize(n,0);
        for(auto& v: bookings)
        {
            res[v[0]-1]+=v[2];
            // std::cout << "res[v[1]] = " << res[v[1]] << std::endl;
            std::cout << "v[0] = " << v[0] << std::endl;
            // std::cout << "v[1] = " << v[1] << std::endl;
            if(v[1]<n) res[v[1]] -= v[2];
        }
        
        for(int i=1;i<n;i++)
            res[i]+=res[i-1];
        
        return res;
    }
    };


int main(int argc, char* argv[])
{
    //TODO
    

}