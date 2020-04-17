/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-04-17 00:40:27
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-04-17 00:41:18
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;
class Solution {
public:
    //O(n^2) Brute force solution
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
        if(nums.size()==0)    return 0;
        int maxlen=0, sum=0;
        
        for(int i=0;i<nums.size();++i)
        {
            sum=nums[i];
            if(sum == k) maxlen = std::max(maxlen, 1);
            
            for(int j=i+1;j<nums.size();++j)
            {
                sum+=nums[j];
                if(sum==k)  maxlen=std::max(maxlen, j-i+1);
            }
        }
        
        return maxlen;
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
        int k = stringToInteger(line);
        
        int ret = Solution().maxSubArrayLen(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}