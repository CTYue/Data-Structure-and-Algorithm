//  main.cpp
//  Print_Binary_Tree
//  Description:
//    Print a binary tree in an m*n 2D string array following these rules:
//
//    The row number m should be equal to the height of the given binary tree.
//    The column number n should always be an odd number.
//    Each unused space should contain an empty string "".
//    Print the subtrees following the same rules.
//    Example 1:
//    Input:
//    1
//    /
//    2
//    Output:
//    [["", "1", ""],
//     ["2", "", ""]]
//    Example 2:
//    Input:
//    1
//    / \
//    2   3
//    \
//    4
//    Output:
//    [["", "", "", "1", "", "", ""],
//     ["", "2", "", "", "", "3", ""],
//     ["", "", "4", "", "", "", ""]]
//    Example 3:
//    Input:
//    1
//    / \
//    2   5
//    /
//    3
//    /
//    4
//    Output:
//
//    [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
//     ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
//     ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
//     ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
//  Created by Zidong Yu on 8/1/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(){left = nullptr;right = nullptr;}
    node(int x){data = x;left = nullptr;right = nullptr;}
};

int count = 0;


//Recursive implementation for addition
//你要干嘛？
//Recursion函数不一定需要返回类型，void型也可以。
//int recursion(int x)
//{
//    int result = 0;
//
//    cout << "I am working" << endl;
//
//    if( result < 10 )
//    {
//        result += 1;
//
//        cout << "I am working" << endl;
//        cout << "result = " << result << endl;
//
//        result = recursion(x);
//    }
//
//    return result;
//}


//We need 2^n-1 spaces for each level
//Return height
int height(node* root)
{
    //Recursive
    if( root == nullptr )
        return 0;
    
    return max(height(root->right), height(root->left)) + 1;
}

void insertData(vector<vector<string>> &result, node* root, int row, int start, int end)
{
    if(root == nullptr)
        return;
    
    int middle = (start + end) / 2;
    
    result[row][middle] = to_string(root->data);
    insertData(result, root->left, row + 1, start, middle - 1);
    insertData(result, root->right, row + 1, middle + 1 , end);
}

vector<vector<string>> printTree(node* root)
{
    if(root == nullptr)
    {
        vector<vector<string>> temp;
        return temp;
    }
    int  row = height(root);
    int column = (pow(2, height(root)) - 1);
    
    cout << "height: " << row << endl;
    cout << "column: " << column << endl;
    
    vector<string> vec_string(column,"\"\"");
    vector<vector<string>> vec_vec_string(row,vec_string);

//  Insert root->data to correct position recursively
    //insertData中使用root == nullptr确保row不会越界。
    insertData(vec_vec_string, root, 0, 0, column - 1);
    
    return vec_vec_string;
}



int main(int argc, const char * argv[])
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->left->left = new node(4);

    
    
    auto result = printTree(root);

    cout << endl << "Print vector<vector<string>>: " << endl;
    for(int i = 0;i < result.size();i++)
    {
        for(int j = 0;j < result[i].size();j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

//Test for recursion
//    int test = 10;
//    int res = 0;
////    res = recursion(10);
////    cout << "res_recursion = " << res << endl;
    
    getchar();
    getchar();
    return 0;
}
