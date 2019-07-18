#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    //二分法
    //递归
    //
    int searchInsert(vector<int>& nums, int target) 
    {        
        std::cout << "nums.size()-1 = " << nums.size()-1 << std::endl;
        
        return recursion(nums,0,nums.size()-1,target);
    }
    
private:
    int recursion(vector<int>& nums,int start, int end, int target)
    {
        std::cout << "start = " << start << std::endl;
        std::cout << "end = " << end << std::endl;
        
        if(start>end)   return -1;
        
        int mid=(start+end)/2;
        std::cout << "mid = " << mid << std::endl;

        if(target==nums[mid])   return mid;
        
        if(target>nums[mid])
            return recursion(nums, mid+1, end, target);
        
        return   recursion(nums, start, mid-1, target);
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
        
        int ret = Solution().searchInsert(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}