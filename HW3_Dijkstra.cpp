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

void set_up(vector<rt_node> &rt, vector<h_node> & heap, int &start); //Insert the souce node to heap and update rt and heap accordingly
void heap_adjust_up(vector<rt_node> &rt, vector<h_node> & heap, int &n);
void heap_adjust_down(vector<rt_node> & rt, vector<h_node> & heap);
void heap_op(vector<vector<e_node> > & graph, vector<rt_node> & rt, vector<h_node> &heap);

int main() {

	ifstream in("text1.txt");
	int start;
	in >> start;//source node for the Dijkstra's algorithm
	int n, e; //n: num of nodes ; e: num of edges
	in >> n >> e;
	vector<e_node> ve;
	vector<vector<e_node> > graph(n, ve);
	e_node e1;
	int n1, n2, w;
	for (int i = 0; i < e; i++) {
		in >> n1 >> n2 >> w;
		e1.nb = n2;
		e1.weight = w;
		graph[n1].push_back(e1);
	}
	in.close();
	vector<rt_node> rt(n); //rt stands for routing table
	vector<h_node> heap(n);
	
	set_up(rt, heap, start);
	heap_op(graph, rt, heap);

	for (int i = 0; i < n; i++) {

		cout << "cost from" << start << " to " << i << " is: " << rt[i].cost << "  from node is " << rt[i].from << endl;
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

void heap_adjust_down(vector<rt_node> & rt, vector<h_node> & heap) {
	size_t last = heap.size() - 1;
	// swap the first node with last leaf and delete it.
	heap[0].id = heap[last].id;
	heap[0].cost = heap[last].cost;
	heap.pop_back();
	//re-heap from root and update value in routing table, if needed
	//every time exchange with child with less cost, if needed
	unsigned int cur = 0, cur_child;
	if (heap.size() == 2 || (heap.size() > 2 && heap[2 * cur + 1].cost < heap[2 * cur + 2].cost)) 
		 {
			 cur_child = 2 * cur + 1;
		 }
	else 
		{	
			cur_child = 2 * cur + 2; //if size == 1, or size > 2 and child 2 is smaller
		}
	while (cur_child < heap.size()) {
		if (heap[cur].cost > heap[cur_child].cost) {
			//exchange in heap and update in routing table
			int child_id = heap[cur_child].id;
			int child_cost = heap[cur_child].cost;
			heap[cur_child].id = heap[cur].id;
			heap[cur_child].cost = heap[cur].cost;
			rt[cur].h_pos = cur_child;
			heap[cur].id = child_id;
			heap[cur].cost = child_cost;
			rt[cur_child].h_pos = cur;
			//re-assignment
			cur = cur_child;
			if (heap.size() == 2 * cur + 1 || (heap.size() > 2 * cur + 2 && heap[2 * cur + 1].cost < heap[2 * cur + 2].cost)) 
				{
					cur_child = 2 * cur + 1;
				}
			else {
					cur_child = 2 * cur + 2;				
				 }
		}
		else break;
	}
}

void heap_adjust_up(vector<rt_node> & rt, vector<h_node> & heap, int &n) {
	int cur_parent = -1, cur = -1;
	for (size_t i = 0; i < heap.size(); i++) {
		if (heap[i].id == n) {
			cur = i;
			break;
		}
	}
	if (cur == 0) return;
	cur_parent = cur / 2;
	while (cur > 0) {
		if (heap[cur].cost < heap[cur_parent].cost) {
			//exchange in heap and update in routing table
			int parent_id = heap[cur_parent].id;//
			int parent_cost = heap[cur_parent].cost;//
			heap[cur_parent].id = heap[cur].id;//
			heap[cur_parent].cost = heap[cur].cost;//
			rt[cur].h_pos = cur_parent;//
			heap[cur].id = parent_id;//
			heap[cur].cost = parent_cost;//
			rt[cur_parent].h_pos = cur;//
			//re-assignment
			cur = cur_parent;
			cur_parent = cur / 2;
		}
		else break;
	}
}

void heap_op(vector<vector<e_node>> & graph, vector<rt_node> & rt, vector<h_node> &heap) {
	for (size_t i = 0; i < rt.size(); i ++) {
		int checked_node = heap[0].id; //check the root of heap
		rt[checked_node].checked = 1;
		heap_adjust_down(rt, heap);
		for (auto cur_neighbor : graph[checked_node]) {
			int neighbor_id = cur_neighbor.nb;
			if (rt[neighbor_id].cost > rt[checked_node].cost + cur_neighbor.weight) {
					rt[neighbor_id].cost = rt[checked_node].cost + cur_neighbor.weight;
					rt[neighbor_id].from = checked_node;
					heap_adjust_up(rt, heap, (int &)neighbor_id);
			}
		}
	}
}