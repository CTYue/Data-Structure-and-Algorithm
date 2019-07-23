/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-18 16:55:55
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-21 18:03:42
 * @Description: To be added.
 * @AC: Solution_1: Yes
 *      Solution_2: Yes
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution_1 {
public:
    //二分法(Dichotomy)
    //Recursion
    //Time Complexity: O(logN)
    //如果nums中已有这个数字，则返回该数字的第一个index
    //否则，则插入到其应所在的位置。
    int searchInsert(vector<int>& nums, int target) 
    {                
        return recursion(nums,0,nums.size()-1,target);
    }
    
private:
    int recursion(vector<int>& nums,int start, int end, int target)
    {
        if(start>end)   return start;
        
        int mid=start+(end-start)/2;//To avoid int overflow
        
        if(target>nums[mid])
            return  recursion(nums, mid+1, end, target);
        
        if(target<nums[(start+end)/2])
            return  recursion(nums, start, mid-1, target);
        
        return mid;
    }
};

class Solution_2 {
public:
    //Dichotomy(Iteration)
    //Time Complexity: O(logN)
    //Space Complexity: O(1)
    int searchInsert(vector<int>& nums, int target) 
    {
        if(nums.size()==0)  return 0;
        int len=nums.size();
        int start=0, end=len-1;
        int mid=0;
        
        while(start<=end)
        {   
            mid=start+(end-start)/2;//To avoid int overflow
            if(target>nums[mid])    start=mid+1;
            else if(target<nums[mid])    end=mid-1;
            else break;
        }
        
        //考虑头插和尾插的情况
        if(start>end)   return start;
        
        return mid;
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
    // string line;
    // while (getline(cin, line)) {
    //     vector<int> nums = stringToIntegerVector(line);
    //     getline(cin, line);
    //     int target = stringToInteger(line);
        
    //     int ret = Solution_1().searchInsert(nums, target);

    //     string out = to_string(ret);
    //     cout << out << endl;
    // }
    
    char *nums=new char[100];
    std::cout << "sizeof(nums) = " << sizeof(nums) << std::endl;
    std::cout << "strlen(nums) = " << strlen(nums) << std::endl;

    return 0;
}