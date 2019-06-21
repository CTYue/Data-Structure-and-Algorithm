/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-21 00:06:03
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-21 02:11:38
 * @Description:
 * Pre-order Traversal:
 *         1
 *      2     3
 *    4   5     6
 * Output: 1 2 4 5 3 6
 */

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_1
{
public:
    //Iteration solution
    //Time complexity: O(n)
    //Space complexity: O(n)
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res={};
        if(root==nullptr)   return res;
        
        stack<TreeNode*> stack;
        TreeNode* cur=root;
        
        while(cur!=nullptr || !stack.empty())
        {
            while(cur!=nullptr)
            {
                stack.push(cur);
                std::cout << "cur->val = " << cur->val << std::endl;
                res.push_back(cur->val);
                cur=cur->left;
            }
            
            //Update cur
            cur=stack.top();
            std::cout << "Updated cur->val = " << cur->val << std::endl;
            std::cout << "========"<< std::endl;
            stack.pop();
            cur=cur->right;
        }
        
        return res;
    }
};

class Solution_2
{
public:
    //Recursion Solution
    //DFS
    //Time complexity: O(n)
    //Space complexity: O(n)(Worst case) O(logn)(Average case)
    //Average case happens when the tree is balanced or almost balanced
    //Worst case happens when the tree is unbalanced(left or right???)
    void recursion(TreeNode* root, vector<int> &res)
    {
        if(root==nullptr)   return;
        
        res.push_back(root->val);
        
        if(root->left!=nullptr)
            recursion(root->left,res);
        
        if(root->right!=nullptr)
            recursion(root->right,res);
    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res={};
        if(root==nullptr) return res;
        
        recursion(root,res);
        return res;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}
int main(int argc, char* argv[]) {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution_1().preorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}