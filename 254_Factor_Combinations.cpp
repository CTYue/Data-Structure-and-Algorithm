/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-18 03:24:08
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-20 17:28:55
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    //DFS
    //Time Complexity: O(?)
    //Space Complexity: O(?)
    vector<vector<int>> res;
    vector<vector<int>> getFactors(int n) 
    {
        vector<int> vec;
        dfs(n, 2, vec);
        return res;  
    }
    
    void dfs(int n, int factor, vector<int> vec)
    {
        if(factor>sqrt(n)) return;
        
        dfs(n,factor+1,vec);
        
        if(n%factor==0)
        {
            vec.push_back(factor);
            
            dfs(n/factor, factor,vec);

            vec.push_back(n/factor);
            res.push_back(vec);
        }
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> input;
    
    
    return 1;
}