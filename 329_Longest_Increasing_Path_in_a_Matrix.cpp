/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-07 15:42:51
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-07 15:45:59
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    //BFS+Topologial Sort
    vector<vector<int>> directions={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        //这次是matrix了
        //多个一样的值，怎么算node？
        if(matrix.size()==0)    return 0;
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int> > indegree(m, vector<int>(n,0));
        queue<vector<int> > queue;
        
        for(int row=0;row<m;row++)
        {
            for(int col=0;col<n;col++)
            {
                for(int i=0;i<4;i++)
                {   
                    int nextRow=row+directions[i][0];
                    int nextCol=col+directions[i][1];
                    //Check if BFS is outbounded or not
                    if(nextRow>=0 && nextRow<m && nextCol>=0 && nextCol<n && matrix[row][col]>matrix[nextRow][nextCol])
                        indegree[row][col]++;
                }
                if(indegree[row][col]==0) queue.push({row, col});//存储start point
            }
        }
        
        int len=0;
        while(!queue.empty())
        {
            //为什么要使用queue的size？
            int size=queue.size();
            while(size-->0)
            {
                auto temp=queue.front();
                queue.pop();
                int row=temp[0], col=temp[1];
                for(int i=0;i<4;i++)
                {
                    int nextRow=row+directions[i][0];
                    int nextCol=col+directions[i][1];
                    //判断bfs的时候是否越界
                    if(nextRow>=0 && nextRow<m && nextCol>=0 && nextCol<n && matrix[row][col]<matrix[nextRow][nextCol])
                    {
                        //这里如何改写?
                        if(--indegree[nextRow][nextCol]==0)
                            queue.push({nextRow, nextCol});
                    }
                }
            }
            len++;
        }
        return len;
    }
};


int main(int argc, char* argv[])
{
    
    return 1;
}