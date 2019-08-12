/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-10 18:45:32
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-12 01:50:03
 * @Description: To be added.
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    //
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==0)  return 0;
        //
        int low=0,high=nums.size()-1;
        
        //先找到最小值
        while(low<high)
        {
            int mid=(low+high)/2;
            //只要遇到rotated的point，low则跳到mid+1的位置
            if(nums[low]>nums[high])    low=mid+1;
            
            else high=mid;
        }
        
        //
        int rotated=low;
        low=0;high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            //这是什么意思？
            //这里需要理解！
            //什么意思
            int real_mid=(mid+rotated)%(nums.size());
            if(nums[real_mid]==target) return real_mid;
            if(nums[real_mid]<target)    low=mid+1;
            else    high=mid-1;
        }
        
        return -1;
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
        
        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}