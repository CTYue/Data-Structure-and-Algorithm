/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-09 16:54:42
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-09 16:56:04
 * @Description: To be added.
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) 
    {
        if(matrix.size()==0)    return;
        int m=matrix.size(), n=matrix[0].size();
        bool isCol=false;//第一行或第一列中的任一一个元素为0，都会导致matrix[0][0]为0，这时候，我们需要一个单独的变量用于区分是第一行还是第一列中存在某个元素为0
        for(int i=0;i<m;++i)
        {
            //To mark the first column
            //matrix[0][0] is for the first row
            if(matrix[i][0]==0) isCol=true;
            
            //
            for(int j=1;j<n;++j)
            {
                //Set the first elements of corresponding row and column to 0
                if(matrix[i][j]==0) matrix[i][0]=matrix[0][j]=0;//将该元素对应的行和列的第一个元素设为0
            }
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    //
                    cout<<"("<<i<<", "<<j<<")"<<endl;
                    matrix[i][j]=0;//更新该元素所在的行和列的所有元素为0
                }
            }
        }
        
        //判断是否将第一行设为0
        if(matrix[0][0]==0)
        {
            for(int j=0;j<n;++j)  matrix[0][j]=0;
        }
     
        //判断是否将第一列设为0
        if(isCol)
        {
            for(int i=0;i<m;++i)  matrix[i][0]=0;   
        }
    }
};

int main(int argc, char** argv)
{
    //TODO

    return 1;
}