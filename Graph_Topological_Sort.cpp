/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-28 21:10:45
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-08 23:58:06
 * @Description: 
 * Here we have a graph as below (Must be a DAG):
 * 
 *  Adjacent List:
 *  
 * 
 * One possible topological sort Result:
 *
 * (always starts from vertex with 0 in-degree)
*/

#include <iostream>
#include <vector>
#include <stack>

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
    
    void sort_dfs(int v, vector<bool>& visited, stack<int>& Stack);
};

void Graph::sort_dfs(int v, vector<bool>& visited, stack<int>& Stack)
{
    cout<<"v = "<<v<<endl;
    //Mark current node as visited
    visited[v]=true;

    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false)   sort_dfs(adj[v][i],visited, Stack);
    }
    
    //Put visited nodes to stack
    Stack.push(v);
}

//Sort functions
//DFS: stack
void topologicalSort_dfs(Graph G)
{
    stack<int> s;

    //Mark all vertices as unvisited.
    vector<bool> visited(G.num, false);

    for(int i=0;i<visited.size();i++)
        if(visited[i]==false)   G.sort_dfs(i, visited, s);
    
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    
    cout<<endl;
}

//kahn: queue
void topologicalSort_kahn(Graph G)
{
    //TODO
    ;
}


int main(int argc, char* argv[])
{
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,5);

    //Requirements for sorting result:
    //1. Each node appears && only appears once.
    //2. Nodes appears earlier point to nodes appears later.
    cout << "Sort result (DFS): "<<endl; 
    topologicalSort_dfs(g); 

    cout<< "Sort result (Kahn): "<<endl;
    topologicalSort_kahn(g);
    
    return 0; 
}