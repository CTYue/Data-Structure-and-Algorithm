/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-07 15:52:39
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-07 16:52:46
 * @Description: To be added.
 */

#include <iostream>
using namespace std;

class Solution_1 {
public:
    //Iteration Approach
    //Time Complexity: O(1)
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
    //Time Complexity: O(2^n)
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
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution_1().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}