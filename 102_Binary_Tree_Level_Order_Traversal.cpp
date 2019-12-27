/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-27 16:00:30
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2019-12-27 16:03:03
 * @Description: To be added.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_BFS {
public:
    //BFS
    //要用到Queue
    //Time Complexity: O(n)
    //Space Complexity: ???
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        vector<int> level;
        
        if(root==nullptr)   return res;
        queue<TreeNode*> queue;//queue用于存储什么?
        queue.push(root);
        int depth=0;
        
        while(!queue.empty())
        {
            int size=queue.size();
            res.push_back({});//每访问一次，则追加一个子集
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=queue.front();
                queue.pop();
                
                res[depth].push_back(cur->val);//
                
                if(cur->left!=nullptr)  queue.push(cur->left);     
                if(cur->right!=nullptr) queue.push(cur->right);
            }
            
            depth++;
        }
        
        return res;
    }
};

int main(int argc, char** argv)
{
    //TODO

    return 1;
}