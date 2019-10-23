/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-02 15:53:57
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-23 19:57:29
 * @Description: 
 * Given a string, find the length of the longest substring without repeating characters.

 * Example 1:
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 

 * Example 2:
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 
 * Example 3:
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution_1 {
public:
    //Sliding window with set
    //Time complexity: O(n)
    //Space Complexity: O(n)
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty())
            return 0;
        unordered_set<char> seen;
        int len=s.length();
        int max=0,left=0,right=0;

        while(right<len)
        {
            //if right is seen
            if(seen.find(s[right])!=seen.end())
            {
                //Update max length
                if(max<right-left)
                    max=right-left;
                
                while(s[left]!=s[right])
                {
                    seen.erase(s[left]);
                    left++;
                }
                left++;
            }
            
            //if right is not seen
            else
            {
                seen.insert(s[right]);
                // right++;
            }
            right++;
        }
        //处理最后一步
        max=std::max(max,right-left);
        return max;
    }
};

//Wrong answer still!
class Solution_2 {
public:
    //Optimized Sliding Window (One Pass)
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty()) return 0;
        int res=0;
        //<char, index>
        unordered_map<char, int> map={};
        int i=0;//left
        for(int j=0;j<s.length();j++)
        {
            //i:left, j:right.
            //如果当前访问的char之前已经出现过，那么将i更新
            if(map.find(s[j])!=map.end()) 
            {   
                // std::cout<<"map contains " << s[j] << endl;
                i=std::max(i, map[s[j]]+1);//为什么要+1?
                // cout<<"i = " << i << endl;
            }

            map.insert(pair<char, int>(s[j], j));

            //update res
            res=std::max(res, j-i+1);
        }
               
        return res;
    }
};

class Solution_3 {
public:
    //Array
    //Time Complexity:  O(n)
    //Space Complexity: O(1)
    int lengthOfLongestSubstring(string s) 
    {
        //将char作为index，出现的次数作为value
        vector<int> arr(256,0);
        int max=0;
        
        //i: right edge
        //j: left edge
        for(int i=0, j=0;i<s.length();i++)
        {
            char ch=s[i];
            arr[ch]++;//出现次数++
            
            //当ch出现的次数大于1，即ch已经出现过
            while(arr[ch]>1)
            {
                --arr[s[j++]];//清零left+1 
            }
            
            //当且仅当i已经出现过，j才右移
            max=std::max(max, i-j+1);
        }
        
        return max;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution_1().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}