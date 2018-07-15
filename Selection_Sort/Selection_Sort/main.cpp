//
//  main.cpp
//  Selection_Sort
//
//  Created by Zidong Yu on 7/13/18.
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

void Sort(node* head)
{
    node* ptr = head;
    
    
}


int main(int argc, const char * argv[])
{
    /*================Test Hub================*/
    //Test hub for Selection sort
    
    //Generate a linked list
    linked_list *ll = new linked_list();
    
    //Linked list: 19,18,17...0
    for(int i = 0; i < 20; i++)
    {
        ll->add_node(20-i);
        //        ll->add_node(i);
    }
    node* low = ll->head;
    node *head = ll->head;
    
    cout << "=====================" << endl;
    cout << "Original linked list" << endl;
    while(head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    
    
    
    //Sort code here
    
    cout << endl;
    getchar();
    getchar();
    return 0;
}


