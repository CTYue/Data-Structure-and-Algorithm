/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-10 13:22:42
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-11 14:11:43
 * @Description: To be added.
 * @AC: Solution_1: Yes: faster than 98.32%, less than 53.36%
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
    int pathSum(TreeNode* root, int sum)
    {
        int res=0;
        vector<TreeNode*> path;
        dfs(root,sum,0, path, res);
        
        return res;
    }
    
    void dfs(TreeNode* root, int sum, int curSum, vector<TreeNode*>& path, int& res)
    {
        if(root==nullptr)   return;

        curSum+=root->val;//curSum起始为0
        path.push_back(root);
        
        if(curSum==sum) ++res;
        int t=curSum;
        // std::cout << "root->val = " << root->val << std::endl;
        // std::cout << "curSum = " << curSum << std::endl;
        
        for (int i=0; i<path.size()-1; ++i)
        {
            t-=path[i]->val;//为什么要减？,而不是加???
            // std::cout << "path[i]->val = " << path[i]->val << std::endl;
            // std::cout << "t = " << t << std::endl;
            if(t==sum) ++res;
        }
        
        dfs(root->left,sum, curSum, path, res);
        dfs(root->right,sum, curSum, path, res);
        
        //将vector<int> path当做stack使用???
        path.pop_back();
    }
};
int main(int argc, char* argv[])
{
    //TODO


}