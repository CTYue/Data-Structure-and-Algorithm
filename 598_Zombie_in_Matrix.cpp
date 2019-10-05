/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-05 00:25:26
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-05 13:08:43
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
     //BFS
     //Time Complexity: O(M*N)
     //Space Complexity: O(1)
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    //Zombie: 1
    //People: 0
    //Wall: 2

    int PEOPLE=0;
    int ZOMBIE=1;
    int WALL=2;
    int zombie(vector<vector<int>> &grid) 
    {
       if(grid.size()<=1) return 0;
       int m=grid.size(), n=grid[0].size();
       
       //僵尸找人
       queue<vector<int>> queue;
        
       int people=0;
       for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==ZOMBIE)  queue.push({i, j});//存储zombie的坐标
                if(grid[i][j]==0)   people++;
            }
        }
        
        if(people==0)   return 0;//0 step needed if no human is found
        int days=0;
        
        
        while(!queue.empty())
        {
            days++;
            int size=queue.size();
            
            //遍历每个zombie的临近点
            for(int i=0;i<size;i++)
            {
                auto temp=queue.front();
                queue.pop();
                std::cout << "(x, y): " << temp[0] << ", " << temp[1] << std::endl;
                for(auto d: directions)
                {
                    int x=temp[0]+d[0];
                    int y=temp[1]+d[1];
                    
                    if(0 <= x && x < m && 0 <= y && y < n && grid[x][y] == 0)//If current node is people
                    {
                        grid[x][y]=ZOMBIE;
                        //更新人数
                        people--;
                    
                        //若已不存在人类，则返回全局感染所需的天数.
                        if(people==0)   return days;
                    
                        //将所有的临近点列入队列
                        queue.push({x,y});
                    }
                }
            }
        }
        
            //return -1 if failed to turn all people to zombies
            return -1;
    }
    
};