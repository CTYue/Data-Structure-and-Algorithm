/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-13 23:42:38
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-14 16:04:07
 * @Description: 尚未理解！
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //Dynanmic Programming
    //Time Complexity:
    //Space Complexity:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        
        if(nums.size()==1)
            return nums[0];
        
        int len=nums.size();
        int pre_Max=0;
        int cur_Max=0;
        
         for(int i=0;i<len;i++)
        {
            int temp=cur_Max;//到当前的最大值
            std::cout << "temp = " << temp << std::endl;
            //pre_Max: f(k-2)
            //cur_Max: f(k-1)
            //cur_Max=max(f(k-2)+nums[i],f(k-1))
            cur_Max=std::max(pre_Max+nums[i],cur_Max);
            pre_Max=temp;//到前一个的最大值
            std::cout << "pre_Max = " << pre_Max << std::endl;
            std::cout << "cur_Max = " << cur_Max << std::endl;
        }
        
        return cur_Max;
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