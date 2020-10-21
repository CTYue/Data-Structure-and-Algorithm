/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-02 15:53:57
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-04 22:55:30
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

//Time Complexity: O(n^3)
//Space Complexity: O(min(m,n)): n is the length of string while 
//m is the size of the hash set.
class Solution_Brute_Force
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
                if(allUnique(s, i, j)==true) ans=std::max(ans, j-i);
        }
        return ans;
    }

    bool allUnique(string s, int start, int end)
    {
        unordered_set<char> set;
        for(int i=start;i<end;i++)
        {
            char ch=s[i];
            //一旦遇到重复元素，则返回false。
            if(set.find(ch)!=set.end()) return false;
            set.insert(s[i]);
        }
        //如果没有任何重复ch，则返回true
        
        return true;
    } 
};


class Solution_1 {
public:
    //Sliding window with set
    //Time complexity: O(n)
    //Space Complexity: O(min(n,m))
    //n is the length of the string while m is the size of the hash set.
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

class Solution_2 {
public:
    //Sliding Window with hash set
    //Time Complexity: O(2*N)=O(N) in worst case, each element will be visited twice
    //by i and j respectively.
    //Space Complexity: O(min(m,n)) //n is the length of string while m is the size of hash set.
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.length();
        unordered_set<char> set;
        
        int ans=0, i=0,j=0;
        //Sliding window, 左右边界同时向一个方向移动
        //不同于夹逼原理
        //这里可不可以改成left<right???
        while(i<n && j<n)
        {
            cout<<"i: "<<i<<endl;
            cout<<"j: "<<j<<endl;
            
            //如果该char不存在于set中
            if(set.find(s[j])==set.end())
            {
                set.insert(s[j]);j++;
                ans=std::max(ans, j-i);
            }
            //如果该char已存在set中，则在set中删除该char
            else    
            {set.erase(s[i]);i++;}
        }
        
        return ans;
    }
};
class Solution_3 {
public:
    //Array
    //Time Complexity:  O(n)
    //Space Complexity: O(1) Constant space complexity 
    //because space needed is not decided by input string.
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
            //注意，这里要+1
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
        
        // int ret = Solution_1().lengthOfLongestSubstring(s);
        int ret=Solution_Brute_Force().lengthOfLongestSubstring(s);
        string out = to_string(ret);
        cout << out << endl;
    }
    
    return 0;
}