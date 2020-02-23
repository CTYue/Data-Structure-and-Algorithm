/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-06 14:48:40
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-02-22 22:08:09
 * @Description: To be added.
 * @AC:  Yes, faster than 74%, less than 100%.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Time Complexity: O(n^3)
//Space Complexity: O(m*n)
//行： Row
//列： Column
//M is the number of rows of A
//N is the number of columns of B
class Solution {
public:
    vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) 
    {
        if(A.size()==0 || B.size()==0) return {};
        if(A[0].size()!=B.size())   return {};
        vector<vector<int> > res(A.size(), vector<int>(B[0].size(),0));
        
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B[0].size();j++)
            {
                for(int k=0;k<A[0].size();k++)
                {
                   res[i][j]+=A[i][k]*B[k][j];
                }
                cout<<"res[i][j] = "<<res[i][j]<<endl;
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