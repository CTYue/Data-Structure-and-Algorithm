/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > result;
    if (root == nullptr) 
        return result;

    std::queue<TreeNode*> queue;
    queue.push(root);
    bool leftToRight = true;

    while (!queue.empty()) {
        int size = queue.size();
        
        vector<int> row(size);
        for (int i = 0; i < size; i++) 
        {
            //
            TreeNode* node = queue.front();
            queue.pop();

            // find position to fill node's value
            //这是什么意思？
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) 
            {
                queue.push(node->left);
            }
            if (node->right) 
            {
                queue.push(node->right);
            }
        }
        
        // after this level
        leftToRight = !leftToRight;
        //Push each level to result
        result.push_back(row);
    }
    return result;
    }
};
