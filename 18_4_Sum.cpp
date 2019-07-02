/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-01 19:33:27
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-02 15:50:35
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

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
    unordered_map<int, vector<pair<int, int>>> map;
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        set<vector<int>> res_tmp;
        if(nums.empty())    return res;
        int len=nums.size();
        
        if(len<4)   return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            //注意，map保存的是2sum的加数的index
            for(int j=i+1;j<nums.size();j++)
                map[nums[i]+nums[j]].push_back(make_pair(i,j));//Store index
        }
        
        //将4Sum问题转化为2Sum问题，先找到两个加数的和，再找target-2Sum对应的加数
        for(int i=0;i<len-3;i++)
        {
            
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            for(int j=i+1;j<len-2;j++)
            {
                //If target-2Sum is already in map
                int sum=nums[i]+nums[j];
                if(map.find(target-sum)!=map.end())
                {
                    
                    // std::cout << "sum = " << sum << std::endl;
                    // std::cout << "target-sum = " << target-sum << std::endl;
                    for(auto &&x:map[target-sum])
                    {
                        // std::cout << "nums[i] = " << nums[i] << std::endl;
                        // std::cout << "nums[j] = " << nums[j] << std::endl;
                        // std::cout << "x.first = " << x.first << " x.second = " << x.second << std::endl;
                        // std::cout << "nums[x.first] = " << nums[x.first] << std::endl;
                        // std::cout << "nums[x.second] = " << nums[x.second] << std::endl;
                        
                        //如何消除重复的vector<int>????
                        //???
                        vector<int> tmp{nums[i],nums[j],nums[x.first],nums[x.second]};    
                    
                        res_tmp.insert(tmp);
                    }
                }
            }
        }
        for(auto i:res_tmp)
            res.push_back(i);
        
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