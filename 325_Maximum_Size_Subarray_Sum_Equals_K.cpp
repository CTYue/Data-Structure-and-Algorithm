/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-04-17 00:40:27
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-04-17 01:09:40
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <unordered_map>

using namespace std;
class Solution_1 {
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

class Solution_2 {
public:
    //O(n) solution
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
        if(nums.size()==0)  return 0;
        unordered_map<int, int> hashmap;
        int sum=0, maxlen=0;
        
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            
            //If we find the first subarry which sums up to k
            if(sum==k)  maxlen=i+1;//Update the max length
            
            //
            if(hashmap.find(sum)==hashmap.end())
                hashmap[sum]=i;
            
            //If we find another subarray which sums up to k (cur_sum-k==pre_sum)
            //Then we update the maximum length
            if(hashmap.find(sum-k)!=hashmap.end())
            {
                maxlen=std::max(maxlen, i-hashmap[sum-k]);
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
        
        int ret = Solution_2().maxSubArrayLen(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}