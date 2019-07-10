/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-09 17:11:14
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-10 11:27:58
 * @Description: To be added.
 * @AC: Solution_1(DFS): Yes: faster than 78.27%, less than 72.82%
 *      Solution_2(Iteration):
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_1 {
public:
    //DFS
    //Time Complexity: O(n)
    //Space Complexity: O(n^2)
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res)
    {
        if(root==nullptr) return;
        path.push_back(root->val);
        
        //If reaches to leaf, then push_back current path to result
        if(sum==root->val && root->left==nullptr && root->right==nullptr)
            res.push_back(path);
        
        dfs(root->left, sum-root->val, path, res);
        dfs(root->right, sum-root->val, path, res);
        
        // std::cout << "path.back() = " << path.back() << std::endl;
        //若没找到path，则pop_back
        //这里还没怎么理解！
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> res;
        vector<int> path;
        if(root==nullptr) return res;
        
        dfs(root, sum, path, res);
        return res;
    }
};

class Solution_2
{
public:

    
};

int main(int argc, char* argv[])
{
    //TODO

}