/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-06 14:48:40
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-06 16:27:47
 * @Description: To be added.
 * @AC:  Yes, faster than 74%, less than 100%.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    //最优可以达到O(n^3)
    //Time Complexity:
    //Space Complexity:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        vector<vector<int>> res;
        if(A.size()==0 || B.size()==0)  return res;
        
        //Check if the multiplication is possible or not
        if(A[0].size()!=B.size())   return res;
        
        //注意理解矩阵的乘法
        res.resize(A.size(), vector<int>(B[0].size(),0));
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)//???注意理解这里
            {
                if(A[i][j]!=0)
                {
                    for(int k=0;k<B[0].size();k++)
                    {
                        if(B[j][k]!=0)  res[i][k]+=A[i][j]*B[j][k];//注意理解这里！
                    }
                }
            }
        }
        
        return res;
    }
};

int main(int argc, char* argv[])
{
    //TODO

    return 1;
}