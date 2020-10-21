/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-13 23:22:20
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-13 23:23:19
 * @Description: To be finished.
 */


#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    
    //Dynanmic Programming
    //Time Complexity:
    //Space Complexity:
    //Level: Hard
    int numDecodings(string s) 
    {
        if(s.empty()) return 0;
        
        int len=s.length();
        vector<int> dp(len+1,0);
        dp[0]=1;
        if(s[0]=='*')
            dp[1]=9;
        if(s[0]=='0')
            dp[1]=0;
        else
            dp[1]=1;
        
        int M = 1000000007;//What???
        
        for(int i=1;i<len;i++)
        {
            if(s[i]=='*')
            {
                dp[i+1]=9*dp[i];
                if(s[i-1]=='1')
                
                    
            }

        
        }
        
        return dp[0];
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
        
        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}