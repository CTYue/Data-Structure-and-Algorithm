/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-28 21:10:45
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-03 21:47:51
 * @Description: 
 * Here we have a graph as below (Must be a DAG):
 * 0->1->2->3->4->5
 * 
 *  Adjacent List:
 *  1->2
 *  2->3
 *  3->4
 *  4->5
 *  
 * One possible topological sort Result:
 * 0 1 2 3 4 5
 * (always starts from vertex with 0 in-degree)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

class Graph
{
public:
    //number of vertexs in the graph
    int num;
    
    //Adjacent list
    vector<vector<int> > adj;

    Graph(int num)
    {
        this->num=num;
        adj.resize(num);
    }
    
    //V->W
    void addEdge(int v, int w)
    {
        cout<<"Added "<<v<<"->"<<w<<endl;
        adj[v].push_back(w);
    }
    
    void sortHelper(int v, vector<bool>& visited, stack<int>& Stack);
};

void Graph::sortHelper(int v, vector<bool>& visited, stack<int>& Stack)
{
    cout<<"v = "<<v<<endl;
    //Mark current node as visited
    visited[v]=true;

    auto idx=adj[v].begin();

    while(idx!=adj[v].end())
    {
        //Visit i's child
        // cout<<"*idx = " <<*idx<<endl;
        if(visited[*idx]==false)  sortHelper(*idx, visited, Stack);    
        idx++;
    }
    
    //Put visited nodes to stack
    Stack.push(v);
}

void topologicalSort(Graph G)
{
    stack<int> s;

    //Mark all vertices as unvisited.
    vector<bool> visited(G.num, false);

    for(int i=0;i<visited.size();i++)
        if(visited[i]==false)   G.sortHelper(i, visited, s);

    // cout<<"s.size() = "<<s.size()<<endl;
    
    while(s.empty()==false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    cout<<endl;
}

int main(int argc, char* argv[])
{
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);

    //Requirements for sorting result:
    //1. Each node appears && only appears once.
    //2. Nodes appears earlier point to nodes appears later.
    cout << "Sort result: \n"; 
    topologicalSort(g); 
  
    return 0; 
}
