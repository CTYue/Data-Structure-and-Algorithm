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
    //Problem in this solution:
    //INT_MAX and INT_MIN are buggy
    //Time Complexity:
    //Space Complexity:
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