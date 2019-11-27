/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-24 22:04:04
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-24 23:53:59
 * @Description: 
 * 
 * Given a 2D matrix which contains '1's and '0's
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_dfs {
private:
    int m=0;
    int n=0;
    int count=0;
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        m=grid.size();
        n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid, i, j);//将周边为1的地方全部填充为0，以免重复计算。
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        //只要周边有一个0，则return
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0') return; 
        //将原本为1的地方填0
        grid[i][j]='0';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
};


class Solution_bfs {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.size()==0)  return 0;
        int m=grid.size(), n=grid[0].size();
        int count=0;
        queue<vector<int>> queue;
        
        for(int i=0;i<m;i++)
        {
            //注意，BFS是对每个点做处理，由每个点扩散开来。
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    grid[i][j]='0';
                    queue.push({i,j});
                    while(!queue.empty())
                    {
                        auto temp=queue.front();
                        queue.pop();

                        int x=temp[0];
                        int y=temp[1];
                        //遍历每个点的上下左右
                        if(x+1>=0 && x+1<m && y>=0 && y<n && grid[x+1][y]=='1') 
                        {
                            grid[x+1][y]='0';
                            queue.push({x+1, y});
                        }
                        if(x-1>=0 && x-1<m && y>=0 && y<n && grid[x-1][y]=='1') 
                        {
                            grid[x-1][y]='0';
                            queue.push({x-1, y});
                        }
                        if(x>=0 && x<m && y+1>=0 && y+1<n && grid[x][y+1]=='1') 
                        {
                            grid[x][y+1]='0';
                            queue.push({x, y+1});
                        }
                        if(x>=0 && x<m && y-1>=0 && y-1<n && grid[x][y-1]=='1') 
                        {
                            grid[x][y-1]='0';
                            queue.push({x, y-1});
                        }
                    }

                }
            }
            
        }
        
        return count;
    }
};




int main(int argc, char* argv[])
{

    return 1;
}