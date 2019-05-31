//  main.cpp
//  Find_Bottom_Left_Tree_Value
//
//  Created by Zidong Yu on 8/9/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.
//
//  Description: Given a binary tree, find the leftmost value in the last row of the tree.
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
    node(){left = nullptr;right = nullptr;}
    node(int x){data = x;left = nullptr;right = nullptr;}
};

//=========================================================//
//  My solution: use vector to store all nodes, then find
//  the left most one
//=========================================================//

//int height(node* root)
//{
//    if(root == nullptr)
//        return 0;
//
//    return max(height(root->left),height(root->right)) + 1;
//}
//
//void insertData(vector<vector<string>> &result, node* root, int row, int start, int end)
//{
//    if( root == nullptr )
//        return;
//
////    if( start > end )
////        return;
//
//    cout << "root->data = " << root->data << endl;
//    int middle = (start + end) / 2;
//    result[row][middle] = to_string(root->data);
//
//
//    //这里有问题
//    //怎样使nodes均匀排布在vector中?
//    insertData(result, root->left, row + 1, start, middle - 1);
//    insertData(result, root->right, row + 1, middle + 1, end);
//}

//
//vector<vector<string>> getNodes(node* root)
//{
//    if( root == nullptr )
//    {
//        vector<vector<string>> temp;
//        return temp;
//    }
//
//    int row = height(root);
//    int column = pow(2,(row - 1));
//
////    cout << "row: " << row << endl;
////    cout << "column: " << column << endl;
//
//    vector<string> vec_string(column,"");
//    vector<vector<string>> vec_vec_string(row,vec_string);
//
//    insertData(vec_vec_string, root, 0 , 0, column - 1);
//
//    return vec_vec_string;
//}


//Leetcode int findBottomLeftValue(node* root)
//int findBottomLeftValue(node* root, vector<vector<string>> &result)
//{
//    int value = 0;
//    if( root == nullptr )
//        return value;
//
//    size_t row = result.size();
//
//    for(size_t i  = 0; i < result[row - 1].size(); i++)
//    {
//        if( result[row - 1][i] != "" )
//        {
//            value = stoi(result[row - 1][i]);
//            cout << "value: " << value << endl;
//            return value;
//        }
////        cout << "value: " << result[row - 1][i] << endl;
//    }
//
//    return value;
//}

//int findBottomLeftValue(node* root)
//{
//    int value = 0;
//    if( root == nullptr )
//        return value;
//
//    vector<vector<string>> result;
//    int row = height(root);
//    int column = pow(2,row) - 1;
//
//    //    cout << "row: " << row << endl;
//    //    cout << "column: " << column << endl;
//
//    vector<string> vec_string(column,"");
//    vector<vector<string>> vec_vec_string(row,vec_string);
//
//    insertData(vec_vec_string, root, 0 , 0, column - 1);
//    result = vec_vec_string;
//
//    for(size_t i  = 0; i < result[row - 1].size(); i++)
//    {
////        if( result[row - 1][i] != "" )
////        {
////            value = stoi(result[row - 1][i]);
////            cout << "value: " << value << endl;
////            return value;
////        }
//                cout << "value: " << result[row - 1][i] << endl;
//    }
//
//    return value;
//}


//=========================================================//
//  BFS Solution
//=========================================================//

int findBottomLeft_BFS(node* root)
{
    queue<node*> queue;//How to use new expression here？
    queue.push(root);
    
    while(!queue.empty())
    {
        //First in, first out
        root = queue.front();
        queue.pop();
        
        if(root->right != nullptr)
        {
            queue.push(root->right);
        }
        
        if(root->left != nullptr)
        {
            queue.push(root->left);
        }
    }
    return root->data;    
}


//=========================================================//
//  DFS Solution
//=========================================================//
int maxDepth = 0;
int leftMost = 0;

int getMaxDepth(node* root, int curDepth)
{
    if(root == nullptr)
        return 0;

    int left = getMaxDepth(root->left, curDepth + 1);
    int right = getMaxDepth(root->right, curDepth + 1);
    
    //Why?
    int subTreeDepth = max(max(left,right), curDepth);
    maxDepth = max(subTreeDepth, maxDepth);
    
    return subTreeDepth;//Why?
}

void getLeftMost(node* root, int curDepth)
{
    if(root == nullptr)
        return;
    
    getLeftMost(root->right, curDepth + 1);
    if( curDepth == maxDepth )
        leftMost = root->data;//why?
    
    getLeftMost(root->left, curDepth + 1);
}

int findBottomLeft_DFS(node* root)
{
    getMaxDepth(root, 0);
    getLeftMost(root,0);
    
    return leftMost;
}



int main(int argc, const char * argv[])
{
    //Test hub
    //Test case 1, expected result =
//    node* root = new node(1);
//    root->left = new node(2);
//    root->left->left = new node(4);
//    root->left->left->right = new node(8);
//    root->right = new node(3);
//    root->right->right = new node(6);
//    root->right->left = new node(5);
//    root->right->left->left = new node(7);
    
//    node* root = new node(2);
//    root->left = new node(1);
//    root->right = new node(3);
    
    //Test case 2, expected result = 666
    node* root = new node(3);
    root->left = new node(1);
    root->right = new node(5);
    root->left->left = new node(666);
    root->left->right = new node(2);
    root->right->right = new node(6);
    root->right->left = new node(4);
    
    int value = 0;
//    vector<string> vec_string;
//    vector<vector<string>> vec_vec_string = getNodes(root);
//    value = findBottomLeftValue(root);
    
//    value = findBottomLeft_BFS(root);
    value = findBottomLeft_DFS(root);
    
    cout << "The bottom left value is: " << value << endl;
    
    getchar();
    getchar();
    return 0;
}
