//HW4: Implement a generic bag using template
//Due: March 30 (Friday) at 11:59pm
//Note that for class linked_list and bag, you need to also include destructor, copy constructor, move constructor, left ref operator=, and right ref operator=

#include <iostream>
#include <stdlib.h>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;

template <class T>
class ThreeD {
public:
    T ht;
    T wid;
    T dep;
    ThreeD<T> *next;
    ThreeD<T> *previous;
    ThreeD() { ht = wid = dep = 0; next = previous = nullptr; }
    ThreeD(T i) { ht = wid = dep = i; next = previous = nullptr; }
    ThreeD(T a, T b, T c) { ht = a; wid = b; dep = c; next = previous = nullptr; }
//  ThreeD(initializer_list<T>){ ht(0),wid(0),dep(0),next(nullptr),previous(nullptr); }
    
    //Add additional code if needed
//    friend ostream & operator<<(ostream &stream, const ThreeD<T> &obj)
//    {
//        //cout << "Printing ThreeD" << endl;
//        stream << "( " << obj.ht << ", " << obj.wid << ", " << obj.dep << " )";
//        return stream;
//    }
    
    friend ostream & operator<<( ostream &stream, const ThreeD<T> &obj )
    {
        stream << "( " << obj.ht << ", " << obj.wid << ", " << obj.dep << " )";
        return stream;
    }
    
    bool operator==(const ThreeD<T> &obj)
    {
        if (this->ht == obj.ht && this->wid == obj.ht && this->dep == obj.dep)
            return true;
        else
            return false;
    }
    
};



template <class T>
class node {
public:
    T value;
    node<T> * next;
    node<T> * previous;
    node<T>() { next = previous = nullptr; }
    
    //Add additional code if needed
    node<T>(T v) { value = v; next = nullptr; previous = nullptr; }
    
    friend ostream & operator<<(ostream &stream, const node<T> &obj)
    {
        //cout << "Printing node" << endl;
        stream << obj.value;
        return stream;
    }
    
    bool operator==(const node<T> &obj)
    {
        if ( this->value == obj.value )
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
};



template <class T>
class linked_list { //doubly linked list as in HW2
public:
    node<T> *head;
    node<T> *tail;
    int num_nodes;
    
    //constructor
    linked_list()
    {
        head = tail = nullptr;
        num_nodes = 0;
    }
    
    //You need to implement this part.
    //destructor
    ~linked_list()
    {
        //cout << " Destructor is working " << endl;
        while (head != nullptr)
        {
            node<T> *ptr = head->next;
            delete head;
            head = ptr;
        }
        num_nodes = 0;
    }
    
    
    //copy constructor
    //for doubly linked list
    linked_list(const linked_list &obj)
    {
//        num_nodes = obj.num_nodes;
//        node<T> *objPtr = obj.head;
//        head = new node<T>;
//        //先开辟空间，再复制
//        while (objPtr != nullptr)
//        {
//            node<T> *new_node = new node<T>();
//            new_node->next = head;
//            head = new_node;
//            objPtr = objPtr->next;
//        }
//
//        objPtr = obj.head;
//        node<T> *ptr = head;
//
//        while (objPtr != nullptr)//这里有问题，多开辟了空间！
//
//        {
//            ptr->value = objPtr->value;
//
//            ptr = ptr->next;
//            objPtr = objPtr->next;
//        }

        
        head = tail = nullptr;
        if (obj.head == nullptr)
            return;

        node<T> *temp = obj.head->next;
        head = new node<T>(obj.head->value);
        tail = head;
        while (temp != nullptr)
        {
            node<T> *newNode = new node<T>(temp->value);
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
            temp = temp->next;
        }
    }

    
    //move constructor
    linked_list(linked_list &&obj)
    {
        num_nodes = obj.num_nodes;
        head = obj.head;
        obj.head = nullptr;
        obj.tail = nullptr;
    }
    
    
    //stream override
    friend ostream & operator<<(ostream &stream, const linked_list<T> &obj)
    {
        //cout << "Printing linked_list" << endl;
        
        node<T> *ptr = obj.head;
        while (ptr != nullptr)
        {
            stream << *ptr << " ";
            ptr = ptr->next;
        }
        
        return stream;
    }
    
