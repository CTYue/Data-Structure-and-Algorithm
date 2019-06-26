#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
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
    //Iteration Approach
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)   return 0;
        vector<pair<int, TreeNode*> > my_stack;
        my_stack.push_back(pair<int, TreeNode*>(1, root));
        int max_depth = 0;
        
        while (!my_stack.empty()) 
        {
            pair<int, TreeNode*> my_pair = my_stack.back();
            
            int c_depth = get<0>(my_pair);//获取pair的第一个值
            // std::cout << "c_depth = " << c_depth << std::endl;
            TreeNode* cur = get<1>(my_pair);//获取pair的第二个值
            // std::cout << "c_node->val = " << c_node->val << std::endl;
            
            max_depth = std::max(max_depth, c_depth);
            my_stack.pop_back();
            
        if (cur->left!=nullptr) 
            my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, cur->left));

        if (cur->right!=nullptr)
            my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, cur->right));
        }
        
        return max_depth;
    }
};

class Solution_2
{
public:
    //Recursion Approach
    //Time Complexity: O(n)
    //Space Complexity: Best case(Balanced): O(logN)
    //Space Complexity: Worst case(Unbalanced): O(N)
    int maxDepth(TreeNode* root)
    {
        if(root==nullptr)   return 0;

        return 1+std::max(maxDepth(root->left),maxDepth(root->right));
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

int main(int argc, char* argv[]) 
{
    string line;
    while (getline(cin, line)) 
    {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution_1().maxDepth(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}