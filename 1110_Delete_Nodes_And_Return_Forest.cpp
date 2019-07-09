/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-08 22:13:07
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-08 22:15:28
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
    vector<TreeNode*> res={};
    //和450题很相似
    //Recursion Approach
    TreeNode* remove(TreeNode* root)
    {
        if(root==nullptr) return nullptr;

        //如果右子树存在
        if(root->right!=nullptr)
        {
            TreeNode* left=root->left;
            delete root;//这里的delete是什么意思？
            return left;
        }
        
        //如果右子树不存在
        else
        {
            TreeNode* right=root->right;
            
            while(right->left)
                right=right->left;
            
            //为什么要swap?
            swap(root->val,right->val);
        }
        
        root->left=remove(root->left);
        root->right=remove(root->right);
        
        return root;
    }
    
    //Inorder Traversal
    void Recursion(TreeNode* root, vector<int> to_delete)
    {
        if(root==nullptr) return;
        
        std::cout << "root->val = " << root->val << std::endl;
        
        vector<int>::iterator it=std::find(to_delete.begin(),to_delete.end(),root->val);
        
        //If current node should be deleted
        if(it!=to_delete.end())
        {
            //Remove the node
            root=remove(root);
            res.push_back(nullptr);
        }
        
        //If current node should NOT be deleted
        else 
        {
            // std::cout << "root->val = " << root->val << std::endl;
            res.push_back(root);
        }
        
        if(root!=nullptr)
            Recursion(root->left, to_delete);
        
        if(root!=nullptr)
            Recursion(root->right, to_delete);
}
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        if(root==nullptr)
            return res;
        
        Recursion(root,to_delete);
    
        return res;
    }
  
};

int main(int argc, char* argv[])
{
    //TODO

}