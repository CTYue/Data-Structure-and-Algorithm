/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-13 20:46:47
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-13 21:59:41
 * @Description: To be added.
 * @AC: Yes
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
class Solution {
public:
    //Duplicate exists
    //Time Complexity: 注意这里的时间复杂度
    //Space Complexity: 
    bool search(vector<int>& nums, int target) 
    {
        if(nums.size()==0)  return false;
        int left=0,right=nums.size()-1;int mid=0;
        if(left==right && nums[left]!=target)   return false;
        
        //为什么是<=，而不是<???
        while(left<=right)
        {
            mid=(left+right)/2;
            
            if(nums[mid]==target)   
            {
                std::cout << "nums[mid] = " << nums[mid] << std::endl;
                std::cout << "target = " << target << std::endl;
                return true;
            }
            
            //如果中间大于左边, 则说明左边是ascending order
            if(nums[mid]>nums[left])
            {
                //如果target在left sub-array
                if(nums[mid]>target && nums[left]<=target)  right=mid-1;
                //target位于right sub-array
                else    left=mid+1;
            }
            
            //若left sub-array是descending order
            else if(nums[mid]<nums[left])
            {
                //target位于right sub-array
                if(nums[mid]<target && nums[right]>=target) left=mid+1;
                //target位于 left sub-array
                else    right=mid-1;
            }
            
            //若nums[mid]==nums[left]
            //这一步导致了时间复杂度的变化(由O(nlogn)变成了O(n))???
            else    left++;
        }
        
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        bool ret = Solution().search(nums, target);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}