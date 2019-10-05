/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-09-13 20:46:28
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-05 15:56:21
 * @Description: To be added.
 * @AC: DFS: Yes
 *      BFS: Yes
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution_DFS {
public:
    //DFS
    //用gate去找room
    //Time Complexity: O(M^2*N^2) Worst case: M: number of rows; N: number of columns. 
    //Space Complexity: O(1)
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if(rooms.size()==0) return;
        int m=rooms.size(), n=rooms[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)    
                //这里相当于是用gate去找room, 以gate为原点，同时更新周边的room
                if(rooms[i][j]==0) dfs(rooms, i, j, 0);
        }
    }
    
    void dfs(vector<vector<int>>& rooms, int x, int y, int dist)
    {
        int m=rooms.size(),n=rooms[0].size();
        if(x<0||y<0||x>=m||y>=n||rooms[x][y]<dist||rooms[x][y]<0)   return;
        
        rooms[x][y]=dist++;
        //遍历该gate的上下左右点
        dfs(rooms, x-1, y, dist);
        dfs(rooms, x+1, y, dist);
        dfs(rooms, x, y-1, dist);
        dfs(rooms, x, y+1, dist);
    }
};

class Solution_BFS 
{
public:
    //BFS
    //Time Complexity: O(MN)
    //Space Complexity: O(n)
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    int GATE=0;
    int WALL=-1;
    int INF=INT_MAX;
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if(rooms.size()<=0) return;
        int m=rooms.size(), n=rooms[0].size();
        
        queue<vector<int>> queue;
        
        //gates find rooms
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rooms[i][j]==GATE) queue.push({i,j});
            }
        }

        while(!queue.empty())
        {
            auto temp=queue.front();
            queue.pop();
            
            for(auto d: directions)
            {
                int x=d[0]+temp[0];
                int y=d[1]+temp[1];
                
                //Update empty room
                if(x>=0 && x<m && y>=0 && y<n && rooms[x][y]==INF)
                {
                    rooms[x][y]=rooms[temp[0]][temp[1]]+1;
                    queue.push({x,y});
                }
            }
        }
    }
};
