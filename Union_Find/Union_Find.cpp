/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-15 09:07:00
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-21 16:05:23
 * @Description: 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
    int src, dest;
};

//Union-Find方法到底在干嘛？
//Union(): 
//Find(): 
//Cycle detection
class Graph
{
public:
    int V, E;
    Edge* edge;
};

    Graph* createGraph(int V, int E)
    {
        Graph* graph=new Graph();
        graph->V=V;
        graph->E=E;

        graph->edge=new Edge();
        return graph;
    }

    //return the identifier of the connected component
    int find(int parent[], int i)
    {
        if(parent[i]==-1)   return i;

        return find(parent, parent[i]);
    }

    void Union(int parent[], int x, int y)
    {
        int xset=find(parent, x);
        int yset=find(parent, y);
        
        if(xset!=yset)  parent[xset]=yset;//
    }
    
    //Return whether a given graph has a cycle
    //or not.
    bool isCycle(Graph* graph)
    {
        int* parent = new int[graph->V* sizeof(int)];
        
        //Initialize all subsets as singel element sets
        memset(parent, -1, sizeof(int)* graph->V);

        for(int i=0;i<graph->E;++i)
        {
            int x=find(parent, graph->edge[i].src);
            int y=find(parent, graph->edge[i].dest);

            if(x==y)    return 1;
            
            Union(parent, x, y);
        }
        return 0;
    }

    int main(int argc, char* argv[])
    {
        int V=3, E=3;
        Graph* graph=createGraph(V, E);

        //Add edge 0-1
        graph->edge[0].src=0;
        graph->edge[0].dest=1;

        //Add edge 1-2
        graph->edge[1].src=1;
        graph->edge[1].dest=2;

        //Add edge 0-2
        graph->edge[2].src=0;
        graph->edge[2].dest=2;

        if(isCycle(graph))  cout<<"Yes, there's a cycle inside the graph."<<endl;
        else cout<<"No, no cycle inside the graph."<<endl;
        

        return 0;
    }