/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-04-04 16:33:48
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-04-04 16:38:29
 * @Description: To be added.
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
    //Time Complexity: O(nlogn) ???
    //Space Complexity: O(logn) ???
public:
    int maxSubArray(vector<int> nums) 
    {
        if(nums.size()==0) return INT_MIN;
        if(nums.size()==1) return nums[0];
        
        return helper(nums, 0, nums.size() - 1);
    }
    
    //用的是merge sort的方法
    int crossSum(vector<int> nums, int left, int right, int mid)
    {
        //这里没咋理解
        if(left==right) return nums[left];
        
        int leftSum=INT_MIN,rightSum=INT_MIN;
        int currSum=0;
        
        //Traverse left side
        for(int i=mid;i>=left;--i)
        {
            currSum+=nums[i];
            leftSum=std::max(leftSum, currSum);
        }
        
        currSum=0;
        //Traverse right side
        for(int i=mid+1;i<=right;++i)
        {
            currSum+=nums[i];
            rightSum=std::max(currSum, rightSum);
        }

        return leftSum+rightSum;
    }
    
    int helper(vector<int> nums, int left, int right)
    {
        if(left==right) return nums[left];
        
        int mid=left+(right-left)/2;
        
        //这里的递归再了解下
        int leftSum=helper(nums, left, mid);
        int rightSum=helper(nums, mid+1, right);
        
        int Sum=crossSum(nums, left, right, mid);//C++中，变量和函数不能同名
        
        return std::max(std::max(leftSum, rightSum), Sum);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}