/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-22 00:10:32
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-26 00:56:47
 * @Description: To be added.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>

using namespace std;
// Definition for a binary tree node.
struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution_1 {
public:
    //Recursive solution
    //Problem in this solution: INT_MAX and INT_MIN are buggy
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    bool isValidBST(TreeNode* root) 
    {
        if(root==nullptr)   return true;
        long min=LONG_MIN,max=LONG_MAX;
        std::cout << "INT_MAX = " << INT_MAX << std::endl;
        std::cout << "INT_MIN = " << INT_MIN << std::endl;
        bool res=isBST(root, min, max);
        
        return res;
    }
    
    bool isBST(TreeNode* root, int min, int max)
    {
        if(root==nullptr) 
            return true;
        
        if(root->val<=min || root->val>=max)
        {
            // std::cout << "root->val = " << root->val << std::endl;
            return false;
        }
        
        return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
    }    
};


class Solution_2
{
public:
    //In-Order traversal
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    bool isValidBST(TreeNode* root) 
    {
        TreeNode* prev = nullptr;
        return validate(root, prev);
    }

    bool validate(TreeNode* node, TreeNode* &prev) 
    {
        if (node == nullptr) 
            return true;
        if (!validate(node->left, prev)) 
            return false;
        
        if (prev != nullptr && prev->val >= node->val) 
            return false;

        prev = node;
        return validate(node->right, prev);
    }
};


class Solution_3
{
public: 
    //Recursion
    //非常巧妙的方法，better performance than
    //above In-order traversal approach
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    bool isValidBST(TreeNode* root) 
    {
        return isValidBST(root, nullptr, nullptr);    
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if(root==nullptr) return true;
        
        if(minNode && root->val<=minNode->val || maxNode && root->val>=maxNode->val)    return false;
        return isValidBST(root->left, minNode,root) && isValidBST(root->right, root ,maxNode);
    }
};


class Solution_4
{
public:
    //Iteration Approach
    //Time Complexity:
    //Space Complexity:
    bool isValidBST(TreeNode* root)
    {
        stack<TreeNode*> stack;
        TreeNode* cur=root;
        TreeNode* pre=nullptr;

        while(!stack.empty() || cur!=nullptr)
        {
            if(cur!=nullptr)
            {
                stack.push(cur);
                cur=cur->left;
            }
            else
            {
                TreeNode* p=stack.top();
                stack.pop();
                if(pre!=nullptr && p->val<=pre->val)
                    return false;
                pre=p;
                cur=p->right;
            }
        }
        return true;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        bool ret = Solution_1().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}