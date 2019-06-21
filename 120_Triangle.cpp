/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-20 14:49:23
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-20 20:30:04
 * @Description: To be added.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //DP Solution
    //Time Complexity:  O(n^2)
    //Space Complexity: O(1)
    int minimumTotal(vector<vector<int >>& triangle) 
    {
        int n= triangle.size();
        for(int i=n-2 ; i>=0 ; i--)
        {
        for(int j=0 ; j<triangle[i].size() ; j++ )
            //为什么不与triangle[i-1][j]比较？？
            triangle[i][j] = min(triangle[i][j]+triangle[i+1][j],triangle[i][j]+triangle[i+1][j+1]);
        }
        return triangle[0][0];
    }
};

/* Test Stub */
int main(int argc, char* argv[])
{
    if(argc <1) return 1;
    vector<vector<int >> input={{}};
    
    

    return 1;
}