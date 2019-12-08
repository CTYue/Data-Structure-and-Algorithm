/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-08 17:41:33
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-08 17:42:43
 * @Description: To be added.
 */
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        //找到一个divisor，使得vector中每个数除以它得到的sum<=threshold并最接近threshold
        //如何找到这个divisor???
        //Binary Search?
        //每个非整数结果均入到与之最接近的整数
        //如何实现?
        //threshold怎么用？
        //找到一个合理的divisor，使得每个值除以divisor之后的sum与threshold最接近
        int left = 1, right = 1e6, m, sum;//1e6: 1*10^6
        while (left < right) 
        {
            m = (left + right) / 2, sum = 0;//什么意思???
            for (int i : nums)
                sum += (i + m - 1) / m;//什么意思？
            if (sum > threshold)
                left = m + 1;
            else
                right = m;
        }
        
        return left;
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
        int threshold = stringToInteger(line);
        
        int ret = Solution().smallestDivisor(nums, threshold);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}



