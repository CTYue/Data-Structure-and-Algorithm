//CSE674 HW7
//Due : Tuesday 12 /
//5 at 11 : 59

#include <iostream>
#include <vector>
using namespace std;

class node
{
	//for simplicity, we again assume all numbers are distinct
  public:
	int num_values;
	vector<int> value; //it can contain 1 ... 3 values
	node *parent;
	vector<node *> child; //child[i] ( i = 0 ... 3) is a pointer to child node i
	int child_state;	  //a node can have up to 4 child nodes: child 0, 1, 2, 3.  child_state i (0 ... 3) means this node is child i of its parent
	int is_leaf;		  //1 if this is a leaf node; otherwise 0
	node()
	{
		num_values = 0;
		is_leaf = 1;
		child.assign(4, nullptr);
		parent = nullptr;
		value.assign(3, -999);
	}
	void add_value(int k);	//add value to a node of less than 3 value
	void remove_value(int k); //remove value from a node of more than 1 value
};

void node::add_value(int k)
{
	if (num_values == 0)
	{
		num_values = 1;
		value[1] = k;
	}
	if (num_values == 1)
	{
		num_values = 2;
		if (value[1] > k)
		{
			value[2] = value[1];
			value[1] = k;
		}
		else
			value[2] = k;
	}
	else
	{
		num_values = 3;
		if (k < value[1])
		{
			value[3] = value[2];
			value[2] = value[1];
			value[1] = k;
		}
		if (k < value[2])
		{
			value[3] = value[2];
			value[2] = k;
		}
		else
			value[3] = k;
	}
}
void node::remove_value(int k)
{
	if (value[1] == k)
	{
		value[1] = value[2];
		value[2] = value[3];
		value[3] = -999;
	}
	if (value[2] == k)
	{
		value[2] = value[3];
		value[3] = -999;
	}
	if (value[3] == k)
	{
		value[3] = -999;
	}
	num_values--;
}

class two34_tree
{
  public:
	node *root;
	two34_tree() { root = nullptr; }
	void add(int k);
	node *find(int k);				   //find a node to add value k; invoked by add
	node *break_3_value_node(node *p); //to be invoked by find
	void remove(int k);
	node *find_1(int k);			   //find a node to replace k once k is removed; invokde by remove
	void expand_1_value_node(node *p); //to be invoked by find_1
	void fusion(node *p);			   //to be invoked by exapnd_1_value_node
	void rotation(node *p);			   ////to be invoked by exapnd_1_value_node
	void in_order_traversal(node *p);
};

node *two34_tree::find_1(int k)
{
	node *ptr = root;
	int v1, v2, v3, t = 0;
	//int v4;
	while (ptr->is_leaf == 0)
	{
		v1 = ptr->value[1];
		if (ptr->num_values > 1)
			v2 = ptr->value[2];
		else
			v2 = 999;
		if (ptr->num_values > 2)
			v3 = ptr->value[3];
		else
			v3 = 999;
		if (k < v1)
			ptr = ptr->child[0];
		if (k == v1 || k == v2 || k == v3)
			break;
		else if (k < v2)
			ptr = ptr->child[1];
		else if (k < v3)
			ptr = ptr->child[2];
		else
			ptr = ptr->child[3];
	}

	if (ptr->is_leaf != 1)
	{
		node *p = new node();
		if (k == ptr->value[1])
		{
			p = ptr->child[0];
			t = 1;
		}
		else if (k == ptr->value[2])
		{
			p = ptr->child[1];
			t = 2;
		}
		else if (k == ptr->value[3])
		{
			p = ptr->child[2];
			t = 3;
		}
		while (p->is_leaf != 1)
		{
			if (p->num_values > 2)
				p = p->child[3];
			else if (p->num_values > 1)
				p = p->child[2];
			else
				p = p->child[1];
		}
		if (p->num_values == 3)
		{
			int temp = ptr->value[t];
			ptr->value[t] = p->value[3];
			p->value[3] = temp;
			return p;
		}
		else if (p->num_values == 2)
		{
			int temp = ptr->value[t];
			ptr->value[t] = p->value[2];
			p->value[2] = temp;
			return p;
		}
		else if (p->num_values == 1)
		{
			int temp = ptr->value[t];
			ptr->value[t] = p->value[1];
			p->value[1] = temp;
		}
		ptr = p;
	}

	node *prt = ptr->parent;
	int d = ptr->child_state;
	int d1 = d - 1;
	int r = 1;
	if (d1 > -1)
	{
		if (prt->child[d1]->num_values > 1)
		{
			int k1 = prt->child[d1]->num_values;
			prt->child[d1]->value[k1] = -999;
			prt->child[d1]->num_values = prt->child[d1]->num_values - 1;
			ptr->num_values = ptr->num_values + 1;
			ptr->value[2] = ptr->value[1];
			ptr->value[1] = prt->value[d];
			prt->value[d] = v2;
			r = 0;
		}
	}

	if (r == 1)
	{
		d1 = d1 + 2;
		if (d1 <= prt->num_values)
		{
			if (prt->child[d1]->num_values > 1)
			{
				int k2 = prt->child[d1]->value[1];
				prt->child[d1]->value[1] = prt->child[d1]->value[2];
				prt->child[d1]->value[2] = prt->child[d1]->value[3];
				prt->child[d1]->value[3] = -999;
				prt->child[d1]->num_values = prt->child[d1]->num_values - 1;
				ptr->num_values = ptr->num_values + 1;
				ptr->value[2] = prt->value[d + 1];
				prt->value[d + 1] = k2;
				r = 0;
			}
		}
	}

	if (r == 1)
		fusion(ptr);

	return ptr;
}

