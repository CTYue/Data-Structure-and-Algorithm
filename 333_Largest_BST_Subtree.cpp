/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-19 17:25:45
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-19 17:26:26
 * @Description: To be added.
 * @AC: Yes
 */
#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
 struct TreeNode 
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    //DFS
    //Find the subtree with largest number of nodes
    //需要判断子树是否为BST
    //注意：这里的subtree也包括该树本身
    //例如：[2,1,3] return 3
    bool isBST(TreeNode* root, int& res, int& min, int& max)
    {
        if(root==nullptr)   return true;//若没有子节点，则可视为BST
        
        int left_size=0,right_size=0;
        int left_min=0, left_max=0, right_min=0, right_max=0;
        
        bool isLeft=isBST(root->left, left_size, left_min, left_max);
        bool isRight=isBST(root->right, right_size, right_min, right_max);
        
        if(isLeft&&isRight)
        {
          if( (root->left==nullptr || root->val>left_max ) && ( root->right==nullptr || root->val<right_min ) )
          {
              res=left_size+right_size+1;
              min=root->left?left_min:root->val;
              max=root->right?right_max:root->val;
              return true;
          }
        }
        
        res=std::max(left_size, right_size);
        return false;
    }
    
    int largestBSTSubtree(TreeNode* root) 
    {
        int res=0;
        int max=INT_MIN;
        int min=INT_MAX;
        
        isBST(root, res, min, max);
                
        return res;//Return the size of the tree
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().largestBSTSubtree(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}