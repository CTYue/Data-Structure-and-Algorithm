/*
 * main.cpp
 * Version 1.0
 * Created on:Jan 17, 2018 9:03:32 PM
 * Author: yuzidong
 */
#include <iostream>
#include <vector>
using namespace std;

//ListNode
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL){}
};

//Create ListNode
ListNode* createNode(int d)
{
	ListNode* p;
	p->val = d;
	p->next = nullptr;
	cout << "Create Node" << endl;
	return p;
}

//Create List
void createList(ListNode** h)
{
	ListNode* pn = nullptr;
	ListNode* p = nullptr;
	int d;
	cin >> d;
	pn = createNode(d);
	*h = pn;
	p = *h;

	while(1)
	{
		cout << "Input data:" << endl;
		cin >> d;
	}
}

class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
    		vector<int> listStorage;
    		int i = 0;
    		while(head != nullptr)
    		{
    			listStorage.push_back(head->val);
    			head = head->next;
    			cout << "This is the "<< i << "th count" << endl;
    			cout << listStorage[i] << endl;
    			i++;
    		}
    }
};

int main(void)
{
	cout << "Hello World" << endl;
	float n1 = 4.0;
	int n2 = 10;
	cout << n1/n2 << endl;//the result is of float type
	cout << n2/n1 << endl;//the result is of float type
}
