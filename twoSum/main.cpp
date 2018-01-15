/*
 * main.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: yuzidong
 */

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)//暴力解法
	{
    		vector<int> result;
    		for(int i = 0; i < nums.size();i++)
    		{
    			for(int j = 0; j < i; j++)
    			    			{
    			    				if(nums[i] + nums[j] == target)
    			    				{
    			    					result.push_back(i);
    			    					result.push_back(j);
    			    					return result;
    			    				}
    			    			}
    		}
    	}
};

int main()
{
	Solution s;
	int a[] = {3,2,4};
	vector<int> nums(a,a+3);
	vector<int> result;
	result = s.twoSum(nums, 6);
	for(int i = 0; i< result.size(); i++)
		cout << result[i] << endl;
	return 0;
}
