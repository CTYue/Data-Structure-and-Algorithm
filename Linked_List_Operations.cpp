/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-05-31 01:12:19
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-05-31 01:12:19
 * @Description: To be added.
 */

//Submit a text vesion of your program to blackboard

//For sort, you are not allowed to swap values of nodes; you should only change the addresses of pointers.
//See explanations in class on this.

#include <iostream>
using namespace std;

class node {
public:
    int value;
    node * next;
    node * previous;
    node() { next = previous = nullptr; }
    node(int k) { value = k; next = previous = nullptr; }
};

class linked_list {
public:
    node * head;
    node * tail;
    linked_list() { head = tail = nullptr; }
    void make_random_list(int k, int m);//create a linked list of
    //k nodes with values in 0 ..m-1 randomly
    void print_forward(); //Print values of all nodes from head node
    void print_reverse(); //Print values of all nodes reversely from tail node
    void reverse(); //Reverse the order of nodes of linked list
    void sort(); //Sort the nodes, based on ascending order of node values
    
    void insert(int k); //Create a new node with values k, and properly add it to an already sorted list
    //After the insertion, the entire linked list is still sorted.
    //You are not allowed to invoke the function sort()

    void remove_all(int k); //Remove all nodes whose node values are equal to k
    
};


void linked_list::make_random_list(int k, int m) { //create linked list of k nodes with
    //values randomly in 0 ... m-1
    node * p;
    for (int i = 0; i < k; i++) {
        p = new node(rand() % m);
        p->next = head;
        if (head == nullptr) {
            tail = p; head = p;
        }
        else {
            head->previous = p;
            head = p;
        }
    }
}

void linked_list::print_forward() {
    node * p = head;
    cout << endl;
    while (p != nullptr) {
        cout << p->value << " ";
        p = p->next;
    }
}


void linked_list::print_reverse() {
    node * p = tail;
    cout << endl;
    while (p != nullptr) {
        cout << p->value << " ";
        p = p->previous;
    }
}

void linked_list::reverse()
{
    //Iterative Reverse
    node *ptr, *pre;
    
    if( head != nullptr && head->next != nullptr )
    {
        ptr = head;
        pre = nullptr;
        while( ptr != nullptr && ptr->next != nullptr )
        {
            pre = ptr->next;
            ptr->next = ptr->next->next;
            pre->next = head;
            head = pre;
        }
    }
    
    if( tail != nullptr && tail->previous != nullptr )
    {
        ptr = tail;
        node *p1 = nullptr;

        while( ptr != nullptr && ptr->previous != nullptr)
        {
            p1 = ptr->previous;
            ptr->previous = ptr->previous->previous;
            p1->previous = tail;
            tail = p1;
        }
    }
}

void linked_list::sort()
{

    //Insertion sort
    node* sorted = nullptr;
    node* current = head;
    node* ptr;
    
    while (current != nullptr)
    {
        node *CurNext = current->next;
        
        //break the original linked list
        current->previous = nullptr;
        current->next = nullptr;
        
        if ( sorted == nullptr )
            sorted = current;//assume a sorted linked list starts from current
        
        else if (sorted->value >= current->value)
        {
            current->next = sorted;
            current->next->previous = current;
            sorted = current;
        }
        
        else {
            ptr = sorted;
            while (ptr->next != nullptr && ptr->next->value < current->value)
            {
                ptr = ptr->next;
            }
            current->next = ptr->next;
            
            //if not insert at tail
            if (ptr->next != nullptr)
            {
                current->next->previous = current;
            }
            else
                current->next = nullptr;
            
            ptr->next = current;
            current->previous = ptr;
        }
        
        current = CurNext;
    }
    //update head
    head = sorted;
    
    //update tail
    if(tail != nullptr)
    {
        while( tail->next != nullptr )
            tail = tail->next;
    }

}
    


void linked_list::insert(int k)
{
    //Will not invoke sort()
    node *new_node = new node(k);
    new_node->previous = nullptr;
    
    //cannot create new linked list
    //must be inserted in a non-empty linked list
    while(head->previous != nullptr)
        head = head->previous;
    
    node *current;
    
    if( head->value >= new_node->value )
    {
        new_node->next = head;
        new_node->next->previous = new_node;
        head = new_node;
    }

    else
    {
        current = head;
        while( current->next != nullptr && current->next->value < new_node->value )
            current = current->next;//we should insert node after currentnode

        new_node->next = current->next;

        if( current->next != nullptr )//if not tail
            new_node->next->previous = new_node;

        else
        {
            new_node->previous = tail;
            tail->next = new_node;
            tail = new_node;
        }
        
        
        current->next = new_node;
        new_node->previous = current;
    }

}

void linked_list::remove_all(int k)
{

    if (head == nullptr)
        return;

    node* current = head;
    node* curNext;

    while (current != nullptr)
    {
        if (current->value == k)
        {
            curNext = current->next;//store the next position

            if ( current == head  )
                head = current->next;

            if (current->next != nullptr)//if node is not tail
                current->next->previous = current->previous;

            if (current->previous != nullptr)//if node is not head
                current->previous->next = current->next;

            delete current;

            current = curNext;
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{

    linked_list L1;
    L1.make_random_list(60, 15);
    L1.print_forward();
    L1.print_reverse();
    L1.reverse();
    L1.print_forward();
    L1.print_reverse();
    L1.remove_all(11);
    L1.print_forward();
    L1.print_reverse();
    L1.sort();
    L1.print_forward();
    L1.print_reverse();
    L1.insert(0);
    L1.insert(10);
    L1.insert(16);
    L1.print_forward();
    L1.print_reverse();
    getchar();
    getchar();
    return 0;
    
}

