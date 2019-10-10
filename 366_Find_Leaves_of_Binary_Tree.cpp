/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-10 16:53:11
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-10 16:54:19
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    //DFS
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    int max_depth=0;
    unordered_map<int, vector<int>> level;
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
        vector<vector<int>> res;
        dfs(root);
        for(int i=1;i<=max_depth;i++)
            res.push_back(level[i]);
        
        return res;
    }
    
    //Return depth of each level
    int dfs(TreeNode* root)
    {
        if(root==nullptr)   return 0;
        
        //比较左边和右边的depth
        int d=std::max(dfs(root->left), dfs(root->right))+1;
        std::cout << "d = " << d << std::endl;
        //update max depth
        max_depth=std::max(d,max_depth);
        level[d].push_back(root->val);
        
        return d;
    }
};

//Test Stub
int main(int argc, char* argv[])
{
    //TODO
    return 0;
}