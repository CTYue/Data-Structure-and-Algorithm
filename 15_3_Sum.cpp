/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-03-12 23:51:00
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-21 21:49:57
 * @Description: To be added.
 */

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    //Time complexity:O(n^2)+O(n*logn)
    //Space complexity:O(1)???
    vector<vector<int> > threeSum(vector<int>& nums) 
    {   
        //sort函数的时间复杂度是O(N*logN)
        if(nums.size()<3) return {};
        std::sort(nums.begin(), nums.end(), less<int>());
        //less: less在前
        //greater: greater在前
        vector<vector<int>> res;
        
        for(auto n: nums)   cout<<n<<" ";
                
        for(int i=0;i<nums.size()-2;i++)
        {
            int lo=i+1;
            int hi=nums.size()-1;
            
            // Processing duplicates of Number 1
            if (i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                 while(lo<hi)
                {
                    if(nums[i]+nums[lo]+nums[hi]==0)
                    {
                        res.push_back(vector<int>{nums[i],nums[lo],nums[hi]});

                        while(lo<hi&&nums[lo]==nums[lo+1]) lo++;//Processing duplicates of Number 2
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;//Processing duplicates of Number 3

                        lo++;hi--;
                    }
                     else if(nums[i]+nums[lo]+nums[hi]<0)   lo++;
                     else hi--;
                }            
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    vector<int> input;
    int temp=0;
    do
    {
        cin>>temp;
        input.push_back(temp);
    }while(getchar()!='\n');

    Solution s1;
    auto res=s1.threeSum(input);
    for(auto v: res)
    {
        cout<<"[";
        for(int n: v)   cout<<n<<" ";
        cout<<"]"<<endl;
    }

    return 1;
}