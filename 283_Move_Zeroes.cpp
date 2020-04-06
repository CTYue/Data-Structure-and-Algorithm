/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-04-06 02:58:39
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-04-06 02:59:09
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;
class Solution {
public:
    
    void moveZeroes(vector<int>& nums) 
    {
        if(nums.size()<=1) return;
        int lastNonZero=0;
        
        //要求是in-place解决
        for(size_t i=0;i<nums.size();++i)
        {
            //如果该元素为0，则用新的index，即lastNonZero覆盖，该位置的新元素为下一个不为0的值
            if(nums[i]!=0)
            {
                nums[lastNonZero++]=nums[i];
            }
        }
        
        //后面的元素填0
        for(int i=lastNonZero;i<nums.size();++i)
        {
            nums[i]=0;
        }
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
        
        Solution().moveZeroes(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}