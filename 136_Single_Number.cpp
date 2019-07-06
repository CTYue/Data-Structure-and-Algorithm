/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-02 16:33:26
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-05 23:20:10
 * @Description: To be added.
 * @AC: YES
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class Solution_1 {
public:
    //注意，要求Linear runtime
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    int singleNumber(vector<int>& nums) 
    {
        if(nums.size()<2) return nums[0];
        sort(nums.begin(),nums.end());
        int len=nums.size();
        for(int i=0;i<len-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]=0;
                nums[i+1]=0;
            }
        }
        sort(nums.begin(),nums.end());
        if(nums[len-1]>0)   return nums[len-1];
        else    return nums[0];
    }
};

class Solution_2 {
public: 
    //XOR Solution    
    //注意理解XOR原理
    //XOR Example:
    //2^2=0
    //0^1=1
    //使用XOR, 能屏蔽所有相同的数字，从而找出出现次数仅为1的数字
    //该方法可以推广到所有类似问题。
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    int singleNumber(vector<int>& nums) 
    {
        int res=0;
        for(int i=0;i<nums.size();i++)
            res^=nums[i];
        return res;   
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
        
        int ret = Solution().singleNumber(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}