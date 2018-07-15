//  main.cpp
//  Reverse_Linked_List
//
//  Created by Zidong Yu on 6/7/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.

#include <iostream>

class node
{
public:
    int value;
    node *next;
//  node *previous;
    node(int v):value(v)//initializer list
    {
        value = v;
        next = nullptr;
//      previous = nullptr;
    }
};

class linked_list
{
public:
    int num_nodes = 0;
    node *head;;
//    node *tail;
    linked_list(int n)
    {
        num_nodes = n;
        head = nullptr;
//      tail = nullptr;
    }
    
    linked_list()
    {
        head = nullptr;
//        tail = nullptr;
    }
};


node *reverse(node* head)
{
    //Please impelement both iterative and recursive implementation
    
    
    node * temp = nullptr;
    return temp;
}

node *reverse(node *head,int m, int n)
{
    //Please implement both iterative and recursive implementation
    
    
    
    node *temp = nullptr;
    return temp;
}

node *remove(int val)
{
    
    return nullptr;
}

int numComponents(node* head, std::vector<int>& G)
{
    int component = 0;
    //How to calculate component?
    //
    
    return component;
}

int main(int argc, const char * argv[])
{
    //Create a linked list
    linked_list *ll = new linked_list();
//    ll->head = new node(0);
    node *temp_ptr = ll->head;
    
    //创建链表
    //
//    for(int i = 1; i < 100; i++)
//    {
//        temp_ptr->next = new node(i);
//        temp_ptr = temp_ptr->next;
//    }

//
//    //创建链表
//    //头插法，倒序插入
//    for(int i = 99; i > 0; i--)
//    {
//        node *new_node = new node(i);
//        new_node->next = ll->head;
//        ll->head = new_node;
//    }
    
    
//    //Print linked list
//    node *print_ptr = ll->head;
//    std::cout << std::endl;
//    std::cout << "Print linked list" << std::endl;
//    std::cout << "===================================================================================" << std::endl;
//    while( print_ptr != nullptr )
//    {
//        std::cout << print_ptr->value << " ";
//        print_ptr = print_ptr->next;
//    }
//    std::cout << std::endl;
//    std::cout << "===================================================================================" << std::endl;
//
//
//    //reverse a single linked list
//    node *cur = ll->head;
//    node *temp = nullptr;
//
//    //Complexity analysis
//    //Time Complexity: O(n)
//    //Leetcode error: member access null pointer in line 74
//    while( cur->next != nullptr )
//    {
//        node *curNext = cur->next;
//
//        cur->next = temp;
//        temp = cur;
//        cur = curNext;
//        //std::cout << "cur: " << cur << std::endl;
//    }
//
//    //Update head
//    //最后这一个ptr需要被处理
//    cur->next = temp;
//    ll->head = cur;
//    std::cout << std::endl;

//    //print single reversed linked list
//    node *ptr_print = ll->head;
//    while( ptr_print != nullptr )
//    {
//        std::cout << ptr_print->value <<  " ";
//        ptr_print = ptr_print->next;
//    }
    
    
    

//    //Reverse a single linked list in a range
//    //Leetcode medium
//    //m is the start point, n is the end point
//    int m = 5;
//    int n = 95;
//
//    //reverse the 5th to 95th nodes in a single linked list
//    node *ptr_start = ll->head;
//    node *ptr_end = ll->head;
//
//    if(m == n)
//        return 0;
//
//    int count = n - m;
//
//    for(int i = 0; i < m;i++)
//    {
//        ptr_start = ptr_start->next;
//    }
//
//    for(int j = 0; j < n;j++)
//    {
//        ptr_end = ptr_end->next;
//    }
//
//
//    node *temp = ptr_start;
//    node *cur = ptr_start->next;
//
//    //这里有问题！
//    //打印结果始终为1 2 3 4 5 6 5 6 5 6...
//    while(count--)
//    {
//        node *curNext = cur->next;
//        cur->next = temp;
//
//        temp = cur;
////      std::cout << "cur: " << cur << std::endl;
////      std::cout << "temp: " << temp << std::endl;
//        cur = curNext;
//    }
//
    
//    //print reversed linked list for range
//    node *ptr_print = ll->head;
//    std::cout << "Print reversed linked list" << std::endl;
//    std::cout << "===================================================================================" << std::endl;
//    while( ptr_print != nullptr )
//    {
//        std::cout << ptr_print->value <<  " ";
//        ptr_print = ptr_print->next;
//    }
//    std::cout << "===================================================================================" << std::endl;
    
    
    int x,y;
    x = 100;
    y= 99;
    
//    std::cout << "x/2 = " << x/2 << std::endl;
//    std::cout << "y/2 = " << y/2 << std::endl;
    
    std::cout << "x%2 = " << x%2 << std::endl;
    std::cout << "y%2 = " << y%2 << std::endl;
    

    getchar();
    return 0;
}
