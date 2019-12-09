/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-08 17:41:33
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-08 19:57:22
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
    //Time Complexity: O(N*logM) where M=max(nums) ???
    //Space Complexity: O(1)
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        //找到一个divisor，使得vector中每个数除以它得到的sum<=threshold并最接近threshold
        //如何找到这个divisor???
        //Binary Search?
        //每个非整数结果均入到与之最接近的整数
        //找到一个合理的divisor，使得每个值除以divisor之后的sum与threshold最接近
        int left = 1, right = 1e6, divisor=0, sum=0;//1e6: 1*10^6
        while (left < right) 
        {
            //
            divisor = (left + right) / 2, sum = 0;
            for (int n : nums)  sum += (n + divisor - 1) / divisor;//用这种方式使得每个结果都向上取整, 要记住！
            //如果所得sum大于阈值，，此时divisor选得过小，要增加左边界
            //更新左边界
            if (sum > threshold)
                left = divisor + 1;
            //若所得sum小于阈值, ，divisor选得太大，需要减小右边界
            //更新右边界
            else
                right = divisor;//这里处理得很巧妙，还没怎么理解
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



