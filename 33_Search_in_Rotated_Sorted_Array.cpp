/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-10 18:45:32
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-13 00:16:12
 * @Description: To be added.
 * @AC: Yes: Faster than 11%, less than 80%
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    //No duplicate
    //Ascending Order
    //Time Complexity: O(logN)
    //Space Complexity: O(1)
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==0)  return -1;
        int left=0,right=nums.size()-1;
        int mid=0;
        //Handle corner case
        //when only one item in the array
        if(left==right && nums[left]!=target) return -1;
        
        while(left<=right)
        {
            cout << "left = " << left << endl;
            cout << "right = " << right << endl;
            cout << "mid = " << mid << endl;
            mid=(left+right)/2;
            if(nums[mid]==target)   return mid;
            //mid到right有序
            //考虑右侧sub-array
            if(nums[mid]<nums[right])
            {
                if(target>nums[mid] && target<=nums[right])  left=mid+1;
                else right=mid-1;
            }
            //mid到right是无序的(非ascending)
            //考虑左侧sub-array
            else
            {
                if(target>=nums[left] && target<=nums[mid])   right=mid-1;
                else left=mid+1;
            }
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