    void push_back(const T &obj)
    {
        node<T> *new_node = new node<T>(obj);
        if (head == nullptr)
        {
            new_node->next = head;
            head = new_node;
            tail = head;
            num_nodes++;
            return;
        }
        else
        {
            node<T> *p = head;
            while (p->next != nullptr)
                p = p->next;
            tail = p;
            
            //Insert at tail
            tail->next = new_node;
            new_node->previous = tail;
            
            //Update tail
            tail = tail->next;
            tail->previous = new_node;
            
            num_nodes++;
            
            return;
        }
    }
    
    
    void push_front(const T &obj)
    {
        node<T> *ptr = new node<T>(obj);
        ptr->next = head;
        head = ptr;
        num_nodes++;
    }
    
    
    //left reference operator
    //Copy assignment operator= override
//    linked_list &operator=(linked_list &obj)
    void operator=(linked_list &obj)
    {
        num_nodes = obj.num_nodes;
        //delete this storage
        while (head != nullptr)
        {
            node<T> *p = head->next;
            delete head;
            head = p;
        }
        
        node<T> *ptr = obj.head;
        while (ptr != nullptr)
        {
            node<T> *new_node = new node<T>;
            new_node->next = head;
            head = new_node;
            ptr = ptr->next;
        }
        
        ptr = head;
        node<T> *objPtr = obj.head;
        while (objPtr != nullptr)
        {
            ptr->value = objPtr->value;
            
            ptr = ptr->next;
            objPtr = objPtr->next;
        }
//        return *this;
    }
    
    
    //Move assignment operator= override
    //Right Ref operator
//    linked_list &operator=(linked_list &&obj)
    void operator=(linked_list &&obj)
    {
        num_nodes = obj.num_nodes;
        
//        //delete this storage
//        while (head != nullptr)
//        {
//            node<T> *ptr = head->next;
//            delete head;
//            head = ptr;
//        }
        
        head = obj.head;
        tail = obj.tail;
        obj.head = nullptr;
        obj.tail = nullptr;
//        return *this;
    }
    
    bool operator==(const linked_list &obj)
    {
        node<T> *ptr = head;
        node<T> *objPtr = obj.head;
        bool result = true;
        
        if (this->num_nodes != obj.num_nodes)
        {
            return false;
        }
        
        else
        {
            while (ptr->next != nullptr)
            {
                if (ptr == objPtr)
                {
                    result &= true;
                }
                else
                    result = false;//
                
                ptr = ptr->next;
                objPtr = objPtr->next;
            }
            
            if (ptr == objPtr)
                result &= true;
            
            return result;
        }
    }
    
    
};



template <class X>
class item {
public:
    X value;
    item<X> *next;
    item<X> *previous;
    item<X>(X v) { value = v; next = nullptr; previous = nullptr; }
    
    
    friend ostream & operator<<(ostream &stream, const item<X> &obj)
    {
        //cout << "Printing item<X>" << endl;
        stream << obj.value;//
        return stream;
    }
    
};



template <class X>
class bag {
public:
    item<X> *last;
    item<X> *first;
    
    int num_items;
    int size() { return num_items; }
    bag() { last = nullptr; first = nullptr; num_items = 0; } //default constructor for bag class
    
    void push_back(X v)  //insert an item with value v to the back of the bag
    {
        item<X> *new_node = new item<X>(v);
        
        if (first == nullptr && last == nullptr)
        {
            new_node->next = first;
            first = new_node;
            last = first;
            
            num_items++;
            return;
        }

        else
        {
            item<X> *ptr = first;
            while (ptr->next != nullptr)
                ptr = ptr->next;
            last = ptr;
            
            //Insert at tail
            last->next = new_node;
            new_node->previous = last;
            
            //Update tail
            last = last->next;
            last->previous = ptr;
            
            num_items++;
        }
    }
    
    
    void push_front(X v) //insert an item with value v to the front of the bag
    {
        num_items++;
        item<X> *new_node = new item<X>(v);
        new_node->previous = nullptr;
        new_node->next = first;
        first = new_node;
    }
    
    
    void pop_back() //delete the last item in the bag
    {
        //pop_back
        if (first == nullptr)
        {
            num_items = 0;
            first = last = nullptr;
            return;
        }
        
        else
        {
            item<X> *ptr = first;
            
            while (ptr->next != nullptr)
                ptr = ptr->next;
            last = ptr;
            
            //update last
            last = last->previous;
            last->next = nullptr;
            
            //update item numbers
            num_items--;
            
        }
    }
    
    
    void pop_front() //delete the first item in the bag
    {
        //pop_front
        if (first == nullptr)
        {
            num_items = 0;
            first = last = nullptr;
            return;
        }

        else
        {
            //update first
            first = first->next;
            first->previous = nullptr;
            
            //update item numbers
            num_items--;
        }
    }
    
    
    X &operator[](int i) //Access bag item with index.
    {
        item<X> *ptr = first;
        
        for (int k = 0; k < i; k++)
        {
            ptr = ptr->next;
        }
        
        return ptr->value;
    }
    
    
    X front()
    {
        return first->value;
    }
    
    
    X back()
    {
        return last->value;
    }
    
    
    void clear() //Delete all items in the bag
    {
        //delete nodes except the first one
        num_items = 0;
        if (first == nullptr)
        {
            num_items = 0;
            first = last = nullptr;
            return;
        }
        
        item<X>* ptrNext = first->next;
        while (ptrNext != nullptr)
        {
            first->next = ptrNext->next;
            ptrNext->next = nullptr;
            free(ptrNext);
            ptrNext = first->next;
        }
        
        //delete the first item
        item<X> *temp = first;
        first = first->next;
        delete temp;
    }
    
