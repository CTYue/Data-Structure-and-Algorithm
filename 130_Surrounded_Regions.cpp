/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-03 02:14:54
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-03 02:15:28
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    //BFS
    //Time Complexity: 
    //Space Complexity: 
    void solve(vector<vector<char>> &board) 
    {
        if(board.size()==0) return;
        int m=board.size();
        int n=board[0].size();
        
        //处理上下左右边缘
        //左右边缘
        for(int i=0;i<m;i++)
        {
            // std::cout << "(i, 0) = " << i << ", " << 0 << std::endl;
            // std::cout << "(i, n-1) = " << i << ", " << n-1 << std::endl;

            //处理每行的第一个元素
            if(board[i][0]=='O') bfs(board,i,0);
            //处理每行的最后一个元素
            if(board[i][n-1]=='O') bfs(board,i,n-1);
        }
        
        //处理上下边缘
        for(int j=0;j<n;j++)
        {
            // std::cout << "(0, j) = " << 0 << ", " << j << std::endl;
            // std::cout << "(m-1, j) = " << m-1 << ", j" << j << std::endl;

            //处理每列的第一个元素
            if(board[0][j]=='O') bfs(board,0,j);
            //处理每列的最后一个元素
            if(board[m-1][j]=='O') bfs(board, m-1,j);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                std::cout << "(i, j) = " << i << ", " << j << " --> "<< board[i][j] << std::endl;
                //遇到所有O, 均替换为X
                if(board[i][j]=='O') 
                {
                    // std::cout << "(i, j) = " << i << ", " << j << std::endl;
                    board[i][j]='X';
                }
                //将原本位于边缘的O还原
                else if(board[i][j]=='E') 
                    board[i][j]='O';
            }
        }
    }
    
    //负责将所有非边缘的O标记为E
    void bfs(vector<vector<char>>& board, int x, int y)
    {
        int m=board.size(),n=board[0].size();
        queue<std::pair<int, int>> queue;
        
        //注意，这里只能用std::pair, 不能使用vector<int>, 思考下为什么
        queue.push(std::pair<int, int>(x,y));
        board[x][y]='E';
        
        while(!queue.empty())
        {
            auto temp=queue.front();queue.pop();
            // std::cout << "temp[0] = " << temp[0] << " temp[1] = " << temp[1] << std::endl;
            int i=temp.first;int j=temp.second;
            
            if (i != 0 && board[i - 1][j] == 'O')
            {
                std::cout << "i-1 = " << i-1 << " j = " << j << std::endl;
                queue.push(std::pair<int, int>(i - 1, j));
                board[i - 1][j] = 'E'; //extended;
            }
            
            if (i != m - 1 && board[i + 1][j] == 'O')
            {
                std::cout << "i+1 = " << i+1 << " j = " << j << std::endl;
                queue.push(std::pair<int, int>(i + 1, j));
                board[i + 1][j] = 'E'; //extended;
            }
            
            if (j != 0 && board[i][j - 1] == 'O')
            {
                std::cout << "i = " << i << " j-1 = " << j-1 << std::endl;
                queue.push(std::pair<int, int>(i, j - 1));
                board[i][j - 1] = 'E'; //extended;
            }
            
            //当使用queue<vector<int>>时，这里有问题！
            //i=1, j+1=2
            if (j != n - 1 && board[i][j + 1] == 'O')
            {
                std::cout << "i = " << i << " j + 1 = " << j+1 << std::endl;
                queue.push(std::pair<int, int>(i, j + 1));
                board[i][j + 1] = 'E'; //extended;
            }
        }
    }
    
};