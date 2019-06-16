/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-15 23:55:23
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-16 01:57:37
 * @Description: To be added.
 * @Level: Hard
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        //DP Solution
        //Copied from GeeksForGeeks.com
        //是否可用KMP ???
        //Time Complexity: ???
        //Space Complexity: ???
        int m=str1.length(),n=str2.length();
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        
        // Fill table in bottom up manner 
        for (int i = 0; i <= m; i++) 
        { 
            for (int j = 0; j <= n; j++) 
            { 
                // Below steps follow recurrence relation 
                if(i == 0) 
                    dp[i][j] = j; 
                else if(j == 0) 
                    dp[i][j] = i; 
                else if(str1[i - 1] == str2[j - 1]) 
                    dp[i][j] = 1 + dp[i - 1][j - 1]; 
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]); 
            } 
        } 

            int index = dp[m][n]; 
    string str; 

            int i = m, j = n; 
    while (i > 0 && j > 0) 
    { 
        // If current character in X and Y are same, then 
        // current character is part of shortest supersequence 
        if (str1[i - 1] == str2[j - 1]) 
        { 
            // Put current character in result 
            str.push_back(str1[i - 1]); 
  
            // reduce values of i, j and index 
            i--, j--, index--; 
        } 
  
        // If current character in X and Y are different 
        else if (dp[i - 1][j] > dp[i][j - 1]) 
        { 
            // Put current character of Y in result 
            str.push_back(str2[j - 1]); 
  
            // reduce values of j and index 
            j--, index--; 
        } 
        else
        { 
            // Put current character of X in result 
            str.push_back(str1[i - 1]); 
  
            // reduce values of i and index 
            i--, index--; 
        } 
    } 

    while (i > 0) 
    { 
        str.push_back(str1[i - 1]); 
        i--, index--; 
    } 
        
         while (j > 0) 
    { 
        str.push_back(str2[j - 1]); 
        j--, index--; 
    } 
        
    reverse(str.begin(), str.end()); 
    return str; 
        
    }
};

//Test Stub
int main(int argc, char* argv[])
{
    string str1="",str2="";

    std::cin >> str1;
    std::cin >> str2;
    Solution s;
    string res=s.shortestCommonSupersequence(str1,str2);

    std::cout << "Result: " << res << std::endl;

}