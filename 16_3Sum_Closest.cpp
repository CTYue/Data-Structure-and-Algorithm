/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-21 00:41:14
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-21 00:44:09
 * @Description: 
 * Given an array nums of n integers and an integer target, 
 * find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * Example:
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        if(nums.size()<3)   return 0;
                
        int res=nums[0]+nums[1]+nums[2];
        
        //Ascending order
        std::sort(nums.begin(), nums.end(), less<int>());
        
        for(int i=0;i<nums.size()-2;i++)
        {        
            int front=i+1, back=nums.size()-1;
            
            while(front<back)
            {
                int sum=nums[i]+nums[front]+nums[back];
                
                if(sum>target) back--;
                
                if(sum<target) front++;
                
                if(sum==target) {res=sum;break;}
                
                //Update sum to the most closet one
                if(abs(sum-target)<abs(res-target)) res=sum;
            }
        }
        
        return res;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}