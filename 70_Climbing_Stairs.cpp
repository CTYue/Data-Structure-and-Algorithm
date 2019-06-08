/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-07 15:52:39
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-08 00:45:26
 * @Description: This is a very good example to 
 * learn recursion, DP and more.
 */

#include <iostream>
using namespace std;

class Solution_1 {
public:
    //Iteration Approach
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    int climbStairs(int n) 
    {
        if(n<=1) return n;

        int f1=1,f2=2;
        if(n==2)
            return f2;
        
        for(int i=3;i<=n;i++)
        {
            int f3=f1+f2;
            //
            f1=f2;
            f2=f3;
        }

        return f2;
    }
};

class Solution_2
{
public:
    //Brute Force (Recursion Approach)
    //Time Complexity: O(2^n) ??? How?
    //Space Complexity: O(n)
    int climbStairs(int n)
    {
        return climb_helper(0, n);
    }
    
    int climb_helper(int i, int n)
    {
        if(i>n) return 0;
        
        if(i==n) return 1;
        
        return climb_helper(i+1,n)+climb_helper(i+2,n);
    }
};

class Solution_3
{
public:
    //Recursion with Memoization
    //Time Complexity: O(n) ??? Why
    //Space Complexity: O(n)
    int climbStairs(int n)
    {
        int memo[n+1];
        return climb_helper(0, n, memo);
    }
    
    int climb_helper(int i, int n, int memo[])
    {
        if(i>n) return 0;
        if(i==n) return 1;
        if(memo[i]>0) return memo[i];
        
        memo[i]=climb_helper(i+1,n,memo)+climb_helper(i+2,n,memo);
        
        return memo[i];
    }
};

class Solution_4
{
public:
    //Dynamic Programming
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    int climbStairs(int n)
    {
        if(n==1) return 1;
        int dp[n+1];
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }

};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution_4().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}