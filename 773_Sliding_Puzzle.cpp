/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-08 22:16:43
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-08 22:19:19
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    //BFS
    //Time Complexity: 
    //Space Complexity: 
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        int steps=0;
        int m=board.size(), n=board[0].size();
        // unordered_set<vector<vector<int> > > visited;
        //为什么只能用set，而不是unordered_set???
        //注意set和unordered_set的区别！
        set<vector<vector<int> > > visited;

        //没有理解这个queue内部为什么要这样写
        queue<pair<vector<vector<int>>,vector<int>>> queue;
        
        vector<vector<int>> correct={{1,2,3},{4,5,0}};
        //将vector<vector<int>>视为matrix
        vector<vector<int>> directions{{0,-1},{0,1},{1,0},{-1,0}};
 
        //为什么是2和3？？？
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]==0)  queue.push({board, {i,j}});
            }
        }
        
        while(!queue.empty())
        {
            int size=queue.size();
            
            for(int i=0;i<size;i++)
            {
                auto temp=queue.front().first;
                auto zero=queue.front().second;queue.pop();
                
                if(temp==correct) return steps;
                visited.insert(temp);
                
                for(auto d: directions)
                {
                    int x=zero[0]+d[0], y=zero[1]+d[1];
                    //？？？
                    if(x<0 || x>=2 || y<0 || y>=3)  continue;
                    vector<vector<int> > candidate=temp;
                    //为什么要交换?
                    swap(candidate[zero[0]][zero[1]], candidate[x][y]);
                    
                    if(visited.count(candidate))    continue;
                    queue.push({candidate, {x,y}});
                }
            }
           steps++;
        }
        
        return -1;
    }
};


int main(int argc, char* argv[])
{
    //TODO


}