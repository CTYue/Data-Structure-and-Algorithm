#include <iostream>
#include <string>
#include <vector>

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //Two pass solution
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head==nullptr)
            return nullptr;
        //Create dummy in order to avoid case when n = count 
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp = head;

	    int count=0;//一定要初始化

        while(temp!=nullptr)
        {
            count++;
            head=head->next;
        }
        
        dummy=head;
        while(count>0)
        {
            count--;
            temp=temp->next;
        }

        return dummy->next;
    }


    // //One pass solution
    // ListNode* removeNthFromEnd(ListNode* head, int n)
    // {
    //     if(head==nullptr)
    //         return nullptr;


    // }

};
