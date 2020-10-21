/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-20 20:30:44
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-12 20:43:29
 * @Description: 
 * In-Order Traversal: 
 *       1
 *    2    3
 *  4  5    6
 *  Res:4 2 5 1 3 6
 */

#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<sstream>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_1
{
public:
    //Recursive Solution
    //Time Complexity: O(n)
    //Space Complexity: Worst: O(n) Average: O(logn)
    void Recursion(TreeNode* root,vector<int>& res)
    {
        if(root==nullptr)   return;
        Recursion(root->left,res);
        res.push_back(root->val);
        Recursion(root->right,res);
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res={};
        if(root==nullptr)   return res;
        Recursion(root,res);
        return res;
    }
};

class Solution_2 {
public:
    //Iteration Solution
    //Time complexity: O(n)
    //Traverse each child node once, so O(n)
    //Space complexity: O(n)
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res={};
        if(root==nullptr)   return res;

        stack<TreeNode*> stack;
        TreeNode* curr = root;
        
        //注意这里的循环条件！
        while(curr!=nullptr || !stack.empty())
        {
            while(curr!=nullptr)
            {
                stack.push(curr);
                curr=curr->left;//小循环每次向左遍历到底
            }

            curr=stack.top();
            stack.pop();
            res.push_back(curr->val);
            curr=curr->right;//大循环向右遍历到底
        }
        return res;
    }
    
};


    void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

//
void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) 
    {
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution_1().inorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}