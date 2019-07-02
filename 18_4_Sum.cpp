/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-01 19:33:27
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-02 15:26:20
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_1
{
public:
    //来自Discuss区
    //运用了2分法的思想?
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
                //为什么要设置j>i+1???
                // if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[j]==nums[j-1]) continue;
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
                    res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
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
    //将4SUM分解为2SUM的解法, from GeeksforGeeks
    //Time Complexity:
    //Space Complexity:    
    //map(target-2sum)=vector of all possible pairs
    //hashmap用于存储另外两个2的sum
    unordered_map<int, vector<pair<int,int> > > map;//注意这里的表达方式
    vector<vector<int> > fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int> > res;
        if(nums.empty())    return res;
        int len=nums.size();
        
        if(len<4)   return res;
        for(int i=0;i<len-1;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                //target-sum exists in map
                int sum=nums[i]+nums[j];
                if(map.find(target-sum)!=map.end())
                {
                    auto num_pair=map.find(target-sum);//找到另外两个加数
                    vector<pair<int,int>> v=num_pair->second;//

                    //找出num_pair中的重复项
                    for(int k=0;k<num_pair->second.size();k++)
                    {
                        pair<int,int> it=v[k];
                        if(it.first!=i && it.first!=j && it.second!=i && it.second!=j)
                        // res.push_back(v[k].first,v[k].second);//
                        {
                        // res.push_back();
                        ;
                        }
                    }
                    
                }   
                //If targer-sum doesn't exist in the map
                //
                else
                {
                    //这里有问题!
                    //没理解！
                    map[target-sum].push_back(std::make_pair(nums[i],nums[j]));
                }
                
            }
        }
        return res;
    }
};


int main(int argc, char* argv[])
{
    vector<int> input;
    int target;
    int temp;
    while(std::cin>>temp)
    {
        input.push_back(temp);
        if(cin.get()=='\n') break;
    }
    
    std::cin >> target;

    std::cout << "Input: " << std::endl;
    for(int item:input)
        std::cout << item << " ";
    std::cout << std::endl << "target = " << target << std::endl;

    Solution_1 s;
    vector<vector<int> > res=s.fourSum(input,target);
    std::cout << "res: " << std::endl;
    
    for(auto pair:res)
    {
        for(int num: pair)
            std::cout << num << " ";
        std::cout << std::endl;
    }

    return 1;
}