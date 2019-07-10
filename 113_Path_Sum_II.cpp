#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_1 {
public:
    //DFS Solution
    //Time Complexity:
    //Space Complexity:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> res;
        if(root==nullptr)   return res;
        
        

        return res;
    }
};

int main(int argc, char* argv[])
{
    //TODO

}