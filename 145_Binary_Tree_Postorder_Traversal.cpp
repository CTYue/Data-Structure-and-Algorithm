/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-16 20:55:00
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-16 22:40:26
 * @Description:
 *                1
 *             2     3
 *          4   5  6   7
 * 
 * Postorder: 4-5-2-6-7-3-1
 *@AC: Iteration: Yes: faster than 100%, less than 57.81%
       Recursion: Yes: 
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

class Solution_1 {
public:
    //Iteration
    //Time Complexity: O(logN)???
    //Space Complexity: ???
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root==nullptr) return res;
        
        stack<TreeNode*> stack;
        TreeNode* cur=root;
        TreeNode* last=nullptr;
        
        while(cur!=nullptr || !stack.empty())
        {
            //遍历左子树
            if(cur!=nullptr)
            {
                stack.push(cur);
                //std::cout << "stack.size() = " << stack.size() << std::endl;
                
                cur=cur->left;
            }
            //遍历右子树
            else
            {
                TreeNode* r_cur=stack.top();
                //Update cur to right child
                if(r_cur->right!=nullptr && last!=r_cur->right)   cur=r_cur->right;                    
                
                //if cur is not 
                else
                {
                    res.push_back(r_cur->val);
                    last=r_cur;//这是什么意思？
                    stack.pop();
                }
            }
        }
        return res;
    }
};


class Solution_2
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root==nullptr) return res;
        dfs(root, res);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& res)
    {
        if(root==nullptr)   return;

        dfs(root->left, res);
        dfs(root->right, res);

        res.push_back(root->val);
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
        
        vector<int> ret = Solution_1().postorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}