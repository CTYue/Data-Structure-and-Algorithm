/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-18 17:15:30
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-18 17:22:55
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    //Refer to 200. Number of Islands
    //Return the number of separate areas divided by slashes
    //给的是NxN的网格
    //反斜杠用\\表示
    //N*N*4是什么意思???
    int n=0, count=0;
    vector<int> pre;//
    int regionsBySlashes(vector<string>& grid) 
    {
        if(grid.size()<2)  return 1;
        n=grid.size();
        
        count=n*n*4;//每个unit最多可有4个空间
        
        //每个单位正方形，能被'\'和'/'划分成最多4个空间
        //为什么？
        //这里将每个划分出来的子空间视为Union-Find中的一个节点
        //为每一个节点设置parent表，pre[i]指向该点的上一点？？？
        for(int i=0;i<n*n*4;i++)  pre.push_back(i);//every node points itself by default
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                //join：合并分区
                //为什么要合并0与2，1与3？
                //以下两部相当于预先打通整个单元方格
                if(i>0) join(g(i-1, j, 2), g(i,j,0));//
                if(j>0) join(g(i, j-1, 1), g(i,j,3));//没理解
                
                
                //怎么理解?
                //如果没有/，则打通1与0，2与3
                if(grid[i][j]!='/')
                {
                    join(g(i,j,0),g(i,j,1));
                    join(g(i,j,2),g(i,j,3));
                }
                
                //怎么理解?
                //如果第[i][j]个单元方块没有被反斜杠划分开,
                //则合并0，3和1，2
                //如果没有\\，则打通0与3，1与2
                if(grid[i][j]!='\\')
                {
                    join(g(i,j,0),g(i,j,3));
                    join(g(i,j,2),g(i,j,1));
                }
            }
            
        }
        
        return count;
    }
    
    //
    int find(int x)
    {
        if(x!=pre[x]) pre[x]=find(pre[x]);
        
        return pre[x];
    }
    
    //判断x和y是否已经连通
    //若没有连通，则连通x和y
    //x,y可以是空间编号
    void join(int x, int y)
    {
        x=find(x);y=find(y);
        //若x和y不相同，则将i的上一级更新为y
        if(x!=y)
        {
            pre[x]=y;
            count--;//
        }
    }
    
    //这个函数是干嘛用的？
    //没理解！
    //k代表被两个斜杠划分出的空间的编号
    //n代表grid的size
    //i*n+j是什么意思?
    int g(int i, int j, int k)
    {
        return (i*n+j)*4+k;//返回所在空间的编号
    }
    
    
};


int main(int argc, char* argv[])
{
    
    return 1;
}