/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-08 22:13:07
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-09 00:51:48
 * @Description: To be added.
 * @AC: 
 * @Related: 450@Leetcode
 */

#include<iostream>
#include<vector>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> res;
    //和450题很相似
    //Recursion Approach
    TreeNode* remove(TreeNode* root)
    {
        if(root==nullptr) return nullptr;

        
        return root;
    }
    
    //Pre-order Traversal
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        if(root==nullptr)
            return res;
        
        for(auto key:to_delete)
        {
            //TODO
            
        }
        

        return res;
    }
  
};

int main(int argc, char* argv[])
{
    //TODO

}