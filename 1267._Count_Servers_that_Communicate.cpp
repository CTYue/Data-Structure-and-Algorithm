/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-24 01:09:59
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-24 01:11:12
 * @Description: To be added.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private: 
    int m=0,n=0;
    int count=0;
public:
    int countServers(vector<vector<int>>& grid) 
    {
        if(grid.size()<=1)  return 0;
        m=grid.size();n=grid[0].size();
        
        vector<int> row(m,0);
        vector<int> col(n,0);

        // cout<<"m = "<<m <<" n = "<<n <<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    row[i]++;col[j]++;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(grid[i][j]==1 && (row[i]>1 || col[j]>1) ) 
                    count++;
            }
        }
        return count;
    }
    
};

int main(int argc, char* argv[])
{
    //TODO
    
    return 1;
}