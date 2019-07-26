/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-12 18:56:18
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-26 00:17:05
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //Dynanmic Programming Approach
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    int numDecodings(string s) 
    {
        if(s.empty() || s[0]=='0')
            return 0;
        if(s.length()==1)
            return 1;
        
        int len=s.length();
        vector<int> dp(len+1,0);
        dp[0]=1;
        if(s[0]!='0')
            dp[1]=1;
        else  
            dp[1]=0;
        
        //题意：输入的字符串中，每两个char
        //即有可能代表一个字母，也有可能代表两个字母
        //求总共有多少种可以输出的字母数
        for(int i=2;i<=len;i++)
        {
            //读取第i-1个char
            int first=stoi(s.substr(i-1,1));
            std::cout << "i = " << i << std::endl;
            // std::cout << "s[i] = " << s[i] << std::endl;
            // std::cout << "first = " << first << std::endl;
            
            //stoi: string to integer
            //读取从i-2开始的2个char
            int second=stoi(s.substr(i-2,2));
            
            if(first>=1 && first<=9)
                dp[i]+=dp[i-1];

            if(second>=10 && second<=26)
                dp[i]+=dp[i-2];
        
            std::cout << "dp[len] = " << dp[len] << std::endl;
        }

        return dp[len];
    }
};

class Solution_2
{
public:
    //DFS Solution
    //方法正确，但input的字符串长度不能超过30!
    //原因是
    //Cannot pass "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948"
    int numDecodings(string s) 
    {
        if(s.length()==0)   return 0;
        return dfs(s, s.length()-1);
    }
    
    int dfs(string s, int end)
    {
        //Handle length 1
        if(end==0)
        {
            if(s[end]!='0') return 1;
            else return 0;
        }
        
        //Handle length 2
        if(end==1)
        {
            int ways=0;
            if(s[end-1]=='0')   return 0;
            if(s[end]!='0') ways++;
            
            int num=(s[end-1]-'0')*10+s[end]-'0';//处理两位数的情况
            std::cout << "num = " << num << std::endl;
            if(num<=26) ways++;
            return ways;
        }
        
         int ways=0;
         //
         if(s[end]!='0')  ways+=dfs(s, end-1);
        
         //从后往前
         int num=(s[end-1]-'0')*10+(s[end]-'0');
         if(s[end-1]!='0' && num<=26)   ways+=dfs(s,end-2);
         return ways;
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
    // string line;
    // while (getline(cin, line)) {
    //     string s = stringToString(line);
        
    //     int ret = Solution().numDecodings(s);

    //     string out = to_string(ret);
    //     cout << out << endl;
    // }

    // string test="4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";
    string test="111111111111111111111111111111";
    std::cout << "test.length() = " << test.length() << std::endl;

    return 0;
}