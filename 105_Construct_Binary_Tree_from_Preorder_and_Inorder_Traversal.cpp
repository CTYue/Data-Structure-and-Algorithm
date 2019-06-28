/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-26 23:21:05
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-27 22:53:36
 * @Description: To be added.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

 struct TreeNode 
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    //Recursive Approach
    //Time:  O(n)
    //Space: O(n)
    int pre_index=0;
    vector<int> preorder;
    vector<int> inorder;
    unordered_map<int,int> idx_map;
    
    TreeNode* helper(int in_left, int in_right)
    {
        if(in_left==in_right)   return nullptr;
        
        //pick up pre_idx as root
        int root_val=preorder[pre_index];
        //利用pre_index遍历preorder
        TreeNode* root=new TreeNode(root_val);
        
        //找到root在inorder中的index
        int index=idx_map[root_val];
        
        //pre_index递增，遍历preorder
        pre_index++;
        
        //in_left和in_right是什么？
        //分别是inorder vector的两端
        //index是root所在的位置
        root->left=helper(in_left, index);
        root->right=helper(index+1, in_right);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        this->preorder=preorder;
        this->inorder=inorder;
        
        int idx=0;
        
        //使用inorder填充idx_map
        //此时idx_map中，first代表node值，second是其在inorder中的位置
        for(int val:inorder)    idx_map[val]=idx++;

        int in_len=inorder.size();
        
        return helper(0,in_len);
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
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

int main(int argc, char* argv[]) 
{
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}