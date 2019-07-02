/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-02 15:53:57
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-02 15:56:00
 * @Description: To be added.
 * @AC: YES
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:

    //Sliding window
    //Time complexity: O(n)
    //Space Complexity: O(n)
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty())
            return 0;
        unordered_set<char> seen;
        int len=s.length();
        int max=0;
        int left=0,right=0;
        
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
                    seen.erase(s[left]);//
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
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}