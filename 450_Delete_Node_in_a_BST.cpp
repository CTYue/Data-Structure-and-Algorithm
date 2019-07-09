/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-08 22:15:43
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-09 15:32:05
 * @Description: To be added.
 * @AC: Recursion: YES
 */

#include<iostream>

using namespace std;

struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    //Recursive Solution
    //Time Complexity: O(n) (Visit every node for one time)
    //Space Complexity: O(1)???
    //Smallest node after root(right)
    int successor(TreeNode* root)
    {
        root=root->right;
        //因为左边总是小于右边，因此总找最左
        while(root->left!=nullptr)
            root=root->left;
        
        return root->val;
    }
    
    //The largest node before root(left)
    int predecessor(TreeNode* root)
    {
        root=root->left;
        //由于右边总是大于左边，因此总找最右
        while(root->right!=nullptr)
            root=root->right;
        
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==nullptr) return nullptr;

        if(key>root->val)
            root->right=deleteNode(root->right,key);
            
        if(key<root->val)
            root->left=deleteNode(root->left,key);
        
        if(root->val==key)
        {
            //If the node is a leaf
            if(root->right==nullptr && root->left==nullptr)
            {
                root=nullptr;
            }
            //Not leaf, with right child
            else if(root->left==nullptr && root->right!=nullptr)
            {
                root->val=successor(root);
                //删除被替换到root的node
                root->right=deleteNode(root->right, root->val);
            }
            //Not a leaf, with left child
            else if(root->left!=nullptr && root->right==nullptr)
            {
                root->val=predecessor(root);
                //删除被替换到root的node
                root->left=deleteNode(root->left, root->val);
            }
        
            //最复杂的情况，左右儿子都存在
            //这时选择用左边的node替换root
            else
            {
                root->val=predecessor(root);
                root->left=deleteNode(root->left,root->val);
            }
        }
        
        return root;
    }    
};

int main(int argc, char* argv[])
{
    //TODO

}