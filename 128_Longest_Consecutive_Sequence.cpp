/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-09-08 23:37:50
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-09-08 23:40:41
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
    //priority_queue
    //优先队列的插入：O(n)
    //优先队列的删除: O(n)
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    int longestConsecutive(vector<int>& nums) 
    {
        
        priority_queue<int,vector<int>, greater<int> > res;
        
        if(nums.size()==0)  return 0;
        if(nums.size()==1)  return 1;
        
        for(int num:nums)   res.push(num);

        int count=1,length=0;
        
        int cur=INT_MIN;//注意这里，不能赋值为0
        while(!res.empty())
        {
            int temp=res.top();
            res.pop();
            
            std::cout << temp << " ";
            
            if(temp==(cur+1))
            {
                // std::cout << "temp==(cur+1)" << std::endl;
                count++;
                length=max(length,count);
            }
            
            else if(temp==cur)
            {
                // std::cout << "temp==cur"<< std::endl;
                continue;
            }
            
            else 
            {
                // std::cout << "else " << std::endl;
                // length=max(length,count);//
                count=1;
            }
            
            cur=temp;
            // std::cout << "count = " << count << std::endl;
            // std::cout << std::endl << "length = " << length << std::endl;
            length=std::max(count,length);//length的计算有问题！
        }
        
        return length;
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
        
        int ret = Solution().longestConsecutive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}