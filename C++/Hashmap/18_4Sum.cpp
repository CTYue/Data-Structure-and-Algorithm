/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-21 20:25:40
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-22 12:35:39
 * @Description: 
 * 
 * Example:
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * A solution set is:
 * [
 *  [-1,  0, 0, 1],
 *  [-2, -1, 1, 2],
 *  [-2,  0, 0, 2]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //Time Complexity: ???
    //Space Complexity: ???
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if(nums.size()<4)   return {};
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end(), less<int>());
        int n=nums.size();
        
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])   continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                
                int left=j+1, right=n-1;
                
                while(left<right)
                {
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    
                    else
                    {
                        res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while(left<right&&nums[left]==nums[left+1]) left++;
                        while(left<right&&nums[right]==nums[right-1]) right--;
                        
                        left++;right--;
                    }
                }
            }
        }
       
        return res;
    }
};

int main(int argc, char* argv[])
{
    vector<int> input;
    int target=0;
    cout<<"Enter Target: "<<endl;
    cin>>target;

    int temp=0;
    do
    {
        cin>>temp;
        input.push_back(temp);
    }while(getchar()!='\n');

    Solution s1;
    auto res=s1.fourSum(input, target);
    for(auto v: res)
    {
        cout<<"[";
        for(int n: v)   cout<<n<<" ";
        cout<<"]"<<endl;
    }

    return 1;
}