/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-05-31 01:56:42
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-23 00:33:59
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution_1 {
public:
	//Two Pass Hash Map
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
        if(nums.size()==0)  return res;

        unordered_map<int, int> hash_map;
        for(int i=0;i<nums.size();i++)
        {
            hash_map.insert(pair<int,int>(nums[i] ,i));
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int complement=target-nums[i];
            
            if(hash_map.find(complement)!=hash_map.end() && hash_map[complement]!=i )
            {
                res.push_back(i);
                res.push_back(hash_map[complement]);
                return res;
            }
        }
        
        return res;
    }
};

class Solution_2 {
public:
    //Hash map one pass
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        if(nums.size()==0)  return vector<int>{};
        
        unordered_map<int, int> hash_map;
        
        for(int i=0;i<nums.size();i++)
        {
            int complement=target-nums[i];
            
            if(hash_map.find(complement)!=hash_map.end())   return vector<int>{hash_map[complement], i};
            
            hash_map.insert(pair<int, int>(nums[i], i));
        }
        return vector<int>{};
    }
};

int main()
{
	Solution_1 s;
	int a[] = {3,2,4};
	vector<int> nums(a,a+3);
	vector<int> result;
	result = s.twoSum(nums, 6);
	for(int i = 0; i< result.size(); i++)
		cout << result[i] << endl;
	return 0;
}
