/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-30 22:47:42
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-31 18:44:32
 * @Description: To be added.
 * @AC: Solution_1: T: O(n) and S: O(n): Faster than 32%, less than 6%
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
class Solution_1 {
public:
    //Hash_set Approach
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    int longestPalindrome(string s) 
    {
        if(s.empty())   return 0;
        
        int count=0;
        unordered_set<char> set;

        for(int i=0;i<s.length();i++)
        {
            //If seen
            if(set.find(s[i])!=set.end())
            {
                set.erase(s[i]);
                count+=2;//前一次+当前次
            }

            //NOT seen
            else
                set.insert(s[i]);
        }
        
        //Handle even length
        if(set.empty())  
        {
            return count;
        }
        
        //Handle odd length
        
        return count+1;
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
        
        int ret = Solution_1().longestPalindrome(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}