    //find函数有问题
    item<X> * find(X I)//add this function
    {
        item<X> *ptr = first;
        item<X> *target = nullptr;
        if (first == nullptr)
            return nullptr;

        while (ptr != nullptr)
        {
            if (ptr->value == I)
            {
                target = ptr;
            }
            ptr = ptr->next;
        }
        return target;
    }
    
    
    void erase(int index)
    {
        if (first == nullptr)
            return;
        
        if (index == 0)
        {
            first = first->next;
            num_items--;
            return;
        }
        
        item<X> *current = first;
        
        int i = 0;
        while (current != nullptr && i < index - 1)
        {
            current = current->next;
            i++;
        }
        if (current == nullptr || current->next == nullptr) {
            return;
        }
        item<X> *next = current->next->next;
        
        current->next = next;
        
        
        num_items--;
    }
    
    
    
    
    
    void erase(item<X> * p)
    {
        if (first == p)
        {
            if (first->next == nullptr)
                return;
            
            first->value = first->next->value;
            
            p = first->next;
            
            first->next = first->next->next;
            free(p);
            num_items--;
            return;
        }
        
        item<X> *pre = first;
        while (pre->next != nullptr && pre->next != p)
            pre = pre->next;
        
        if (pre->next == nullptr)
            return;
        pre->next = pre->next->next;
        
        free(p);
        num_items--;
        return;
    }
    
    //implement pointer to an element and implement delete element using this pointer as parameter
    //bag1.erase(pointer);
    //also support bag1.erase(index);
    
    
    //You also need to implement cout <<bag1;
    
    friend ostream & operator<<(ostream &stream, const bag<X> &L)
    {
        //cout << "Printing bag" << endl;
        item<X> *ptr = L.first;
        while (ptr != nullptr)
        {
            stream << *ptr << " ";
            ptr = ptr->next;
        }
        return stream;
    }
    
    
    //copy constructor
//    bag(const bag <X> &obj)
//    {
//        num_items = obj.num_items;
//        item<X> *objPtr = obj.first;
//
//        while (objPtr != nullptr)
//        {
//            item<X> *new_item = new item<X>;
//            new_item->next = first;
//            first = new_item;
//            objPtr = objPtr->next;
//        }
//
//        objPtr = obj.first;
//        item<X> *ptr = first;
//
//        while (objPtr != nullptr)
//        {
//            ptr->value = objPtr->value;
//
//            ptr = ptr->next;
//            objPtr = objPtr->next;
//        }
//    }
    
    //Example provided by Prof
    bag(const bag &v)
    {
        /*
         first = nullptr;
         last = nullptr;
         num_items = 0;
         */
        item<X>* start = v.last;//
        while(start != nullptr)
        {
            this->push_front(start->value);
            start = start->next;
        }
    }

    
    
