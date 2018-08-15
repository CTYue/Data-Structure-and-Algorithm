//
//  main.cpp
//  Tree_Leaf_Similar
//  Description:    Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
//  For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
//  Two binary trees are considered leaf-similar if their leaf value sequence is the same.
//
//  Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
//
//    Input: Roots of below Binary Trees
//    1
//    / \
//    2   3
//    /   / \
//    4   6   7
//
//    0
//    /  \
//    5    8
//    \  / \
//    4  6  7
//    Output: same
//    Leaf order traversal of both trees is 4 6 7
//
//  Created by Zidong Yu on 7/21/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
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

bool isSame(node *root1, node* root2)
{
    //Check if two roots are same
    //stack: first in last out
    std::stack<node*> *s1 = new std::stack<node*>();//store root1 leaves
    std::stack<node*> *s2 = new std::stack<node*>();//store root2 leaves
    
    s1->push(root1);
    s2->push(root2);
    
    bool result = true;
    
    
    if( root1 == nullptr && root2 == nullptr )
        return true;
    
    if( root1 == nullptr && root2 != nullptr )
        return false;
        
    else if( root1 != nullptr && root2 == nullptr )
        return false;
        
        
    while( !s1->empty() || !s2->empty() )
    {
        //Why?
        if(s1->empty() || s2->empty())
            return false;
        
        node *temp1 = s1->top();
        s1->pop();
        
        //While the top element is not null and has leaf
        //store right leaf before left leaf
        while( temp1 != nullptr && temp1->isLeaf()  )
        {
            if(temp1->right != nullptr)
                s1->push(temp1->right);
            
            if(temp1->left != nullptr)
                s1->push(temp1->left);
            
            temp1 = s1->top();
            s1->pop();
            
            cout << "temp1->data: " << temp1->data << endl;
        }
        
        node *temp2 = s2->top();
        s2->pop();
        
        while( temp2 != nullptr && temp2->isLeaf() )
        {
            if( temp2->right != nullptr )
                s2->push(temp2->right);
            
            if( temp2->left != nullptr )
                s2->push(temp2->left);
            
            temp2 = s2->top();
            s2->pop();
            
            cout << "temp2->data: " << temp2->data << endl;
        }
        
        
        if( temp1 == nullptr && temp2 != nullptr )
            return false;
        if( temp1 != nullptr && temp2 == nullptr )
            return false;
        
        if( temp1 != nullptr && temp2 != nullptr )
        {
            cout << "==============" << endl;
            cout << "temp1->data = " << temp1->data << endl;
            cout << "temp2->data = " << temp2->data << endl;
            
            if( temp1->data == temp2->data)
                result &= true;
            if( temp1->data != temp2->data )
                result &= false;
        }
    }
    
    return result;
}


int main(int argc, const char * argv[])
{
    
//      Stack is not empty when nullptr node pushed into.
    node *root1 = nullptr;
    node *root2 = nullptr;

    cout << "root1: " << root1 << endl;
    cout << "root2: " << root2 << endl;


    stack<node*> *test = new stack<node*>;
    test->push(root1);
    test->push(root2);

    if(test->empty())
        cout << "stack is empty" << endl;

    else
        cout << "Not empty" << endl;

    
////    //Test Hub
//    // Check if two trees have same leaf
//    node* root1 = new node(1);
//    root1->left = new node(2);
//    root1->right = new node(3);
//    root1->left->left = new node(4);
//    root1->right->left = new node(6);
//    root1->right->right = new node(7);
//
////    //Expected: Yes
////    node* root2 = new node(7);
////    root2->left = new node(8);
////    root2->right = new node(9);
////    root2->left->left = new node(4);
////    root2->right->left = new node(6);
////    root2->right->right = new node(7);
//
//
//    //Expected: Yes
//    node* root2 = new node(7);
//    root2->left = new node(4);
//    root2->right = new node(9);
////  root2->left->left = new node(4);
//    root2->right->left = new node(6);
//    root2->right->right = new node(7);
//
//
//    if(isSame(root1, root2) == true)
//        cout << "Yes" << endl;
//
//    else
//        cout << "No" << endl;
    

//    ????
//    stack<node*> *test = new stack<node*>();
//    node* temp = test->top();
//    if(test->empty())
//        cout << "test is empty!" << endl;
////    cout << "temp: " << temp << endl;

    getchar();
    getchar();
    return 0;
}
