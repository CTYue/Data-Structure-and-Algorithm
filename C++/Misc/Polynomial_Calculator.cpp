//A polynomial is implemented using a linked list.  Only non-zero coefficients are included in linked list.
//Implment member functions operator+ , operator* , and add term
//
//You have to use the main function and print_linked_list provided to you.

#include <iostream>

using namespace std;

class term {
public:
    int power;
    int coef;
    term * next;
    term() { next = nullptr; }
    term(int c, int p) { power = p; coef = c; next = nullptr; }
};

class polynomial {
public:
    int num_terms;
    term * head;
    polynomial() { num_terms = 0; head = nullptr; }
    
    void add_term(int c, int p);
    //If the polynomial does not contain a term with power p,
    //then add this new term.
    //If the polynomial contains a term with power p,
    //then add c to the existing coef.
    
    polynomial operator+(polynomial P);
    polynomial operator*(polynomial P);
    void print_polynomial();
};


void polynomial::print_polynomial() {
    cout << endl;
    term * p = head;
    while (p != nullptr) {
        cout << p->coef << " " << p->power << "   ";
        p = p->next;
        
    }
}


void polynomial::add_term(int c, int p)
{
    //Descending according to the value of power
    term *new_term = new term(c, p);
    term *ptr;
    
    //Add nodes to linked list
    //add to head
    new_term->next = head;
    head = new_term;
    
    ptr = head->next;
    head->next = nullptr;
    
    while (ptr != nullptr)
    {
        term *pNext = ptr->next;//Store the next position
        term *q = head;
        //q points to head while ptr points to head->next
        //delete node which has a zero coef
        
        while( q != nullptr && q->next != nullptr )
        {
            if( q->coef == 0)
            {
                if(q->next != nullptr)
                {
                    term * temp = q;
                    temp = temp->next;
                    head = ptr;
                    delete temp;
                }
            }
            
            q = q->next;
        }
        
        q = head;
        
        if (ptr->power == q->power)
        {
            term *temp = q;
            ptr->coef += temp->coef;
            temp = temp->next;
            head = ptr;
            delete temp;
        }
        
        if (ptr->power > q->power)//if previous power is biggger than the new power, then swap
        {
            ptr->next = q;
            head = ptr;
        }
        
        else
        {
            while ( q != nullptr && q->next != nullptr && q->next->power > ptr->power)
            {
                q = q->next;
            }
            ptr->next = q->next;
            q->next = ptr;
        }
        ptr = pNext;
    }
}

polynomial polynomial::operator+(polynomial P)
{
    //Sample code from Prof
    polynomial temp_p;
    term * p1 = head, *p2 = P.head;
    while (p1 != nullptr || p2 != nullptr) {
        if (p1 == nullptr) { temp_p.add_term(p2->coef, p2->power); p2 = p2->next; }
        else if (p2 == nullptr) { temp_p.add_term(p1->coef, p1->power); p1 = p1->next; }
        else if (p1->power < p2->power) { temp_p.add_term(p2->coef, p2->power); p2 = p2->next; }
        else if (p1->power > p2->power) { temp_p.add_term(p1->coef, p1->power); p1 = p1->next; }
        else if (p1->power == p2->power) {
            if ((p1->coef + p2->coef) != 0) {
                temp_p.add_term(p1->coef + p2->coef, p1->power);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return temp_p;
}


polynomial polynomial::operator*(polynomial P)
{
    //Sample code from Prof
    polynomial temp_p;
    term * p1 = head, *p2;
    for (int i = 0; i < num_terms; i++) {
        p2 = P.head;
        for (int j = 0; j < P.num_terms; j++) {
            temp_p.add_term(p1->coef * p2->coef, p1->power + p2->power);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return temp_p;

}

/*
 //An example screenshot is given below:
 //Different cases may be used during grading
 
 Enter numer of terms
 3
 Enter all terms
 2 2 1 1 4 0
 
 2 2   1 1   4 0
 Enter numer of terms
 2
 Enter all terms
 -6 1 3 0
 
 -6 1   3 0
 2 2   -5 1   7 0
 -12 3   -21 1   12 0
 */


int main() {
    polynomial p1, p2, p3, p4, p5, p6;
    int num_t;
    cout << "Enter numer of terms" << endl;
    cin >> num_t;
    cout << "Enter all terms" << endl;
    for (int i = 0; i < num_t; i++) { //You don't need to check for input error
        int c, p;
        cin >> c >> p;
        p1.add_term(c, p);
    }
    p1.print_polynomial();
    
    cout << endl;
    cout << "Enter numer of terms" << endl;
    cin >> num_t;
    cout << "Enter all terms" << endl;
    for (int i = 0; i < num_t; i++) { //You don't need to check for input error
        int c, p;
        cin >> c >> p;
        p2.add_term(c, p);
    }
    p2.print_polynomial();
    p3 = p1 + p2;
    p3.print_polynomial();
    p4 = p1 * p2;
    p4.print_polynomial();
    getchar();
    getchar();
    return 0;
}