/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-27 16:00:30
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2019-12-28 23:56:31
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
    //Time Complexity: O(N) N is the number of nodes
    //Space Complexity: O(N) N is the number of nodes
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root==nullptr)   return {};
        queue<TreeNode*> queue;
        queue.push(root);
        int depth=0;
        
        while(!queue.empty())
        {
            TreeNode* cur=nullptr;
            int size=queue.size();
            res.push_back({});
            
            for(int i=0;i<size;i++)
            {
                cur=queue.front();
                queue.pop();
                //
                res[depth].push_back(cur->val);//push_back to each level
                
                //push next level nodes to queue
                if(cur->left!=nullptr)  queue.push(cur->left);
                if(cur->right!=nullptr) queue.push(cur->right);
            }
            
            depth++;
        }
        
        return res;
    }
};

class Solution_DFS {
private: 
    vector<vector<int>> res={};
public:
    //DFS
    //Time Complexity:  O(N)
    //Space Complexity:  O(N)
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==nullptr)   return res;
        // int depth=0;
        dfs(root, 0);
        
        return res;
    }
    
    void dfs(TreeNode* cur, int depth)
    {
        //直到res的size和depth相等才给res追加空间
        if(res.size()==depth)   res.push_back({});
        
        res[depth].push_back(cur->val);
        
        if(cur->left!=nullptr)  dfs(cur->left, depth+1);
        if(cur->right!=nullptr) dfs(cur->right, depth+1);
    }
};




int main(int argc, char** argv)
{
    //TODO

    return 1;
}