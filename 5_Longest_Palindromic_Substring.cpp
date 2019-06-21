/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-03-12 00:35:32
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-21 14:00:24
 * @Description: To be added.
 */

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution_1
{
public:
    //Non-Dynamic programming approach
    //Brute force
    //Time complexity: O(n^2)
    //Space complexity:O(1)
    //Wrong answer for testcase "ac"
    //102/103 test case passed.
    string longestPalindrome(string s) 
    {
        string res;
        if(s.empty() || s.length()==1)
            return s;
        
        int len=s.length();
        int maxl=1,low,high,start;
        for(int i=0;i<len;i++)
        {
            low=i-1;high=i;
            //Find the longest even length substring,no center needed.
            //偶数
            while(low>=0&&high<=len-1&&s[low]==s[high])
            {
                std::cout << "Even" << std::endl;
                if(high-low+1>maxl)
                {
                    start=low;
                    maxl=high-low+1;
                }
                low--;
                high++;
            }
            //Find the longest odd length palindrome with center point as i
            //奇数
            low=i-1;high=i+1;
            while(low>=0&&high<len&&s[low]==s[high])
            {
                std::cout << "Odd" << std::endl;
                if(high-low+1>maxl)
                {
                    start=low;
                    maxl=high-low+1;
                }
                low--;high++;
            }
        }
        
        for(int i=start;i<start+maxl;i++)
            res+=s[i];
        
        return res;
    }
};


class Solution_2 {
public:
        //DP approach
        //Problem:
        //Input:"babad"
        //Outpit:""
        //Time complexity:
        //Space complexity:
        //Wrong answer
        string longestPalindrome(string s) 
        {
            if(s.empty() || s.length()==1)
                return s;
            int len=s.length();
            int dp[len][len];
            int maxl=1;
            
            for(int i=0;i<len;i++)
                dp[i][i]=1;
            
            int start=0;
            //对于相邻元素, maxl=2的情况
            for(int i=0;i<len;i++)
            {
                if(s[i] == s[i+1])
                {
                    dp[i][i+1]=1;
                    start=i;
                    maxl=2;
                }
            }
            //对于非相邻元素，maxl>2的情况
            for(int k=3;k<=len;k++)
            {
                for(int i=0;i<len-k+1;i++)
                //为什么是i<len-k+1??这里没搞懂！
                {
                    if(dp[i][i+k-2]==1 && s[i] == s[i+k-1] )
                    {
                        dp[i][i+k-1] = 1;
                        if(k>maxl)
                        {
                            start=i;
                            maxl=k;
                        }
                    }
                }
            }
            
            string res;
            for(int i=start;i<start+maxl-1;i++)
            {
                std::cout << "s[i] = " << s[i] << std::endl;
                res+=s[i];
            }
            std::cout << "res = " << res << std::endl;
            
            return res;
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
        
        string ret = Solution_1().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}