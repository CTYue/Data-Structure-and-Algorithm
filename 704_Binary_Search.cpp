
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
class Solution_1 {
public:
    //Recursive Solution
    int search(vector<int>& nums, int target) 
    {
        return recursion(nums, 0, nums.size()-1, target);
    }
    
    int recursion(vector<int>& nums, int start, int end, int target)
    {
        
        int mid=(start+end)/2;
        
        //if not found
        if(start>end)   return -1;
        
        if(target>nums[mid])
            return recursion(nums, mid+1, end, target);
        
        else if(target<nums[mid])
            return recursion(nums, start, mid-1, target);
        
        else
            return mid;
    }
};

class Solution_2 {
public:
    //Iteration Solution
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==0)  return -1;
        int len=nums.size();
        int start=0,end=len-1;
        int mid=0;
        
        while(start<=end)
        {
            mid=(start+end)/2;
            
            if(target>nums[mid])    start=mid+1;
            else if(target<nums[mid])   end=mid-1;
            else break;
        }
        if(start>end)   return -1;
        return mid;
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
        
        int ret = Solution_1().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}