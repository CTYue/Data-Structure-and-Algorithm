#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //Dynanmic Programming
    //Time Comlexity:O(m*n)
    //Space Complexity:O(1)
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) 
    {
        if(obstacleGrid[0][0]==1)
            return 0;

        //Obstacle is marked as 1
        int m=obstacleGrid.size();//Rows?
        int n=obstacleGrid[0].size();//Columns?
        std::cout << "m = " << m << std::endl;
        std::cout << "n = " << n << std::endl;
        obstacleGrid[0][0]=1;
        
        //Filling values 
        for(int i=1;i<m;i++)
        {
            //Update value
            if(obstacleGrid[i][0]==0 && obstacleGrid[i-1][0]==1)
                obstacleGrid[i][0]=1;
            else
                obstacleGrid[i][0]=0;
        }
        
        for(int i=1;i<n;i++)
        {
            if(obstacleGrid[0][i]==0 && obstacleGrid[0][i-1]==1)
                obstacleGrid[0][i]=1;
            else
                obstacleGrid[0][i]=0;
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                 if(obstacleGrid[i][j]==0)
                 {
                     if(obstacleGrid[i-1][j]>INT_MAX-obstacleGrid[i][j-1])
                        obstacleGrid[i][j]=0;
                     else
                        obstacleGrid[i][j] = obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                 }
                 else
                    obstacleGrid[i][j]=0;   
            }
        }
        
        return (int)obstacleGrid[m-1][n-1];
    }
};


int stringToInteger(string input) {
    return stoi(input);
}

int main(int argc, char* argv[]) {
    string line;
    vector<vector<int> > obstacleGrid;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePathsWithObstacles(obstacleGrid);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}