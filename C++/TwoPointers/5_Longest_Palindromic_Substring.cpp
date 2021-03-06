/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-03-12 00:35:32
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-21 23:05:06
 * @Description: Typical DP problem.
 */

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution_1
{
public:
    //Please note: Reverse solution doesn't make sense.
    //Because the longest substring of s and s' is not always a palindrome.
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


class Solution_2
{
public:
        //Brute force
        //Doesn't work for input like "cbbd"(two identical char in the middle)
        string longestPalindrome(string s) 
        {
            int len=s.length();
            string res="";
            if(len<2) return s;
            
            for(int i=0;i<len-1;i++)
            {
                palindrome(s,i,i);//Odd
                palindrome(s,i,i+1);//Even
            }
            // res=s.substr(lo,lo+maxLen);
            // std::cout << "lo = " << lo << std::endl;
            // std::cout << "lo+maxLen = " << lo+maxLen << std::endl;
            // std::cout << "res = " << res << std::endl;
            
            return res;
        }
    
        void palindrome(string s, int start, int end)
        {    
            std::cout <<"==============" << std::endl;
            std::cout << "Input start = " << start << std::endl;
            std::cout << "Input end = " << end <<std::endl; 
            int len=s.length();
            //使用while有问题，start和end都被多extend了一次！
            // while(start>=0 && end<len && s[start]==s[end])
            // {
            //     // std::cout << "s[start] = " << s[start] << std::endl;
            //     // std::cout << "s[end] = " << s[end] << std::endl;
            //     start--;end++;
            // }
            
            //对于input为"abxxj"类型的输入，wrong answer
            for(;start>=0 && end<len;start--,end++)
            {
                if(s[start]!=s[end]) break;
            }
                        
            std::cout << "start = " << start << std::endl;
            std::cout << "end = " << end << std::endl;
            
            //Update max Length
                
            string res=s.substr(start+1,end);
            std::cout << "res = " << res << std::endl;
            std::cout <<"==============" << std::endl;
            
        }
};


class Solution_3 {
public:
      //DP solution
        //Time Complexity: O(n^2)
        //Space Complexity: O(n^2)
        string longestPalindrome(string s) 
        {
            int len=s.length();
            std::cout << "len = " << len << std::endl;
            if(len<2)   return s;
            //单独处理“ba”,"ac"类case
            if(len==2 && s[0]!=s[1]) return s.substr(0,1);
            string res="";
            
            vector<vector<bool> > dp(len,vector<bool>(len,false));
            //i是终点
            for(int i=0;i<len;i++)
            {
                //j是起点
                for(int j=i;j>=0;j--)
                {
                    //只能处理“cbbd”,"bb"类case
                    //不能处理"ac","ab"类case
                    //后面的两个或，若前一个语句为真，则后一个语句不会执行！
                    //距离<2，例如bab
                    //为什么是i-j<2，而不是i-j<3？
                    if(s[i]==s[j] && ( i-j<2 || dp[j+1][i-1]))
                    {
                        dp[j][i]=true;                        
                        //Update substring
                        if(i-j+1>res.length())
                        {
                            // std::cout << "res.length before: " << res.length() << std::endl;
                            res=s.substr(j,i-j+1);
                            // std::cout <<"res.length after: " << res.length() << std::endl;
                        }
                    }
                }
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

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        string s = stringToString(line);
        
        string ret = Solution_3().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 1;
}