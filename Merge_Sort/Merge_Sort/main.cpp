//
//  main.cpp
//  Merge_Sort
//
//  Created by Zidong Yu on 7/10/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.
//

#include <iostream>
using namespace std;

class node{
public:
    int value;
    node* next;
    node(){value = 0; next = nullptr;};
    node(int k){value = k;next = nullptr;};
};

class linked_list{
public:
    node* head;
    int num_nodes;
    linked_list(){head = nullptr;num_nodes = 0;};
    void add_node(int k)
    {
        num_nodes++;
        node *new_head = new node(k);
        new_head->next = head;
        head = new_head;
    };
};
void Split(node* head, node* &partA, node* &partB);
void Sort(node* &head);
node* Merge(node* partA, node* partB);

void Split(node* head, node* &partA, node* &partB)
{
//    cout << "Split function..." << endl;
    //Use slow fast method
    //为什么使用这种方法？
    //没弄懂
    node *slow = head;
    node *fast = head->next;
    
    while(fast != nullptr)
    {
        fast = fast->next;
        if(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    partA = head;
    partB = slow->next;
    slow->next = nullptr;
    
    
//My method
    //我的方法是用count数数
    //有问题
//    node *ptr = head;
//    int count = 1;
//    while(ptr != nullptr)
//    {
//        count++;
//        ptr = ptr->next;
//    }
//
//    //Reset ptr
//    ptr = head;
//
//    //Even case
//    if(count % 2 == 0)
//    {
//        count /= 2;
//        while(count > 1)
//        {
//            count--;
//            ptr = ptr->next;
//        }
//    }
//
//    //Odd case
//    else
//    {
//        count += 1;
//        count /= 2;
//        while(count > 1)
//        {
//            count--;
//            ptr = ptr->next;
//        }
//    }
//    partA = head;
//    partB = ptr->next;
//    ptr->next = nullptr;//for partA
    
}

void Sort(node* &head)
{
//    cout << "Sort function..." << endl;
    
    if(head == nullptr || head->next == nullptr)
        return;
    
    node *partA = nullptr;
    node *partB = nullptr;
    
    Split(head, partA, partB);
    
    Sort(partA);
    Sort(partB);
    
    head = Merge(partA, partB);
}

node* Merge(node* partA, node* partB)
{
//    cout << "Merge function..." << endl;
    //Ascending order
    node *result = nullptr;
    
    if(partA == nullptr)
        return partB;
    
    if(partB == nullptr)
        return partA;
    
    //Sort divided
    if(partA->value <= partB->value)
    {
        result = partA;
        //Compare
        //这里的Recursion没怎么明白
        //复杂度为何为O(n)
        //因为result的长度为n，Merge函数运行n次。
//        result->next = Merge(partA,partB->next);//Wrong
        result->next = Merge(partA->next, partB);
    }
    
    //if(partA->value > partB->value)
    else
    {
        result = partB;
        //Compare
        //这里的Recursion没怎么明白
        //复杂度为何为O(n)
        //因为result的长度为n，Merge函数运行n次。
//        result->next = Merge(partA->next,partB);//Wrong
        result->next = Merge(partA, partB->next);
    }
    
    return result;
}


int main(int argc, const char * argv[])
{
    
/*================Test Hub================*/
//    //Test hub for Merge sort
//
//    //Generate a linked list
//    linked_list *ll = new linked_list();
//
//    //Linked list: 19,18,17...0
//    for(int i = 0; i < 20; i++)
//    {
//        ll->add_node(i);
//    }
//
//    node *head = ll->head;
//    cout << "Original linked list" << endl;
//    cout << "=====================" << endl;
//    while(head != nullptr)
//    {
//        cout << head->value << " ";
//        head = head->next;
//    }
//    head = ll->head;
//
//    //Sort the linked list
//    //Use merge sort
//    //Time complexity O(nlogn)
//    cout << endl;
//    cout << "Sorted linked list" << endl;
//    cout << "=====================" << endl;
//    if(head == nullptr)
//        return 0;
//
//    Sort(head);
//
//    node *ptr = head;
//
//    while(ptr)
//    {
//        cout << ptr->value << " ";
//        ptr = ptr->next;
//    }
//    cout << endl;
//
//    getchar();
//    getchar();
//    return 0;
//
    
    //Test hub for bubble sort
    
    //Generate a linked list
    linked_list *ll = new linked_list();

    //Linked list: 19,18,17...0
    for(int i = 0; i < 20; i++)
    {
        ll->add_node(i);
    }

    node *head = ll->head;
    cout << "Original linked list" << endl;
    cout << "=====================" << endl;
    while(head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    head = ll->head;

    
    
    
    
    cout << endl;
    getchar();
    getchar();
    return 0;
}


