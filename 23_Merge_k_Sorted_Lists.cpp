/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-23 19:31:20
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-23 19:34:50
 * @Description: To be added.
 *  */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        int min=INT_MIN;
        ListNode* new_head=nullptr;
        priority_queue<int> p_queue;//由上到下：从大到小
        for(auto head: lists)
        {
            while(head)
            {
                p_queue.push(head->val);
                head=head->next;
            }
        }
        
        while(!p_queue.empty())
        {
            cout<<p_queue.top()<<" ";
            //Create new linked list.
            ListNode* new_node=new ListNode(p_queue.top());
            new_node->next=new_head;
            new_head=new_node;
            p_queue.pop();
        }
        
        return new_head;
    }
};


int main()
{
    //TODO
    
}