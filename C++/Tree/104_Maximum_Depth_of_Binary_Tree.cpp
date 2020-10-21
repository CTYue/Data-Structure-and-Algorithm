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


class Solution_3 {
private:
    queue<pair<TreeNode*, int> > next_items;
    int max_depth=0;
public:
    int next_maxDepth()
    {
        //If queue is empty, then return depth.
        if(next_items.size()==0)    return max_depth;
        
        pair<TreeNode*, int> next_item=next_items.front();//
        next_items.pop();
        
        TreeNode* next_node=next_item.first;//
        int next_level=next_item.second+1;//
        
        max_depth=std::max(max_depth, next_level);
        
        if(next_node->left!=nullptr)
            next_items.push(make_pair(next_node->left, next_level));
        
        if(next_node->right!=nullptr)
            next_items.push(make_pair(next_node->right, next_level));
        
        return next_maxDepth();
    }
    
    //BFS
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    int maxDepth(TreeNode* root) 
    {
        if(root==nullptr)   return 0;
        //clear the previous queue
        std::queue<pair<TreeNode*, int> > empty;
        std::swap(next_items, empty);
        max_depth=0;
        
        next_items.push(make_pair(root,0));
        
        return next_maxDepth();
    }
};

class Solution_4
{
public:
    //BFS
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;

        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            ++ res;
            //尚未理解!
            for(int i = 0, n = q.size(); i < n; ++ i)
            {
                TreeNode *p = q.front();
                q.pop();

                if(p -> left != NULL)
                    q.push(p -> left);
                if(p -> right != NULL)
                    q.push(p -> right);
            }
        }

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