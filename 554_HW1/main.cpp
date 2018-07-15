//HW1  Polynomial Operations using linked lists

//Due 11:59 pm, February 2 (Friday)
//
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
//	int i = 0;//my code
	while (p != nullptr) {
		cout << p->coef << " " << p->power << "   ";
		p = p->next;
//		i++;
//		cout << "Hello World!" << endl;//My code
//		cout << "This is the " << i << "th count." << endl;
//		cout << "p points to address: " << p << endl;//My code
//		cout << "p->next points to address: " << p->next << endl;//My code
	}
}


void polynomial::add_term(int c, int p)
{
	//按Power从大到小
	//term *p1, *p2;
	//Do not do sorting, just do it while adding a term
	term *new_term = new term(c, p);
	term *p1, *p2, *temp;
	p1 = head;
	p2 = head->next;

	//Add nodes to linked list
	//add from head
//	new_term->next = head;
//	head = new_term;//head->next指向先前的head
//	num_terms++;


	if( head == nullptr)
	{
		cout << "Hello" << endl;
		head = new_term;
		num_terms++;
	}

//	if( num_terms > 0)
//	{
//		head->next = new_term;
//		head = head->next;
//		num_terms++;
//	}


//	while (p2 != nullptr)//无法跳出，因为p2无论怎么指都无法为nullptr
//	if( p2 != nullptr )
//	{
//		if( p1->power < p2->power)
//		//若左侧power比右侧power更小，则交换左右node
//		//交换后，右侧值应继续与右侧比较大小！！！
//		{
//			cout << "swap" << endl;
//			//p1 p2 交换节点
//			temp = p1;
//			p1 = p2;
//			p2 = temp;
//
//		}
//
//		if( p1->power == p2->power )
//		{
////			cout << "equal" << endl;
//			p1->coef += p2->coef;
//		}
//		head = p1;//此时的p2是原来的head
//	}

	//head->next = p2;//因为p1与p2已经被交换，所以此时p2指向p1,即指向head
	//所以打印出的结果是*head *head->next *head *head->next无限循环...
	//因为head是新的，而我们并没有给head->next赋值

}




//polynomial polynomial::operator+(polynomial P)
//{
//
//}
//
//polynomial polynomial::operator*(polynomial P)
//{
//
//}


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
//	cout << endl;
//	cout << "Enter numer of terms" << endl;
//	cin >> num_t;
//	cout << "Enter all terms" << endl;
//	for (int i = 0; i < num_t; i++) { //You don't need to check for input error
//		int c, p;
//		cin >> c >> p;
//		p2.add_term(c, p);
//	}
//	p2.print_polynomial();
//	p3 = p1 + p2;
//	p3.print_polynomial();
//	p4 = p1 * p2;
//	p4.print_polynomial();
	getchar();
	getchar();
	return 0;
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
