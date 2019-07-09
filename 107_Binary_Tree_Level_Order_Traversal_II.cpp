/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-09 14:24:03
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-09 15:31:08
 * @Description: To be added.
 * @AC: 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_1 {
public:
    //BFS
    //Iteration
    //Time Complexity:
    //Space Complexity:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        
        queue<TreeNode*> queue;
        while(queue.empty())
        {  
            //
        }
                
        return res;
    }
};

class Solution_2
{
public:
    //DFS
    //Recursion
    //Time Complexity:
    //Space Complexity:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
            
    }
};

int main(int argc, char* argv[])
{
    //TODO
    
        
}