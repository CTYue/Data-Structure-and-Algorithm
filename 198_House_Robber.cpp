/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-13 23:42:38
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-14 17:12:03
 * @Description: This is a very typical 
 * DP problem. The formula for maximum
 * robbery treasure is Tmax=max(f(k-1),f(k-2)+t[k])
 * In such a methodology, DP solution can be
 * applied, specifically, this problem requires only
 * the maximum value (not the entire path), O(1) space
 * complexity can be implemented.
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    //题意：找到不连续元素的最大和
    //Dynanmic Programming
    //Time Complexity: O(n)
    //Space Complexity: O(1)(pre_Max and cur_Max)
    //Space Complexity: O(n)(vector<int> res(len,0))
    //
    int rob(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        
        if(nums.size()==1)
            return nums[0];
        
        int len=nums.size();
        // int pre_Max=0;
        // int cur_Max=0;
        vector<int> res(len,0);
        
        // for(int i=0;i<len;i++)
        // {
        //     //到当前的最大值
        //     int temp=cur_Max;
        //     std::cout << "temp = " << temp << std::endl;
        //     //pre_Max: f(k-2)
        //     //cur_Max: f(k-1)
        //     //cur_Max=max(f(k-2)+nums[i],f(k-1))
        //     cur_Max=std::max(pre_Max+nums[i],cur_Max);
        //     pre_Max=temp;//到前一个的最大值
        //     std::cout << "pre_Max = " << pre_Max << std::endl;
        //     std::cout << "cur_Max = " << cur_Max << std::endl;
        // }
        

        for(int i=0;i<len;i++)
        {
            if(i==0)
                res[i]=nums[0];
            
            if(i==1)
                res[i]=std::max(nums[i-1],nums[i]);
                
            if(i>=2)
            {
                std::cout << "res[i-1] = " << res[i-1] << std::endl;
                std::cout << "res[i-2] = " << res[i-2] << std::endl;
                res[i]=std::max(res[i-1],res[i-2]+nums[i]);
            }
        }
        
        std::cout << "res[len] = " << res[len-1] << std::endl;
        
        return res[len-1];
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
        
        int ret = Solution().rob(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}