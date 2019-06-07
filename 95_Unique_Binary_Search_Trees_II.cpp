/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-05 19:11:48
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-06 21:44:23
 * @Description: Recursion solution for leetcode 95.
 */

#include <iostream>
#include <vector>
using namespace std;

class TreeNode 
{
public:
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     int val;
     TreeNode *left;
     TreeNode *right;
};

class Solution {
public:
    
    //Recursion Approach
    //Time Complexity: 
    //Space Complexity: 
    vector<TreeNode*> generateTrees(int n) 
    {   
        vector<TreeNode*> temp={};
        if(n<1) return temp;

        return generateAllTrees(1,n);
    }

    vector<TreeNode*> generateAllTrees(int start, int end)
    {
        vector<TreeNode*> res={};

        if(start>end)
        {
            res.push_back(nullptr);
            return res;
        }

        if(start==end)
        {
            res.push_back(new TreeNode(start));
            return res;
        }

        else
        {
            vector<TreeNode*> left={},right={};
            for(int i=start;i<=end;i++)
            {
                //Make i as the root
                left=generateAllTrees(start,i-1);
                right=generateAllTrees(i+1,end);

                //Link parent and children
                for(TreeNode* l_node:left)
                {
                    for(TreeNode* r_node:right)
                    {
                        TreeNode* root=new TreeNode(i);
                        root->left=l_node;
                        root->right=r_node;
                        res.push_back(root);
                    }
                }
            }
            return res;
        }
    }
};

int main(int argc, char* argv[])
{
    if(argc<1) return 1;
    int n=0;
    std::cout << "Input your number: " << std::endl;
    std::cin >> n;

    Solution s;
    vector<TreeNode*> res=s.generateTrees(n);
    
    //How to print the result?
    for(TreeNode* node:res)
        std::cout << node->val << " ";

    std::cout << std::endl;
}