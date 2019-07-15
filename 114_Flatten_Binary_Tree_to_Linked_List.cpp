/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-13 11:15:38
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-13 22:11:14
 * @Description: To be added.
 * @AC: Yes: 
 */

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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
    //算不算真正意义上的in-place?
    //我觉得算
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    TreeNode* prev=nullptr;
    void flatten(TreeNode* root) 
    {
        if(root==nullptr)   return;
        
        //Post-order Traversal
        //in Right-Left-Root
        flatten(root->right);
        flatten(root->left);
        std::cout << "===============" << std::endl;
        std::cout << "root->val = " << root->val << std::endl;
        if(prev!=nullptr)   std::cout << "prev = " << prev->val << std::endl;
        std::cout << "===============" << std::endl;
        
        //注意理解这里！
        root->right=prev;
        root->left=nullptr;
        prev=root;
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

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() 
{
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        Solution_1().flatten(root);

        string out = treeNodeToString(root);
        cout << out << endl;
    }
    return 0;
}