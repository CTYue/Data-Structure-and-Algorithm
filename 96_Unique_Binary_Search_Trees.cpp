/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-05 14:38:19
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-06 17:34:21
 * @Description: Solution(s) for Leetcode #95.
 * DP Approach OK, Recursion Approach failed.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution_1 {
public:

    //Dynamic Programming Approach
    //Time Complexity: O(n^2)
    //Space Complexity: O(n)
    int numTrees(int n) 
    {
        if(n<=2) return n;
        
        std::vector<int> dp(n+1,0);        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;++i)
        {
            for(int j=1;j<=i;++j)
            {
                //Pick j as the root
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};

class Solution_2 {
public:

       //Mathematical Approach
       //Time Complexity:O(n)
       //Space Complexity:O(1)
       //Catalan number General formula:
       //C(n+1)=C(n)*2*(2*n+1)/(n+2)
    int numTrees(int n)
    {
        long int res=1;
        for(int i=0;i<n;++i)
        {
            res=res*2*(2*i+1)/(i+2);
        }
        return (int)res;
    }
};

int stringToInteger(string input) 
{
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution_2().numTrees(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    
    return 0;
}