/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-01 19:33:27
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-02 12:38:05
 * @Description: To be added.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution_1
{
public:
    //Time Complexity: O(n^3)
    //Space Complexity: ???
    vector<vector<int> > fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int> > res;
        if(nums.empty())    return res;
        int len=nums.size();
        
        if(len<4)   return res;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<len-3;i++)
        {
            //若找到两个相同的项，则继续
            if(i>0 && nums[i]==nums[i-1]) continue;
            //由于已经排序，所以若右边4项相加大于target，则直接break
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            //若左边4项相加之和小于target，则continue
            if(nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target) continue;
            //左右两边同时收紧一个位置
            for(int j=i+1;j<len-2;j++)
            {
                //没懂!!!
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                //
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                //
                if(nums[i]+nums[j]+nums[len-2]+nums[len-1]<target) continue;
                int left=j+1, right=len-1;
                while(left<right)
                {
                  int sum=nums[left]+nums[right]+nums[i]+nums[j];
                  if(sum<target)  left++;
                  else if(sum>target)  right--;
                  else
                    {
                    res.push_back(vector<int >{nums[i],nums[j],nums[left],nums[right]});
                    do{left++;}while(nums[left]==nums[left-1]&&left<right);
                    do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return res;
    }
};


class Solution_2 {
public:
    //Hashmap Solution
    //Time Complexity:  
    //Space Complexity:  
    vector<vector<int> > fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int> > res;
        if(nums.empty())    return res;
        int len=nums.size();
        
        if(len<4)   return res;
        

                
        
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