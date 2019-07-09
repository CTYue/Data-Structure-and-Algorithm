/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-09 14:24:03
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-09 17:04:53
 * @Description: To be added.
 * @AC: 
 *      Solution_1(DFS,Recursion): faster than 96.31%, less than 22.25%
 *      Solution_2(BFS,Iteration): 
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
    //DFS(Recursion)
    //Time Complexity: O(n)
    //Space Complexity: O(n^2)
    vector<vector<int>> res;
    int height(TreeNode* root)
    {
        if(root==nullptr)   return 0;
        return max(height(root->left), height(root->right))+1;
    }
    
    void levelTraversal(TreeNode* root,int level)
    {
        // std::cout << "level = " << level << std::endl;
        if(root==nullptr)   return;
        
        res[level-1].push_back(root->val);
        
        levelTraversal(root->left,level-1);
        levelTraversal(root->right,level-1);
    }
        
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {        
        if(root==nullptr)
            return res;
        int h=height(root);
        
        //注意这里的表达方式
        res.resize(h, vector<int>{});
        levelTraversal(root,h);
        
        return res;
    }
};


class Solution_2
{
public:
    //BFS(Iteration, using Queue)
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(!root)   return res;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty())
        {
            int level=queue.size();
            vector<int> level_res;
            //
            for(int i=0;i<level;i++)
            {
                if(queue.front()->left!=nullptr) queue.push(queue.front()->left);
                if(queue.front()->right!=nullptr) queue.push(queue.front()->right);
                level_res.push_back(queue.front()->val);
                queue.pop();//
            }
            res.push_back(level_res);
        }

        std::reverse(res.begin(),res.end());//不能直接return std::reverse(), 返回的既不是指向res的指针也不是res本身
        return res;
    }
};


int main(int argc, char* argv[])
{
    vector<int> input;



    return 1;
}