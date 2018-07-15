//HW2
//Implement the three member functions of linked_list class: reverse, sort, remove_all, and insert
//as described in the code blow
//Due: 11:59pm, Thursday, February 15
//Submit a text vesion of your program to blackboard

//For sort, you are not allowed to swap values of nodes; you should only change the addresses of pointers.
//See explanations in class on this.


#include <iostream>
#include <memory>

using namespace std;

class node {
public:
    int value;
//  node * next;
//  node * previous;
    shared_ptr<node> next;
    shared_ptr<node> previous;
    node() { next = previous = nullptr; }
    node(int k) { value = k; next = previous = nullptr; }
};

class linked_list {
public:
//    node * head;
//    node * tail;
    
    shared_ptr<node> head;
    shared_ptr<node> tail;
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
    //node * p;
    shared_ptr<node> p;
    for (int i = 0; i < k; i++) {
        //p = new node(rand() % m);
        
        p = make_shared<node>(rand() % m);

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
    
//    node * p = head;
    shared_ptr<node> p = head;
    
    cout << endl;
    while (p != nullptr) {
        cout << p->value << " ";
        p = p->next;
    }
}


void linked_list::print_reverse() {
//    node * p = tail;
    shared_ptr<node> p = tail;
    
    cout << endl;
    while (p != nullptr) {
        cout << p->value << " ";
        p = p->previous;
    }
}


void linked_list::reverse()
{
//    node *pre, *cur, *curNext, *curPrevious;

    shared_ptr<node> pre,cur,curNext,curPrevious;
    
    //Reverse from head
    pre = head;
    cur = pre->next;
    
    while( cur != nullptr )
    {
        curNext = cur->next;
        
        cur->next = pre;
        
        if( pre == head )
            pre->next = nullptr;
        
        pre = cur;
        cur = curNext;
    }
    head = pre;
    pre = tail;
    cur = pre->previous;
    
    
    while( cur != nullptr )
    {
        curPrevious = cur->previous;
        
        cur->previous = pre;
        
        if( pre == tail)
            pre->previous = nullptr;
        
        pre = cur;
        cur = curPrevious;
    }
    tail = pre;
    
    
//    //Iterative Reverse
//    node *ptr, *pre;
//
//    if( head != nullptr && head->next != nullptr )
//    {
//        ptr = head;
//        pre = nullptr;
//        while( ptr != nullptr && ptr->next != nullptr )
//        {
//            pre = ptr->next;
//            ptr->next = ptr->next->next;
//            pre->next = head;
//            head = pre;
//        }
//    }

//    if( tail != nullptr && tail->previous != nullptr )
//    {
//        ptr = tail;
//        node *p1 = nullptr;
//
//        while( ptr != nullptr && ptr->previous != nullptr)
//        {
//            p1 = ptr->previous;
//            ptr->previous = ptr->previous->previous;
//            p1->previous = tail;
//            tail = p1;
//        }
//    }
    
    

    
    
    
    
    
    
    
    
    
    
}

void linked_list::sort()
{
  
//    //Ascending
//    //Selection sort
//
//
//    if( head == nullptr || head->next == nullptr )
//        return;
//
//    node *startNode, *endNode, *minNode;
//    int min;
//    startNode = head;
//
//    while( startNode != nullptr )
//    {
//        minNode = startNode;
//        min = startNode->value;
//        endNode = startNode;
//
//        while( endNode != nullptr )
//        {
//            if( endNode->value < min )
//            {
//                min = endNode->value;
//                minNode = endNode;
//            }
//            endNode = endNode->next;
//        }
//
//
//        minNode->value = startNode->value;//交换值
//        startNode->value = min;
//        startNode = startNode->next;
//    }

    
    
    
    //Sample code from Prof
    //Selection sort
    if (head == nullptr || head->next == nullptr)
        return;

//    node * minNode, *startNode = head, *endNode, *startNext, *startPrevious;
    shared_ptr<node> minNode, startNode = head, endNode, startNext, startPrevious;
    
    int min;
    
    while (startNode != nullptr)
    {
        minNode = startNode;
        min = startNode->value;
        endNode = startNode;
        while (endNode != nullptr)
        {
            if (endNode->value < min)
            {
                minNode = endNode;
                min = endNode->value;
            }
            endNode = endNode->next;
        }

        
        //Swap nodes
        startNext = startNode->next;
        startPrevious = startNode->previous;
        
        if (startNode == head) { head = minNode; }
        if (minNode == tail) { tail = startNode; }

        if (startNode->previous != nullptr)
        {
            startNode->previous->next = minNode;
        }

        if (startNode->next != nullptr)
        {
            if (startNode->next != minNode)
                startNode->next->previous = minNode;
        }

        if (minNode->next != nullptr)
        {
            minNode->next->previous = startNode;
        }

        if (minNode->previous != nullptr)
        {
            if (startNode->next != minNode) minNode->previous->next = startNode;
        }

        startNode->next = minNode->next;

        if (minNode != startNext)
        {
            startNode->previous = minNode->previous;
            minNode->next = startNext;
        }

        else {
            startNode->previous = minNode;
            minNode->next = startNode;
        }

        minNode->previous = startPrevious;
        startNode = startNext;
    }

    
    
    
    
    
//    //Insertion sort
//    node* sorted = nullptr;
//    node* current = head;
//    node* ptr;
//
//    while (current != nullptr)
//    {
//        node *CurNext = current->next;
//
//        //break the original linked list
//        current->previous = nullptr;
//        current->next = nullptr;
//
//        if ( sorted == nullptr )
//            sorted = current;//assume a sorted linked list starts from current
//
//        else if (sorted->value >= current->value)
//        {
//            current->next = sorted;
//            current->next->previous = current;
//            sorted = current;
//        }
//
//        else {
//            ptr = sorted;
//            while (ptr->next != nullptr && ptr->next->value < current->value)
//            {
//                ptr = ptr->next;
//            }
//            current->next = ptr->next;
//
//            //if not insert at tail
//            if (ptr->next != nullptr)
//            {
//                current->next->previous = current;
//            }
//            else
//                current->next = nullptr;
//
//            ptr->next = current;
//            current->previous = ptr;
//        }
//
//        current = CurNext;
//    }
//    //update head
//    head = sorted;
//
//    //update tail
//    if(tail != nullptr)
//    {
//        while( tail->next != nullptr )
//            tail = tail->next;
//    }
//
    
    
}
    


void linked_list::insert(int k)
{
//    node *new_node = new node(k);
//    node *ptr = head;
    shared_ptr<node> new_node = make_shared<node>(k);
    shared_ptr<node> ptr = head;
    
    
    if( head == nullptr )
        return;
    
    while( ptr != nullptr)
    {
        if( k < ptr->value )
        {
            if( ptr->previous != nullptr )
            {
                ptr->previous->next = new_node;
                new_node->previous = ptr->previous;
                new_node->next = ptr;
                ptr->previous = new_node;
            }
            
            if( ptr->previous == nullptr )
            {
                new_node->next = ptr;
                ptr->previous = new_node;
                if( ptr == head )
                    head = new_node;
            }
            break;
        }
        ptr = ptr->next;
    }
    
    //若K比所有node都大，则使用尾插法
    if( ptr == nullptr )
    {
        tail->next = new_node;
        new_node->previous = tail;
        tail = new_node;
    }
    
    
    
    

//    node *new_node = new node(k);
//    new_node->previous = nullptr;
//
//    while(head->previous != nullptr)
//        head = head->previous;
//
//    node *current;
//
//    if( head->value >= new_node->value )
//    {
//        new_node->next = head;
//        new_node->next->previous = new_node;
//        head = new_node;
//    }
//
//    else
//    {
//        current = head;
//        while( current->next != nullptr && current->next->value < new_node->value )
//            current = current->next;//we should insert node after currentnode
//
//        new_node->next = current->next;
//
//        if( current->next != nullptr )//if not tail
//            new_node->next->previous = new_node;
//
//        else
//        {
//            new_node->previous = tail;
//            tail->next = new_node;
//            tail = new_node;
//        }
//
//
//        current->next = new_node;
//        new_node->previous = current;
//    }

}

void linked_list::remove_all(int k)
{
    if( head == nullptr )
        return;
    
//    node *cur, *curNext;
    shared_ptr<node> cur, curNext;
    
    cur = head;
    
    while(cur != nullptr)
    {
        curNext = cur->next;
        
        if( cur->value == k )
        {
            if( cur->next == nullptr )
            {
                tail = cur->previous;
            }
            
            if( cur->previous == nullptr )
            {
                head = cur->next;
            }
            
            if( cur->next != nullptr )
            {
                cur->next->previous = cur->previous;
            }
            
            if( cur->previous != nullptr )//when not head
            {
                cur->previous->next = cur->next;
            }
//            delete  cur;
        }
        cur = curNext;
    }
   
    
    
    
    

//    if (head == nullptr)
//        return;
//
//    node* current = head;
//    node* curNext;
//
//    while (current != nullptr)
//    {
//        if (current->value == k)
//        {
//            curNext = current->next;//store the next position
//
//            if ( current == head  )
//                head = current->next;
//
//            if (current->next != nullptr)//if node is not tail
//                current->next->previous = current->previous;
//
//            if (current->previous != nullptr)//if node is not head
//                current->previous->next = current->next;
//
//            delete current;
//
//            current = curNext;
//        }
//        else
//        {
//            current = current->next;
//        }
//    }
    
}

int main()
{

    /* -----------My Test Stub----------- */
        linked_list L1;
        L1.make_random_list(60, 15);
    //    L1.make_random_list(10, 20);
    
    
    ////    L1.print_forward();
    ////    L1.print_reverse();
    ////    L1.reverse();
    ////    L1.print_forward();
    ////    L1.print_reverse();
    ////    L1.remove_all(11);
    ////    L1.print_forward();
    ////    L1.print_reverse();
    ////    L1.sort();
    ////    L1.print_forward();
    ////    L1.print_reverse();
    
    
    //    L1.insert(1);//my code
    //    L1.insert(22);//my code
    //    L1.insert(33);//my code
    //    L1.insert(44);//my code
    //    L1.insert(55);//my code
    //    L1.insert(66);//my code
    //    L1.insert(77);//my code
    
    //    L1.insert(5);//my code
    //    L1.insert(6);//my code
    
    
        cout << "=====Befor linked list is reversed=====";//my code
        cout << endl << "Print Forward: ";//my code
        L1.print_forward();
        cout << endl << "Print Reverse: ";//my code
        L1.print_reverse();
    
//        cout << endl;
//        cout << endl << "=====After linked list is reversed=====: ";//my code
//        L1.reverse();
//        cout << endl << "Print Forward: ";//my code
//        L1.print_forward();
//        cout << endl << "Print Reverse: ";//my code
//        L1.print_reverse();
//
    

    
        cout << endl;
        cout << endl << "=====After linked list is sorted=====";//my code
        L1.sort();
        cout << endl << "Print Forward: ";//my code
        L1.print_forward();
        cout << endl << "Print Reverse: ";//my code
        L1.print_reverse();
    
    
    
    
        cout << endl;
        cout << endl << "=====After linked list is inserted=====";//my code
        L1.insert(88);//my code
        L1.insert(88);//my code
        L1.insert(88);//my code
        L1.insert(77);//my code
        L1.insert(77);//my code
        L1.insert(0);//my code
        L1.insert(11);//my code
        L1.insert(2);//my code
        L1.insert(7);//my code
        L1.insert(6666);//my code
        L1.insert(8888);//my code
        L1.insert(9999);//my code
        L1.insert(9999);//my code
        L1.insert(8888);//my code
        L1.insert(8888);//my code
        L1.insert(8888);//my code
        L1.insert(8888);//my code
        L1.insert(8888);//my code
        L1.insert(8888);//my code
        L1.insert(8888);//my code
        L1.insert(8888);//my code
        L1.insert(8888);//my code

    
        cout << endl << "Print Forward: ";//my code
        L1.print_forward();
        cout << endl << "Print Reverse: ";//my code
        L1.print_reverse();
    
    
            cout << endl;
            cout << endl << "=====After linked list is Removed=====: ";//my code
    
            L1.remove_all(7);//my code
            L1.remove_all(4);//my code
            L1.remove_all(2);
            L1.remove_all(3);
            L1.remove_all(1);
            L1.remove_all(8888);//my code
    L1.remove_all(8888);//my code
    L1.remove_all(8888);//my code
    L1.remove_all(8888);//my code
    L1.remove_all(8888);//my code
    L1.remove_all(8888);//my code
    L1.remove_all(8888);//my code
    L1.remove_all(8888);//my code
    L1.remove_all(88);//my code
    L1.remove_all(88);//my code
    L1.remove_all(88);//my code
    L1.remove_all(9999);//my code
    L1.remove_all(9999);//my code


    
            cout << endl << "Print Forward: ";//my code
            L1.print_forward();
            cout << endl << "Print Reverse: ";//my code
            L1.print_reverse();
    
    
    
    
    
    
    
    
        getchar();
        getchar();
        return 0;
    
    
//    linked_list L1;
//    L1.make_random_list(60, 15);
//    L1.print_forward();
//    L1.print_reverse();
//    L1.reverse();
//    L1.print_forward();
//    L1.print_reverse();
//    L1.remove_all(11);
//    L1.print_forward();
//    L1.print_reverse();
//    L1.sort();
//    L1.print_forward();
//    L1.print_reverse();
//    L1.insert(0);
//    L1.insert(10);
//    L1.insert(16);
//    L1.print_forward();
//    L1.print_reverse();
//    getchar();
//    getchar();
//    return 0;
    
    
}
