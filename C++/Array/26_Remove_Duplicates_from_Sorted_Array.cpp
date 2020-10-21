/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-19 02:40:15
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-02-19 20:41:14
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    //C++引用的值不能为NULL！切记！
    //leetcode的input[]，意思就是null
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size()==0)  return 0;
        
        int i=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]!=nums[i])    i++;
            
            nums[i]=nums[j];
        }
    
        return i+1;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().removeDuplicates(nums);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}