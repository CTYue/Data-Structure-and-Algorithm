/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-21 16:27:19
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-21 16:28:58
 * @Description:
 * Given an array of n integers nums and a target, find the number of index triplets i, j, k 
 * with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
 * 
 * Example:
 * Input: nums = [-2,0,1,3], and target = 2
 * Output: 2 
 * Explanation: Because there are two triplets which sums are less than 2:
    [-2,0,1]
    [-2,0,3]
 */

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        if(nums.size()<3)   return 0;
        //Ascending Order
        std::sort(nums.begin(), nums.end(), less<int>());
        for(int n: nums)    cout<<n<<" ";
        cout<<endl;
        
        int count=0;
        
        for(int i=0;i<nums.size()-2;i++)
        {
            int front=i+1, back=nums.size()-1;
            
            while(front<back)
            {    
                //sum已经小于target，所以只动front
                if(nums[i]+nums[front]+nums[back]<target)  
                {
                    //位于(front, back]的所有值都满足sum<target这一条件，所以count+=back-front;
                    count+=back-front;
                    front++;
                }
                
                else back--;
            }
        }
        
        // cout<<"count = " <<count<<endl;
        return count;
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
        
        int ret = Solution().threeSumSmaller(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}