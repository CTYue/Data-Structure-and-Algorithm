/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-20 14:49:23
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-22 00:05:25
 * @Description: Another DP problem.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //DP Solution
    //Time Complexity:  O(n^2)
    //Space Complexity: O(1)
    //No extra memory needed.
    int minimumTotal(vector<vector<int> >& triangle) 
    {
        int n= triangle.size();
        //Bottom-up
        //Minimum sum will be at dp[0][0]
        for(int i=n-2 ; i>=0 ; i--)
        {
            for(int j=0 ; j<triangle[i].size() ; j++ )
            {
                std::cout << "==============" << std::endl;
                std::cout << "i = " << i << std::endl;
                std::cout << "j = " << j << std::endl;
                std::cout << "==============" << std::endl;
                //Update triangle[i][j]
                triangle[i][j] = min(triangle[i][j]+triangle[i+1][j],triangle[i][j]+triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

/* Test Stub */
int main(int argc, char* argv[])
{
    if(argc <1) return 1;
    vector<vector<int> > input={};
    
    
    return 1;
}