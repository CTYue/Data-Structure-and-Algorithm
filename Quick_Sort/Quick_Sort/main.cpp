//  main.cpp
//  Quick sort
//
//  Created by Zidong Yu on 7/10/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.

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

void QuickSort(node* head, node* low, node* high);
int Partition(node* head, node* low, node* high);
void Swap(node* a,node* b)
{
    //swap value of two nodes
    int temp = b->value;
    b->value = a->value;
    a->value = temp;
}

int Partition(node* head, node* low, node* high)
{
    node* pivot = high;
    
    //Use the right node as pivot
    while(pivot->next != nullptr)
        pivot = pivot->next;

    node *ptr = head;//这里有问题!
    cout << "ptr in Partition Function: " << ptr << endl;
    
    node *ll_index = head;
    int index = 0;
    
    while(ptr != nullptr)
    {
        ll_index = head;
        index = 0;
        if( ptr->value <= pivot->value )
        {
            index++;//得到左侧小于pivot的node的index
            
            for(int i = 0; i < index; i++)
            {
                ll_index = ll_index->next;
            }
            Swap(ll_index,ptr);//将靠左边的位置们用当前找到的小于pivot的值替换掉
        }
        ptr = ptr->next;
    }

    Swap(ll_index->next,high);
    
    //大于pivot的node被放在右边？怎样将大于pivot的node放在右边？

    return index;
}

void QuickSort(node* head, node* low, node* high)
{
    int pi = 0;
    node *pi_pre = head;
    node *pi_after = head;
    node *ptr = nullptr;
    int count_low = 0;
    int count_high = 0;
    
    //Ascending order
    ptr = head;
    while(ptr != low)
    {
        count_low++;
        ptr = ptr->next;
    }

    ptr = ptr->next;
    while (ptr != nullptr)
    {
        count_high++;
        ptr = ptr->next;
    }
    
    if(count_low < count_high)
    {
        //Partition
        pi = Partition(head, low, high);
        for(int i = 0; i < pi - 1; i++ )
        {
            pi_pre = pi_pre->next;
        }
        
        for(int j = 0; j < pi + 1; j++)
        {
            pi_after = pi_after->next;
        }
        
        //迭代有问题，出现了无限次的迭代!
        node *low = head;
        node *high = head;
        
        while( high != nullptr )
        {
            high = high->next;
        }
        
        QuickSort(head,low,pi_pre);//before pivot
        QuickSort(head,pi_after,high);//after pivot
    }
}


int main(int argc, const char * argv[])
{
    /*================Test Hub================*/
    //Test hub for Quick sort
    
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
    head = ll->head;
    
    node *high = ll->head;
    while( high->next != nullptr )
        high = high->next;
    
    head = ll->head;
    QuickSort(head, low, high);

    cout << endl;
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


