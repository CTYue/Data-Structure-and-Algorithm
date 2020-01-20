/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-15 21:06:30
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-20 00:01:01
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
    //Used DFS(Recursion) for nodes visiting,
    //top-down for height calculation
    //Time Complexity: O(???) 这个比较难分析！
    //Space Complexity: O(n)
    //注意，depth的形参也占用栈区的内存空间
    //由于depth函数被调用n(数量级)次，所以这里的空间复杂度是O(n)
    int depth(TreeNode* root)
    {
        if(!root) return 0;
        
        return std::max(depth(root->left),depth(root->right))+1;        
    }

    bool isBalanced(TreeNode* root) 
    {
        if(root==nullptr)   return true;

        return abs(depth(root->left)-depth(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right) ;
    }

};

class Solution_2
{
    //Bottom-up approach
    //同样是用DFS
    //Calculates heights while visiting nodes recursively
    //Time Complexity: O(n) 
    //Space Complexity: O(n)
private:
    bool helper(TreeNode* root, int& height)
    {
        if(root==nullptr)
        {
            height=0;
            return true;
        }
        int left=0, right=0;

        //
        if( helper(root->left, left) && helper(root->right, right) && std::abs(left-right)<=1 )
        {
            height=1 + std::max(left, right);//
            return true;
        }
        return false;
    }
public:
    bool isBalanced(TreeNode* root)
    {
        if(root==nullptr)   return true;

        int height=0;
        return helper(root, height);
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
        
        bool ret = Solution_1().isBalanced(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}