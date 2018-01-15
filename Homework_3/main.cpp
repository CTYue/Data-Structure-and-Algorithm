//Dijkstra's algorithm by C-Y (Roger) Chen, Syracuse University
//Implemented with min-Heap
//Time Complexity O(N + E log N)

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
class e_node { //stands for edge node
public:
	int nb;//the neighbor of a currently considered node
	int weight; //weight of the edge to the above neighbor
	e_node() {}//constructor
};
class rt_node { //rt stands for routing table
public:
	int cost;  //cost to a node
	int from;  //the from node to this node
	int checked;
	int h_pos; //the postion in heap for this node
	rt_node() { from = -1;  cost = 9999;  checked = 0; }
};
class h_node { //stands for heap_node
public:
	int id;
	int cost;
	h_node() { id = -1; cost = 9999; }
	h_node(int i, int j) { id = i; cost = j; }
	bool operator<(h_node h) { return (cost < h.cost); }
};
void set_up(vector<rt_node> &rt, vector<h_node> & heap, int &start);
//Insert the souce node to heap and update rt and heap accordingly
void heap_adjust_up(vector<rt_node> &rt, vector<h_node> & heap, int &n);
void heap_adjust_down(vector<rt_node> & rt, vector<h_node> & heap);
void heap_op(vector<vector<e_node> > & graph, vector<rt_node> & rt, vector<h_node> &heap, vector<vector<int> > &table);

int main(){

	ifstream in("text1.txt");
	int start;
	in >> start;	//source node for the Dijkstra's algorithm
	int n, e; 	//n: num of nodes ; e: num of edges
	in >> n >> e;
	vector<int> vint(n);
	vector<vector<int> > table(n, vint);
	vector<e_node> ve;
	vector<vector<e_node> > graph(n, ve);
	e_node e1;
	int n1, n2, w;
	for (int i = 0; i < e; i++) {
		in >> n1 >> n2 >> w;//
		e1.nb = n2;//neighbor
		e1.weight = w;//weight
		graph[n1].push_back(e1);
	}
	in.close();
	vector<rt_node> rt(n); //rt stands for routing table
	vector<h_node> heap(n);
	heap_op(graph, rt, heap, table);

//	for (int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < n; j++)
//		{
//		   cout << "cost from " << i << " to " << j << " is: " << table[i][j] << endl;
//		}
//	}

	for(int i = 0 ; i < n; i++)
	{
		cout << "Cost from " << rt[i].from << " to " << i << " is " << rt[i].cost << endl;
	}

	getchar();
	getchar();
	return 0;
}


void set_up(vector<rt_node> &rt, vector<h_node> & heap, int &start) {

	rt[start].from = start;
	rt[start].cost = 0;
	for (size_t i = 0; i < heap.size(); i++) {
		heap[i].id = i;
		rt[i].h_pos = i;
	}
	heap[start].id = 0;
	heap[0].id = start;
	heap[0].cost = 0;
	rt[0].h_pos = start;
	rt[start].h_pos = 0;
}

void heap_adjust_down(vector<rt_node> & rt, vector<h_node> & heap)
{
	int last = heap.size() - 1;//swap the root with last node
	heap[0].id = heap[last].id;
	heap[0].cost = heap[last].cost;
	heap.pop_back();	//delete the last node
	size_t currentNode = 0, currentChild = 0;//define current node and

	if( heap.size() == 2 )//if there are only two node in the heap
		{
			currentChild = 2 * currentNode + 1;//id of the left Child
		}

	if( heap.size() > 2 )
	{
		if( heap[2*currentNode + 1 ].cost < heap[2*currentNode +2].cost )
		{
			currentChild = 2 * currentNode + 1;//id of the right Child
		}
	}

	else// when size of heap=1 or size > 2 but right child is smaller than left child
		{
			currentChild = 2 * currentNode + 2; //id of right Child
		}

	while ( currentChild < heap.size() )
    {
		if (heap[currentNode].cost > heap[currentChild].cost)
        {//exchange nodes
			int childId = heap[currentChild].id;
			int childCost = heap[currentChild].cost;
			heap[currentChild].id = heap[currentNode].id;
			heap[currentChild].cost = heap[currentNode].cost;// swap parent node with child node
			rt[currentNode].h_pos = currentChild;//update it to routing table
			heap[currentNode].id = childId;
			heap[currentNode].cost = childCost;
			rt[currentChild].h_pos = currentNode;
			currentNode = currentChild;
			if (heap.size() == 2*currentNode + 1)
				{
					currentChild = 2*currentNode + 1;
				}
			if( heap.size() > 2*currentNode + 2 )
				{
					if(heap[2*currentNode + 1].cost < heap[2*currentNode + 2].cost)
						{
							currentChild = 2*currentNode + 1;
						}
				}
			else currentChild = 2*currentNode + 2;
		}
		else break;
	}
}

void heap_adjust_up(vector<rt_node> & rt, vector<h_node> & heap, int &n)
{
	int currentParent = -1, currentNode = -1;
	for (size_t i = 0; i < heap.size(); i++)
	{
		if (heap[i].id == n)
		{
			currentNode = i;
			break;
		}
	}
	if (currentNode == 0)
	{
		return;
	}
	currentParent /= 2;
	while ( currentNode > 0)
	{
		if (heap[currentNode].cost < heap[currentParent].cost)
		{
			int parentId = heap[currentParent].id;
			int parentCost = heap[currentParent].cost;
			heap[currentParent].id = heap[currentNode].id;
			heap[currentParent].cost = heap[currentNode].cost;
			rt[currentNode].h_pos = currentParent;
			heap[currentNode].id = parentId;
			heap[currentNode].cost = parentCost;
			rt[currentParent].h_pos = currentNode;
			currentNode = currentParent;
			currentParent /= 2;
		}
		else
			{
				break;
			}
	}
}

void heap_op(vector<vector<e_node> > & graph, vector<rt_node> & rt, vector<h_node> &heap, vector<vector<int> > &table)
{
	for (int i = 0; i < rt.size(); i++ )
	{
		set_up( rt, heap, i);
		int checkedNode = heap[0].id; //Check from root
		rt[checkedNode].checked = 1;  //mark checked node with 1
		heap_adjust_down(rt, heap);//
		for (auto currentNeighbor : graph[checkedNode])
		{
			int neighborId = currentNeighbor.nb;
			if (rt[neighborId].cost > (rt[checkedNode].cost + currentNeighbor.weight))
			{
					rt[neighborId].cost = rt[checkedNode].cost + currentNeighbor.weight;
					rt[neighborId].from = checkedNode;
					heap_adjust_up(rt, heap, (int&)neighborId);
			}
		}
//		for(int j = 0; j < rt.size(); j++)
//		{
//			table[i][j] = rt[j].cost;
//		}
	}
}