void two34_tree::add(int k)
{
	node *p = find(k);
	p->add_value(k);
}

node *two34_tree::find(int k)
{
	int v1, v2, v3;
	node *temp = root;

	if (temp == nullptr)
	{
		temp = new node();
		root = temp;
		return (temp);
	}

	while (temp != nullptr)
	{
		if (temp->num_values == 3)
		{
			temp = break_3_value_node(temp);
		}
		if (temp->is_leaf == 1)
			return (temp);
		v1 = temp->value[1];
		if (temp->num_values > 1)
			v2 = temp->value[2];
		else
			v2 = 9999;
		if (temp->num_values > 2)
			v3 = temp->value[3];
		else
			v3 = 9999;
		if (k < v1)
			temp = temp->child[0];
		if (k < v2)
			temp = temp->child[1];
		if (k < v3)
			temp = temp->child[2];
		else
			temp = temp->child[3];
	}
}

void two34_tree::fusion(node *p)
{
	node *ptr = p->parent;
	node *p0 = new node();

	if (ptr->num_values == 1)
		if (ptr != root)
			fusion(ptr);

	if (p->child_state > 0)
		p0 = ptr->child[p->child_state - 1];

	if (p->child_state < ptr->num_values)
		p0 = ptr->child[p->child_state + 1];

	p->num_values = 3;

	if (p->value[1] > p0->value[1])
	{
		p->value[3] = p->value[1];
		p->value[1] = p0->value[1];

		if (p->child[0] != nullptr)
			p->child[2] = p->child[0];

		if (p->child[1] != nullptr)
			p->child[3] = p->child[1];

		if (p0->child[0] != nullptr)
			p->child[0] = p0->child[0];

		if (p0->child[1] != nullptr)
			p->child[1] = p0->child[1];
	}
	else
	{
		p->value[3] = p0->value[1];

		if (p0->child[0] != nullptr)
			p->child[2] = p0->child[0];

		if (p0->child[1] != nullptr)
			p->child[3] = p0->child[1];
	}

	int temp = p->child_state + p0->child_state + 1;
	p->value[2] = ptr->value[temp / 2];

	ptr->num_values--;

	if (ptr->num_values == 0)
	{
		root = p;
		p->parent = nullptr;
	}

	else
	{
		int n1 = p->child_state;
		int n2 = p0->child_state;
		int n = (n1 + n2 + 1) / 2;

		if (n == 1)
		{
			ptr->value[1] = ptr->value[2];
			ptr->value[2] = ptr->value[3];
			ptr->value[3] = -999;
			ptr->child[0] = p;
			ptr->child[0]->child_state = 0;
			ptr->child[1] = nullptr;

			if (ptr->child[2] != nullptr)
			{
				ptr->child[1] = ptr->child[2];
				ptr->child[1]->child_state = 1;
				ptr->child[2] = nullptr;
			}

			if (ptr->child[3] != nullptr)
			{
				ptr->child[2] = ptr->child[3];
				ptr->child[2]->child_state = 2;
				ptr->child[3] = nullptr;
			}
		}

		if (n == 2)
		{
			ptr->value[2] = ptr->value[3];
			ptr->value[3] = -999;
			ptr->child[2] = nullptr;
			ptr->child[1] = p;
			ptr->child[1]->child_state = 1;

			if (ptr->child[3] != nullptr)
			{
				ptr->child[2] = ptr->child[3];
				ptr->child[2]->child_state = 2;
				ptr->child[3] = nullptr;
			}
		}

		if (n == 3)
		{
			ptr->child[2] = p;
			ptr->child[2]->child_state = 2;
			ptr->child[3] = nullptr;
			ptr->value[3] = -999;
		}
	}
}

void two34_tree::remove(int k)
{
	node *p = find_1(k);
	p->remove_value(k);
}

void two34_tree::in_order_traversal(node *p)
{
	cout << endl;
	node *p1 = p;
	if (p1 == nullptr)
		return;
	int i;
	for (i = 0; i < p1->num_values; i++)
	{
		in_order_traversal(p1->child[i]);
		cout << "  " << p1->value[i + 1] << "  "
			 << "child_state = " << p1->child_state;
	}
	in_order_traversal(p1->child[i]);
}

int main()
{
	//The following is just an example.
	//Different test casess can be used during grading.
	two34_tree t1;
	t1.add(40);
	t1.add(30);
	t1.add(20);
	t1.in_order_traversal(t1.root);
	t1.add(100);
	t1.add(120);
	t1.in_order_traversal(t1.root);
	t1.add(200);
	t1.in_order_traversal(t1.root);
	t1.add(400);
	t1.in_order_traversal(t1.root);
	t1.add(600);
	t1.in_order_traversal(t1.root);
	t1.remove(20);
	t1.in_order_traversal(t1.root);
	t1.remove(200);
	t1.in_order_traversal(t1.root);
	t1.remove(100);
	t1.in_order_traversal(t1.root);
	getchar();
	getchar();
	return 0;
}
