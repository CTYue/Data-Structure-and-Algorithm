/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-03-12 23:51:00
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-04 22:22:09
 * @Description: To be added.
 */

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    //Time Complexity: O(n^2)+O(N*logN)(sorting overhead)
    //Space Complexity: O(n) (Worst case)
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        
        if(nums.size()<3)   return res;
        int n=nums.size();
        //Ascending Order
        std::sort(nums.begin(), nums.end(), less<int>());
        for(auto n: nums)   cout<<n<<" ";
        cout<<endl;

        //注意这里的边界，是到n-2为止！
        //因为左边界left=i+1, i<=n-1, 当left==n时，数组越界
        for(int i=0;i<n-2;i++)
        {
            // if(nums[i]==nums[i+1])  continue;//有问题，为什么???
            if(i > 0 && (nums[i] == nums[i-1])) continue; // avoid duplicates
            int left=i+1;
            int right=n-1;
            
            //Two pointers
            //无论targets找没找到，左右pointers都要移动            
            //仅当找到targets的时候，才需要去重
            while(left<right)
            {
                if(nums[left]+nums[right]+nums[i]==0)
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    
                    //对第二个值去重
                    while(left<right && nums[left]==nums[left+1])   left++;
                    //对第三个值去重
                    while(left<right && nums[right]==nums[right-1]) right--;
                    
                    //夹逼边界只能放在这里，放在两个while之上时有问题！
                    //narrow down scope here
                    left++,right--;
                }
                else if(nums[i]+nums[left]+nums[right]<0)   left++;
                else right--;
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
    cout<<endl;
    
    for(auto v: res)
    {
        cout<<"[";
        for(int n: v)   cout<<n<<" ";
        cout<<"]"<<endl;
    }

    return 1;
}