    //move constructor
    bag(bag <X>  &&obj)
    {
        num_items = obj.num_items;
        
        first = obj.first;
        obj.first = nullptr;
    }
    
    
    //copy operator=
//    bag &operator=(bag &obj)
    void operator=(bag &obj)
    {
        num_items = obj.num_items;
        
        //delete this storage
        while (first != nullptr)
        {
            item<X> *ptr = first->next;
            delete first;
            first = ptr;
        }
        
        item<X> *objPtr = obj.first;
        while (objPtr != nullptr)
        {
            item<X> *new_item = new item<X>;
            new_item->next = first;
            first = new_item;
            objPtr = objPtr->next;
        }
        
        objPtr = obj.first;
        item<X> *ptr = first;
        while (objPtr != nullptr)
        {
            ptr->value = objPtr->value;
            
            ptr = ptr->next;
            objPtr = objPtr->next;
        }
//        return *this;
    }
    
    
    //move operator
//    bag &operator=(bag &&obj)
    void operator=(bag &&obj)
    {
        num_items = obj.num_items;
        //delete this storage
        while (first != nullptr)
        {
            item<X> *ptr = first->next;
            delete first;
            first = ptr;
        }
        first = obj.first;
        obj.first = nullptr;
        
//        return *this;
    }
    
    
    ~bag()//destructor
    {
        //delete nodes except the first one
        //        item<X> *ptr = first;
        
        if (first == nullptr)
        {
            num_items = 0;
            first = last = nullptr;
            return;
        }
        
        item<X>* ptrNext = first->next;
        while (ptrNext != nullptr)
        {
            first->next = ptrNext->next;
            ptrNext->next = nullptr;
            free(ptrNext);
            ptrNext = first->next;
        }
        
        //delete the first item
        item<X> *temp = first;
        first = first->next;
        delete temp;
    }
    
};


//your program needs to support simple data type (int, double, string), template-based doubly linked list (as in HW2), template-based ThreeD, vector, list, map, etc.



int main() {
    
    bag<double> bag_d;
    bag_d.push_back(5.5);
    bag_d.push_back(6.6);
    bag_d.push_front(4.4);
    bag_d.push_front(3.3);
    bag_d.pop_front();
    bag_d.pop_back();
    cout << bag_d << endl;;
    
    
    bag<int> bag_i;
    bag_i.push_back(5);
    bag_i.push_back(6);
    bag_i.push_front(4);
    bag_i.push_front(3);
    bag_i.pop_front();
    bag_i.pop_back();
    cout << bag_i << endl;
    
    ThreeD<int> td3(3), td4(4), td5(5), td6(6), td7(100, 200, 300);
    bag<ThreeD<int>> bag_3D;
    bag_3D.push_back(td5);
    bag_3D.push_back(td6);
    bag_3D.push_front(td4);
    bag_3D.push_front(td3);
    bag_3D.pop_front();
    bag_3D.pop_back();
    cout << bag_3D << endl;;
    cout << bag_3D.front() << bag_3D.back();
    cout << bag_3D[0] << " " << bag_3D[1] << endl;
    bag_3D[1] = td7;
    cout << bag_3D[0] << " " << bag_3D[1] << endl;
    bag_3D.clear();
    cout << bag_3D << endl;;
    cout << bag_3D.size() << endl;
    
    
    linked_list<string>ls_1;
    ls_1.push_front("David");
    ls_1.push_front("John");
    ls_1.push_front("Pat");
    ls_1.push_front("Ben");
    ls_1.push_front("Jeff");
    cout << ls_1 << endl;
    
    linked_list<string>ls_2;
    ls_2.push_front("Wendy");
    ls_2.push_front("Mary");
    ls_2.push_front("Nancy");
    ls_2.push_front("Jennifer");
    cout << ls_2 << endl;
    
    bag<linked_list<string>> bag_string;
    
    bag_string.push_back(ls_1);
    
    bag_string.push_back(ls_2);
    
    cout << bag_string << endl;
    cout << bag_string[1] << endl;
    
    ThreeD<double> t10(3.2, 7.4, 8.9), t11(5.6, 7.7, 2.987), t12(4.6, 7.5, 3.1416), t13(55.6, 66.8, 333.45);
    linked_list<ThreeD<double>> LTD1;
    LTD1.push_front(t10);
    
    LTD1.push_front(t11);
    linked_list<ThreeD<double>> LTD2;
    LTD2.push_front(t13);
    LTD2.push_front(t12);
    LTD2.push_front(t10);
    LTD2.push_front(t11);
    
    bag<linked_list<ThreeD<double> > > BLTD;
    BLTD.push_back(LTD1);
    BLTD.push_back(LTD2);
    cout << BLTD << endl;
    
    item<linked_list<ThreeD<double>>> * p2;
    
    cout << "=====================" << endl;
    cout << "Print LTD1" << endl;
    cout << LTD1 << endl;
    cout << "=====================" << endl;
    
    cout << "=====================" << endl;
    cout << "Print LTD2" << endl;
    cout << LTD2 << endl;
    cout << "=====================" << endl;
    
    p2 = BLTD.find(LTD1);//find有问题
    cout << "=====================" << endl;
    //print find content
    cout << "Print P2: " << endl;
    cout << p2 << endl;//有问题，找不到p2！返回为0x00
    
    cout << "=====================" << endl;
    cout << "BLTD.erase(p2)" << endl;//erase有问题，未能抹去p2
    BLTD.erase(p2);
    cout << "Printing BLTD" << endl;
    cout << BLTD << endl;
    cout << "=====================" << endl;

    BLTD.push_back(LTD1);
    cout << "Printing BLTD" << endl;
    cout << BLTD << endl;
    cout << "BLTD.erase(0)" << endl;
    BLTD.erase(0);
    cout << "Printing BLTD" << endl;
    cout << BLTD << endl;
    
    getchar();
    getchar();
    return 0;
}
