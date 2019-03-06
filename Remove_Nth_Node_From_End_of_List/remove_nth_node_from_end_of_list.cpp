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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head==nullptr)
            return nullptr;
        
        //删去尾部第N个节点
        ListNode* temp;
        
        //正向遍历还是反向遍历？
        //单链表
        //如果正向遍历，那么时间复杂度会变大
	int count=0;
        while(head!=nullptr)
        {
	   count++;
	   head=head->next;
        }
        
        return temp;
    }
};
