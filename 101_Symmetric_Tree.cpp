//  main.cpp
//  Tree_Symmetric
//
//  Description:
//  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//    For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//    1
//    / \
//    2   2
//    / \ / \
//    3  4 4  3
//    But the following [1,2,2,null,3,null,3] is not:
//    1
//    / \
//    2   2
//    \   \
//    3    3
//    Note:
//    Bonus points if you could solve it both recursively and iteratively.
//  Created by Zidong Yu on 7/31/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(){data = 0;left = nullptr;right = nullptr;};
    node(int x){data = x; left = nullptr;right = nullptr;};
};

bool dfs(node* root1, node* root2)
{
    if( root1 == nullptr && root2 == nullptr )
        return true;
    
    if( root1 == nullptr && root2 != nullptr )
        return false;
    
    if( root1 != nullptr && root2 == nullptr )
        return false;
    
    if(root1->data == root2->data)
        return dfs(root1->left, root2->right) && dfs(root1->right,root2->left);
    
    else
        return false;
}

bool isTreeSymmetric_DFS(node* root)
{
    //Recursive solution
   if(root == nullptr)
       return true;
    
    return dfs(root->left,root->right);
}

//bool isTreeSymmetric_BFS(node* root)
//{
//    if( root == nullptr )
//        return true;
//
//    bool result = true;
//    node* temp = root;
//
////    stack<node*> *test =
//
////    return result;
//}

int main(int argc, const char * argv[])
{
    //Test hub
    //Symmetric example
    //Test case: No
//    node* root = new node(1);
//    root->left = new node(2);
//    root->right = new node(2);
//    root->left->left = new node(3);
//    root->left->right = new node(4);
//    root->right->left = new node(4);
//    root->right->right = new node(3);
//    root->right->left->right = new node(3);
//    root->right->right->right = new node(798);
    
    
    //Test case: Yes
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);
    
    
//    //Test DFS
//    if(isTreeSymmetric_DFS(root))
//        cout << "Yes" << endl;
//    else
//        cout << "No" << endl;
    
//    //Test BFS
//    if( isTreeSymmetric_BFS(root) )
//        cout << "Yes" << endl;
//    else
//        cout << "No" << endl;
    
    
    getchar();
    getchar();
    return 0;
}
