/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-09-13 20:46:28
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-09-13 22:57:56
 * @Description: To be added.
 * @AC: DFS: Yes
 *      BFS: 
 */

#include <iostream>
#include <vector>

using namespace std;
class Solution_DFS {
public:
    //DFS
    //用gate去找room
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if(rooms.size()==0) return;
        int m=rooms.size(), n=rooms[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)    
                //当遇到gate时？？
                //这里相当于是用gate去找room, 以gate为原点，同时更新周边的room
                if(rooms[i][j]==0) dfs(rooms, i, j, 0);
        }
    }
    
    void dfs(vector<vector<int>>& rooms, int x, int y, int dist)
    {
        int m=rooms.size(),n=rooms[0].size();
        //rooms[x][y]<dist: 如果输入的参数dist大于现在的rooms[x][y]
        //一旦遇到wall, 则return
        //
        if(x<0||y<0||x>=m||y>=n||rooms[x][y]<dist||rooms[x][y]<0)   return;
        
        //这里要注意！！！
        rooms[x][y]=dist++;
        //注意以下递归函数的顺序！
        dfs(rooms, x+1, y, dist);
        dfs(rooms, x-1, y, dist);
        dfs(rooms, x, y+1, dist);
        dfs(rooms, x, y-1, dist);
    }
};

class Solution_BFS
{

    
}