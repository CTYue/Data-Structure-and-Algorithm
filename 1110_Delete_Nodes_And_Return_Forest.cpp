/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-08 22:13:07
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-09 13:21:29
 * @Description: To be added.
 * @AC: 
 * @Related: 450@Leetcode
 * @AC: YES(faster than 92.36%, less than 100%)
 */

#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> res;
    unordered_set<int> set;
    //Recursion Approach
    //这道题不需要用sub-node的值替换被删除的node
    //该题不同于450
    //Pre-order Traversal
    //Time Complexity: ???
    //Space Complexity: O(n)
    TreeNode* helper(TreeNode* root, bool isRoot) 
    {
        if(root==nullptr) return nullptr;
        bool tobeDeleted;
        
        if(set.find(root->val)!=set.end())
            tobeDeleted=true;
        else 
            tobeDeleted=false;
        
        //若root不会被删除，则push_back到结果中.
        if(isRoot && !tobeDeleted)
            res.push_back(root);//
        //Pre-order, 先root，再left，最后right
        root->left=helper(root->left,tobeDeleted);
        root->right=helper(root->right,tobeDeleted);
        
        //若该node应被删除，则返回nullptr
        if(tobeDeleted==true) 
            return nullptr;
        //反之返回root
        else 
            return root;
    }    


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        if(root==nullptr)
            return res;
        
        for(auto key:to_delete)
            set.insert(key);
        
        helper(root,true);
        
        return res;
    }    
};

int main(int argc, char* argv[])
{
    //TODO

}