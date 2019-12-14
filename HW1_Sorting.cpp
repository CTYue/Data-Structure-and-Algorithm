//Homework 1 for CSE674
//Zidong Yu
//SUID:665530525
//zyu107@syr.edu

//HW1
//Implement the three member functions of linked_list class: sort, remove_all, and insert
//as described in the code blow
//Due: 11:59pm, Friday, September 8
//Submit a text vesion of your program to blackboard
//Linked List Examples by C-Y (Roger) Chen, Syracuse University

#include <fstream>
#include <iostream>
//#include <time.h>
using namespace std;

ofstream out("data1.txt");

class node {
public:
	int value;
	node * next;
	node() { next = nullptr; }
	node(int k) { value = k; next = nullptr; }
};

class linked_list {
public:
	int num_nodes;
	node * head;
	linked_list() { num_nodes = 0; head = nullptr; }
	void make_random_list(int k);//create a linked list of
								 //k nodes with values in 0 ..99 randomly

	void new_make_random_list(int k, int m);//create a linked list of
											//k nodes with values in 0 .. m randomly

	void print(); //Print values of all nodes from head node

	void selection_sort(); //Sort the nodes, based on ascending order of node values

	void bubble_sort();
	void insertion_sort();
};

void linked_list::make_random_list(int k) {
	node * p;
	for (int i = 0; i < k; i++) {
		p = new node(rand() % 100);
		p->next = head;
		head = p;
		num_nodes++;
	}

}

void linked_list::new_make_random_list(int k, int m) {
	node * p;
	for (int i = 0; i < k; i++) {
		p = new node(rand() % m);
		p->next = head;
		head = p;
		num_nodes++;
	}
}


void linked_list::print() {
	node * p = head;
	out << endl;
	while (p != nullptr) {
		out << p->value << " ";
		p = p->next;
	}
}

void linked_list::selection_sort()
{
	if ( num_nodes <= 1 )
		{
			return;
		}

	node *startNode = head;
	node *endNode = startNode;//End node of the sorted subarray

	while ( endNode->next != nullptr )
	{
		node *minNode = endNode->next;//minimum node of the unsorted array
		node *p = endNode->next->next;

		while ( p != nullptr )//Find minimum node in unsorted subarray
		{
			if ( p->value < minNode->value )
				{
					minNode = p;
				}
			p = p->next;
		}
		//swap(endNode->next->value, minNode->value);
		int temp = 0;
		temp = endNode->next->value;
		endNode->next->value = minNode->value;
		minNode->value =temp;

		endNode = endNode->next;
	}
		head =startNode->next;
}

void linked_list::bubble_sort()
{
	if ( num_nodes <= 1 )
	{
		return;
	}

	node *previousNode = head;
	node *currentNode = head->next;
	for (int i = 0; i < num_nodes; i++)
	{
        while ( currentNode != nullptr )
		{
			if ( previousNode->value > currentNode->value)
			{
				//swap(currentNode->value, previousNode->value);
				int temp = 0;
				temp = currentNode->value;
				currentNode->value = previousNode->value;
				previousNode->value = temp;
			}
			else
			{
				previousNode = currentNode;
				currentNode = previousNode->next;
			}
		}
			previousNode = head;
			currentNode = previousNode->next;
	}
}

void linked_list::insertion_sort()
{
	if ( num_nodes <= 1 )
	{
		return;
	}

    node *previousNode = head;
    node *currentNode = head->next;

    while (currentNode != nullptr)
    {
        if ( currentNode->value >= previousNode->value )
        //if current number is larger than or equals to the previous one, we just move to next number
        {
            currentNode = currentNode->next;//current node move to next input number
            previousNode = previousNode->next;//previous node move to next input number
        }
        //Assuming the smallest number is at the beginning of array
        else//if current number is smaller than the previous one,compare it with previous numbers
        	{
            if ( currentNode->value <= head->value )
            //if current number is smaller than or equal to the smallest one, replace the smallest one
            {
                previousNode->next = currentNode->next;//Move forward
                currentNode->next = head;//move current number to the most left position
                head = currentNode;//Now current position is the most left position
            }
            else//if current number is larger than the smallest one, compare it to the number next to
            	//the smallest one
            	{
                	node *p = head;
                	while ( currentNode->value > p->next->value && p->next != nullptr)
                {
                	p = p->next;
                }

                previousNode->next = currentNode->next;
                currentNode->next = p->next;
                p->next = currentNode;
            	}
        	}
        currentNode = previousNode->next;
    }
}

int main() {

	//Some examples of tests for your program are given below
	//During grading, other test cases will also be used

	linked_list L1;
	L1.make_random_list(70);
	L1.print();
	L1.bubble_sort();
	L1.print();

	cout << endl;

	linked_list L2;
	L2.make_random_list(70);
	L2.print();
	L2.selection_sort();
	L2.print();

	cout << endl;

	linked_list L3;
	L3.make_random_list(70);
	L3.print();
	L3.insertion_sort();
	L3.print();

	out.close();
	return 0;

}
