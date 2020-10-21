/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-09 20:55:44
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-09 20:56:50
 * @Description: To be added.
 */

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:    
    //这个问题实际上只需要我们imitate one evolution
    //Time Complexity: O(M*N)
    //Space Complexity: O(1)
    
    //Follow up: in-place?
    //Follow up: 能写多线程版的吗？
    //Follow up: infinite board???
        
    //In-place Solution
    void gameOfLife(vector<vector<int> >& board) 
    {
        //Simultaneously
        if(board.size()==0) return;
        
        vector<int> directions={0,-1,1};
        
        int row=board.size(), cols=board[0].size();
        
        cout<<"Original State:"<<endl;
        
        for(auto& v: board)
        {
            for(auto& h:v)  cout<<h<<" ";
            cout<<endl;
        }
        cout<<endl;
        
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<cols;++j)
            {
                    int liveNeighbors=0;

                for(int v=0;v<3;++v)
                {
                    for(int h=0;h<3;++h)
                    {
                        int r=directions[v]+i;
                        int c=directions[h]+j;
                    
                        //Do not count itself
                        //这里有问题！
                        // if( (r>=0 && r<row) && (c>=0 && c<cols) && !(v==0 && h==0 ) && board[r][c]==1)   liveNeighbors++;
                        //这里要注意，需要用绝对值表明
                        if( (r>=0 && r<row) && (c>=0 && c<cols) && !(v==0 && h==0 ) && std::abs(board[r][c])==1)   liveNeighbors++;
                    }
                }
            
            cout<<"("<<i<<", "<<j<<")"<<": "<<liveNeighbors<<endl;    
                
            //Rule 1: [0,1]: die
            //Rule 2: [2,3]: if it's dead, then it's still dead, it's alive, it's still alive until the next evolution
            //that means we don't have to handle it explicitly each time.
            //Rule 3: (3, +INF): die
            //Rule 4: [3]: live

            //Rule 1 & 3
            if(board[i][j]==1 && (liveNeighbors<2 || liveNeighbors>3))  board[i][j]=-1;//-1: dead(was live)   
                
            //Rule 4
            if(board[i][j]==0 && liveNeighbors==3)    board[i][j]=2;//2: live(was dead)
            }
        }
        
        // 0 1 0
        // 0 0 1
        // 1 1 1
        // 0 0 0
        
        // for(auto& v: board)
        // {
        //     for(auto& h:v)  cout<<h<<" ";
        //     cout<<endl;
        // }
        
        //Update the matrix
        for(auto& v: board)
        {
            for(auto& h:v)
            {
                if(h>0) h=1;
                else h=0;
            }
        }
        
    }
};

int main(int argc, char** argv)
{
    //TODO

    return 1;
}