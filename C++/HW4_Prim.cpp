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
    int id; // the pointer to the node
    int cost; // the key
    h_node() { id = -1; cost = 9999; }
    h_node(int i, int j) { id = i; cost = j; }
    bool operator<(h_node h) { return (cost < h.cost); }
};

void init(vector<rt_node> &rt, vector<h_node> & heap, int &start); //Insert the souce node to heap and update rt and heap accordingly
void heap_decrease_key(vector<rt_node> &rt, vector<h_node> & heap, int id, int n);
h_node heap_extrat_min(vector<rt_node> & rt, vector<h_node> & heap);
void prime(vector<vector<e_node> > & graph, vector<rt_node> & rt, vector<h_node> &heap);

int main() {

  ifstream in("text1.txt");
  int start;
  in >> start;	//source node for the Dijkstra's algorithm
  int n, e; 	//n: num of nodes ; e: num of edges
  in >> n >> e;
  vector<e_node> ve;
  vector<vector<e_node> > graph(n, ve);
  e_node e1;
  e_node e2;
  int n1, n2, w;
  for (int i = 0; i < e; i++) {
    in >> n1 >> n2 >> w;//
    e1.nb = n2;//neighbor
    e1.weight = w;//weight
    e2.nb = n1;
    e2.weight =w;
    graph[n1].push_back(e1);
    graph[n2].push_back(e2);
  }
  in.close();
  vector<rt_node> rt(n); //rt stands for routing table
  vector<h_node> heap(n);

  init(rt, heap, start);
  cout << "afeter init and heapify" << endl;
  prime(graph, rt, heap);
  for (int i=0;i<n;i++)
    cout << i << " Node's parent is " << rt[i].from << " and distance is " << rt[i].cost << endl;  
  //getchar();
  //getchar();
  return 0;
}

void min_heapify(vector<rt_node> &rt, vector<h_node> & heap, int i) {
  int size = heap.size();
  int l=0, r=0, smallest=0;
  l = i*2+1;
  r = i*2+2;
  int tmp;
  if (l<size && heap[l].cost < heap[i].cost)
    smallest = l;
  else smallest = i;
  if (r<size && heap[r].cost < heap[smallest].cost)
    smallest = r;
  if (smallest != i) {
    rt[heap[i].id].h_pos = smallest;
    rt[heap[smallest].id].h_pos = i;
    tmp  = heap[i].cost;
    heap[i].cost = heap[smallest].cost;
    heap[smallest].cost = tmp;
    tmp  = heap[i].id;
    heap[i].id = heap[smallest].id;
    heap[smallest].id = tmp;
    min_heapify(rt,heap,smallest);
  }
}

void heapify(vector<rt_node> &rt, vector<h_node> & heap) {
  int size = heap.size(); 
  if (size==0) return;
  for(int i=size/2;i>=0;i--) 
  {
    min_heapify(rt,heap,i);
  }
}


void init(vector<rt_node> &rt, vector<h_node> & heap, int &start) {
  rt[start].from = start;
  rt[start].cost = 0;
  for (size_t i = 0; i < heap.size(); i++) {
    heap[i].id = i;
    heap[i].cost = rt[i].cost;
    rt[i].h_pos = i;
  }
  heapify(rt,heap);
}



h_node heap_extract_min(vector<rt_node> & rt, vector<h_node> & heap) {
  h_node min = heap[0];
  heap[0].cost = heap[heap.size()-1].cost;
  heap[0].id = heap[heap.size()-1].id;
  rt[heap[0].id].h_pos=0;
  heap.pop_back();
  min_heapify(rt,heap,0);
  return min;
}

void heap_decrease_key(vector<rt_node> & rt, vector<h_node> & heap, int id, int pos)
{
  int i=pos;
  int parent = (i+1)/2-1;
  int tmp;
  heap[pos].cost = rt[id].cost;
  while( i>=0 && parent>=0 && heap[parent].cost>heap[i].cost )
  {
    rt[heap[i].id].h_pos = parent;
    rt[heap[parent].id].h_pos = i;
    tmp  = heap[i].cost;
    heap[i].cost = heap[parent].cost;
    heap[parent].cost = tmp;
    tmp  = heap[i].id;
    heap[i].id = heap[parent].id;
    heap[parent].id = tmp; 
    i=parent;
    parent = (i+1)/2-1;
  }
}

void prim(vector<vector<e_node> > & graph, vector<rt_node> & rt, vector<h_node> &heap)
{
  while (heap.size()>0)
  {
    int checkedNode = heap_extract_min(rt,heap).id;
    rt[checkedNode].checked = 1;  //mark checked node with 1
    for (auto currentNeighbor : graph[checkedNode])//
    {
      int neighborId = currentNeighbor.nb;
      if (rt[neighborId].checked == 1) continue;
      if (rt[neighborId].cost >  currentNeighbor.weight)
      {
        rt[neighborId].cost =  currentNeighbor.weight;
        rt[neighborId].from = checkedNode;
        heap_decrease_key(rt,heap,neighborId,rt[neighborId].h_pos);
      }
    }
  }
}
