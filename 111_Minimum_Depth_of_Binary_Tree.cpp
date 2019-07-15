/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-15 14:51:20
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-15 16:14:08
 * @Description: To be added.
 * @AC: Solution_1: Yes
 *      Solution_2: 
 */

#include <iostream>
#include <sstream>
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
    //DFS
    //Time Complexity: 
    //Space Complexity: 
    //没怎么理解！
    int minDepth(TreeNode* root) 
    {
        if(root==nullptr)   return 0;
        if(root->left==nullptr && root->right==nullptr) return 1;
        
        int min_depth=INT_MAX;//
        
        //为什么只访问了3和20？？？
        std::cout << "root->val = " << root->val << std::endl;
        
        if(root->left!=nullptr)     min_depth=std::min(minDepth(root->left),min_depth);
        if(root->right!=nullptr)    min_depth=std::min(minDepth(root->right),min_depth);
        
        return min_depth+1;
    }    
};

class Solution_2
{
public:
    //Time Complexity: 
    //Space Complexity: 
    int minDepth(TreeNode *root) 
    {
        if(root==nullptr) return 0;
        std::cout << "root->val = " << root->val << std::endl;

        if(root->left==nullptr) return 1 + minDepth(root->right);
        if(root->right==nullptr) return 1 + minDepth(root->left);
        
        return 1+min(minDepth(root->left),minDepth(root->right));
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
        
        int ret = Solution_2().minDepth(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}