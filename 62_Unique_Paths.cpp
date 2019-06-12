/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-10 15:21:31
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-11 21:08:10
 * @Description: Typical Dynanmic Programming Problem.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution_1 {
public:
    //Approach 1
    //Time Complexity: O(n^2)
    //Space Complexity: O(n^2)
    int uniquePaths(int m, int n) 
    {
        std::vector<std::vector<int> > dp(m, vector<int>(n,1));//将所有dp[x][y]均初始化为1
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                // std::cout << "dp[i-1][j] = " << dp[i-1][j] << std::endl;
                // std::cout << "dp[i][j-1] = " << dp[i][j-1] << std::endl;
                // std::cout << "dp[i][j] = " << dp[i][j] << std::endl;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];//没怎么理解!
            }
        }
        return dp[m-1][n-1];
    }   
};

class Solution_2
{
public:
        //Approach 2
        //Time Complexity: O(n^2)
        //Space Complexity: ???
        int uniquePaths(int m, int n) 
        {
            vector<int> pre(n,1),cur(n,1);
            for(int i=1;i<m;i++)
            {
                for(int j=1;j<n;j++)
                    cur[j]=pre[j]+cur[j-1];
            swap(pre,cur);   
            }
        return pre[n-1];
        } 

};

int stringToInteger(string input) {
    return stoi(input);
}

int main(int argc, char* argv[]) {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}