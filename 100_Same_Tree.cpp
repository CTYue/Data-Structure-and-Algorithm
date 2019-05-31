//
//  main.cpp
//  Same_Tree
//
//  Description:
//    Given two binary trees, write a function to check if they are the same or not.
//
//    Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
//
//    Example 1:
//
//    Input:     1         1
//    / \       / \
//    2   3     2   3
//
//    [1,2,3],   [1,2,3]
//
//    Output: true
//    Example 2:
//
//    Input:     1         1
//    /           \
//    2             2
//
//    [1,2],     [1,null,2]
//
//    Output: false
//    Example 3:
//
//    Input:     1         1
//    / \       / \
//    2   1     1   2
//
//    [1,2,1],   [1,1,2]
//
//    Output: false
//  Created by Zidong Yu on 7/30/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class node
{
public:
    int data;
    node *left, *right;
    node(){data = 0;left = nullptr;right = nullptr;};
    node(int x){data = x; left = nullptr;right = nullptr;};
    bool isLeaf()
    {
        if(left == nullptr && right == nullptr)
            return false;
        
        else
            return true;
    }
};

bool isLeaf(node* root)
{
    if( root->left == nullptr && root->right ==nullptr )
        return false;
    else
        return true;
}

bool isTreeSame(node* root1, node* root2)
{
    if(root1 == nullptr && root2 == nullptr)
        return true;
    
    if(root1 == nullptr && root2 != nullptr)
        return false;
    
    if(root1 != nullptr && root2 == nullptr)
        return false;
    
    else
        return (root1->data == root2->data && isTreeSame(root1->left, root2->left) && isTreeSame(root2->right, root2->right));
}

int main(int argc, const char * argv[])
{
    //Test hub
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->left->left = new node(3);
    
    node* root2 = new node(3);
    root2->right = new node(2);
    

    if(isTreeSame(root1, root2) == true)
        cout << "Yes" << endl;
    
    else
        cout << "No" << endl;
    
    getchar();
    getchar();
    return 0;
}
