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
node* Sort(node* head);


node* Sort(node* head)
{
//    cout << "I am working!" << endl;
    //Ascending order
    node *ptr = head;
    
    while(ptr != nullptr)
    {
        node *ptrNext = ptr->next;
        while(ptrNext != nullptr)
        {
//            if( ptrNext->value <= ptr->value )
            if(ptrNext->value > ptr->value)
            {
                //Swap node or value?
                //Swap value
                int temp = ptrNext->value;
                ptrNext->value = ptr->value;
                ptr->value = temp;
            }
            
            ptrNext = ptrNext->next;
        }
        
        ptr = ptr->next;
    }
    
    return head;
}


int main(int argc, const char * argv[])
{
    
    /*================Test Hub================*/
    //Test hub for bubble sort
    
    //Generate a linked list
    linked_list *ll = new linked_list();
    
    //Linked list: 19,18,17...0
    for(int i = 0; i < 20; i++)
    {
        ll->add_node(20-i);
    }
    
    node *head = ll->head;
    cout << "=====================" << endl;
    cout << "Original linked list" << endl;
    while(head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    head = ll->head;
    
    head = Sort(head);
    
    cout << "=====================" << endl;
    cout << "Sorted linked list" << endl;

    //Print the linked list
    while( head != nullptr )
    {
        cout << head->value << " ";
        head = head->next;
    }
    
    cout << endl;
    getchar();
    getchar();
    return 0;
}


