/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-05 14:38:19
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-06 01:45:30
 * @Description: Solution(s) for Leetcode #95.
 * DP Approach OK, Recursion Approach failed.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
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


    //Recursion Approach ??? How???
       //Time Complexity:
       //Space Complexity:
    //    int numTrees(int n)
    //    {    
    //        if(n<=2) return n;
            
    //        return numberOfTrees(1,n);
    //    }
    
    //     int numberOfTrees(int start, int end)
    //     {
    //         int num=0;
    //         if(start>=end)
    //             return 0;
            
    //         else
    //         {
    //             num=numberOfTrees(start,);
    //         }
    //         return num;
    //     }


};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().numTrees(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}