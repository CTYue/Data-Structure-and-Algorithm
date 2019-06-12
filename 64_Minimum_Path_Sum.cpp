/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-11 23:46:22
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-11 23:47:43
 * @Description: TODO: Testhub.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    
    //Dynanmic Programming
    //Time Complexity: O(m*n)
    //Space Complexity: O(m*n)
    int minPathSum(vector<vector<int> >& grid) 
    {
        int row=grid.size();
        int column=grid[0].size();
        
        // std::cout << "Row = " << row << std::endl;
        // std::cout << "Column = " << column << std::endl;
        vector<vector<int> > res(row,vector<int>(column,0));
     
        for(int i=row-1;i>=0;i--)
        {
            for(int j=column-1;j>=0;j--)
            {
                if(i==row-1 && j!=column-1)//处理边界条件
                    res[i][j]=grid[i][j]+res[i][j+1];
                else if(j==column-1 && i!=row-1)
                    res[i][j]=grid[i][j]+res[i+1][j];
                else if(j!=column-1 && i!=row-1)
                    res[i][j] = grid[i][j] + std::min(res[i+1][j],res[i][j+1]);       
                else
                    res[i][j]=grid[i][j];
            }
            
        }
        return res[0][0];
        }
};


int stringToInteger(string input) {
    return stoi(input);
}

int main(int argc, char* argv[]) {
    string line;
    vector<vector<int> > grid;
    
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().minPathSum(grid);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}