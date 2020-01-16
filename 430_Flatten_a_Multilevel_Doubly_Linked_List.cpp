/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-01-09 23:47:52
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-14 21:06:48
 * @Description:
 */

#include <iostream>
#include <stack>

using namespace std;

class Node{
public:
    Node(int val, Node* prev, Node* next, Node* child)
    {
        val=val;
        prev=prev;
        next=next;
        child=child;
    };
    ~Node()=delete;
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) 
    {
        if(head==nullptr)   return nullptr;
        Node* dummy=new Node(0, nullptr, head, nullptr);
        Node* pre=dummy, *cur=head;
        
        stack<Node*> stack;
        stack.push(cur);
        
        //
        while(!stack.empty())
        {
            cur=stack.top();
            stack.pop();
                        
            pre->next=cur;
            cur->prev=pre;
            
            if(cur->next!=nullptr)  stack.push(cur->next);
            
            if(cur->child!=nullptr)
            {
                stack.push(cur->child);
                cur->child=nullptr;
            }
            
            pre=cur;//Move forward
        }
            dummy->next->prev=nullptr;
        
        return dummy->next;
    }
};

int main()
{
    //TODO

    
}