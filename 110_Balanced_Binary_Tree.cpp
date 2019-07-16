/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-15 21:06:30
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-15 21:26:29
 * @Description: To be added.
 * @AC: Solution_1: Yes: faster than 67.80%, less than 80.88%
 *      Solution_2: 
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

class Solution_1 {
public:
    //Top-down Approach
    //分治法
    bool isBalanced(TreeNode* root) 
    {
        if(root==nullptr)   return true;
        int depth_left=depth(root->left);
        int depth_right=depth(root->right);
        
        return abs(depth_left-depth_right)<=1 && isBalanced(root->left) && isBalanced(root->right) ;
    }
    
    int depth(TreeNode* root)
    {
        if(!root) return 0;
        return std::max(depth(root->left),depth(root->right))+1;        
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
        
        bool ret = Solution().isBalanced(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}