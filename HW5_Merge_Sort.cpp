//HW5 CSE674
//Due: Sunday (Nov. 5) at 11:59PM
//You need to implement the following three functions
//
//void merge_sort(node * p, int i);
//void merge(node * p1, int i1, node * p2, int i2);
//void merge_sort(vector<int> &V);
//Read the requirements stated below.

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class node
{
  public:
	int value;
	node *next;
	node() { next = nullptr; }
	node(int i)
	{
		value = i;
		next = nullptr;
	}
};

class linked_list
{
  public:
	int num_nodes;
	node *head;
	linked_list()
	{
		num_nodes = 0;
		head = nullptr;
	}
	void make_list(int k, int m);
	void print();
	//****************************************************************************************************************************************
	//    void merge_sort(node * p, int i); //Sort the portion (i nodes) of linked list beginning at the node pointed by p.
	//You will implement the algoeithm using a recursive approach.
	//In-place merge sort is required; that is, you are not allowed to create a separate linked list, etc. to perform sorting.

	//You need to also implement the following merge funciton, which
	//merges two already sorted porttion of linked list beginning at nodes pointed by p1 and p2, with sizes being i1 nodes and i2 nodes, respectively.
	//Assume that these two portions are adjacent.
	//That is, the last node of the first portion is immediately followed by the first node of the second portion.

	//    void merge(node * p1, int i1, node * p2, int i2);
	//*******************************************************************************************************************************************
};

void linked_list::make_list(int k, int m)
{
	for (int i = 0; i < k; i++)
	{
		node *p = new node(rand() % m);
		p->next = head;
		head = p;
		num_nodes++;
	}
}

void linked_list::print()
{
	node *p = head;
	cout << endl;
	while (p != nullptr)
	{
		cout << p->value << " ";
		p = p->next;
	}
}

void make_random_vector(vector<int> &V, int k, int m)
{
	for (int i = 0; i < k; i++)
		V.push_back(rand() % m);
}

//***********************************************************************************************************************
void merge(vector<int> &V, size_t left, size_t middle, size_t right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int number = V.size();

	vector<int> leftArr;
	vector<int> rightArr;
	leftArr.resize(number);
	rightArr.resize(number);

	for (i = 0; i < n1; i++)
	{
		leftArr[i] = V[left + i];
	}
	for (j = 0; j < n2; j++)
	{
		rightArr[j] = V[middle + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			V[k] = leftArr[i];
			i++;
		}

		else
		{
			V[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		V[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		V[k] = rightArr[j];
		j++;
		k++;
	}
}

void merge_sort(vector<int> &V) //Using iterative (i.e., non_recursive) approach to implement merge sort.
{
	int current_size = 0;
	int left_start = 0;
	int right_end = 0;
	int mid = 0;

	for (current_size = 1; current_size <= V.size() - 1; current_size = (2 * current_size))
	{
		for (left_start = 0; left_start < V.size() - 1; left_start += (2 * current_size))
		{
			mid = left_start + current_size - 1;

			if ((left_start + 2 * current_size - 1) < (V.size() - 1))
			{
				right_end = left_start + 2 * current_size - 1;
			}
			else
			{
				right_end = V.size() - 1;
			}

			merge(V, left_start, mid, right_end);
		}
	}
}

//Non in-place algorithm

//***********************************************************************************************************************

int main()
{

	vector<int> V;
	make_random_vector(V, 50, 40);
	cout << endl;
	cout << "Input" << endl;
	for (size_t i = 0; i < V.size(); i++)
		cout << V[i] << " ";
	merge_sort(V);
	cout << endl;
	cout << "Output" << endl;
	for (size_t i = 0; i < V.size(); i++)
		cout << V[i] << " ";

	//    linked_list L1;
	//    L1.make_list(30, 20);
	//    L1.print();
	//    L1.merge_sort(L1.head, L1.num_nodes);
	//    L1.print();

	getchar();
	getchar();
	return 0;
}
