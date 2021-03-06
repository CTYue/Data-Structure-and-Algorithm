/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-16 16:39:35
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-16 23:59:52
 * @Description: To be added.
 * @AC: Recursion: Yes
 */

#include <iostream>
#include <queue>
#include <stack>
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
    //Recursive Solution
    //Time Complexity: Average case: O(logN)
    //Space Complexity: 1*O(logN)=O(logN)
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root==nullptr)   return new TreeNode(val); 
            
        if(val==root->val)  return root;        
        if(val<root->val)   root->left = insertIntoBST(root->left, val);
        if(val>root->val)   root->right = insertIntoBST(root->right,val);
        
        return root;
    }
};

class Solution_2
{    
public:
    //Iteration
    //Time Complexity: O(logN)
    //Space Complexity: O(1)
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root==nullptr)   return new TreeNode(val);
        TreeNode* cur=root;
        
        while(cur!=nullptr)
        {
            //左遍历
            if(cur->val>val)
            {
                if(cur->left!=nullptr)  cur=cur->left;
                else
                {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
            //右遍历
            else
            {
                if(cur->right!=nullptr) cur=cur->right;
                else
                {
                    cur->right=new TreeNode(val);
                    break;
                }
            }
        }   
        //注意，是return root而不是别的。
        return root;
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

int stringToInteger(string input) {
    return stoi(input);
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int val = stringToInteger(line);
        
        TreeNode* ret = Solution_1().insertIntoBST(root, val);
        // TreeNode* ret = Solution_1().insertIntoBST(root, val);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}