/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-01 19:33:27
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-01 20:53:36
 * @Description: To be added.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //Time Complexity: 
    //Space Complexity: 
    vector<vector<int> > fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int> > res;
        if(nums.empty())    return res;
        int len=nums.size();
        
        if(len<4)   return res;
        sort(nums.begin(),nums.end());
        
                
        
        return res;
    }
};

int main(int argc, char* argv[])
{
    if(argc<1)  return 0;
    string line;
    std::cin >> line;

    return 1;
}