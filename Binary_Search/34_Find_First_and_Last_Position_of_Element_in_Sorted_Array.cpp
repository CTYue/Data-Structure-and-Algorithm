/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-25 16:32:12
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-25 16:33:56
 * @Description: To be added.
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.size()==0)   return {-1,-1};
        int left=0,right=nums.size()-1;
        vector<int> res={-1,-1};
        int mid=0;

        //搜索两次，分别找左和右
        //找左
        while(left<right)
        {
            mid=left+(right-left)/2;
            
            //如果mid小于target，将下界确定为mid+1    
            if(nums[mid]<target)   left=mid+1;
            else right=mid;//如果nums[mid]>=target, 此时将右边界确定为mid
            
            cout<<"Find left: "<<endl;
            cout<<"left == "<<left<<endl;
            cout<<"right == "<<right<<endl;
        }
        
        if(nums[left]!=target)  return res;
        else res[0]=left;//
        
        right=nums.size()-1;
        
        while(left<right)
        {
            //这里很关键！
            mid=left+(right-left)/2+1;
            
            //如果mid大于target，那么将上边界确定为mid-1
            if(nums[mid]>target)   right=mid-1;//如果只有一个target，那么此时right和left重合
            //如果mid小于等于target，那么确定下界为mid
            else left=mid;//下界往上移
                            
            cout<<"Find right: "<<endl;
            cout<<"left == "<<left<<endl;
            cout<<"right == "<<right<<endl;
        }
        res[1]=right;
        
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

int stringToInteger(string input) {
    return stoi(input);
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
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}