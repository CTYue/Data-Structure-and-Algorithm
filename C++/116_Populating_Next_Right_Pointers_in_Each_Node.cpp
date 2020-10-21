/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-11 21:46:21
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-11 21:47:17
 * @Description: To be added.
 */
#include<iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) 
    {
        //Level order traversal
        if(!root) return nullptr;
        
        queue<Node*> queue;
        queue.push(root);
        Node* node;
        
        while(!queue.empty())
        {
            int size=queue.size();
            for(int i=0;i<size;i++)
            {
                node=queue.front();
                queue.pop();
                
                //确保node->next不指向下一个level的元素
                if(i<size-1)
                {    
                    // cout<<node->val<<" ";
                    node->next=queue.front();//all next ptrs are set to NULL initially
                }
                // cout<<endl;
                
                if(node->left!=nullptr) queue.push(node->left);
                if(node->right!=nullptr) queue.push(node->right);
            }
        }

        //#1:
        //Loop 0:
        //End: Queue: {1}, size=1
        //#2:
        //Loop0:
        //Start: Queue: {2,3}, size=2
        //2->next=3,
        //Loop1:
        //
        //Loop1:
        //
        //End: Queue: {}
        //#3:
        //
        //Queue: {2,3},size=2
        //node=2, 2->next=3
        //Queue: {3, 4, 5},size=3
        //node=3, 3->next=
        //Queue: {4,5,6,7}
        
        return root;
    }
};

int main(int argc, char** argv)
{
    //TODO

    return 1;
}