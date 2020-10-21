/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-01-27 21:00:20
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-27 22:23:31
 * @Description: To be added.
 */

#include <iostream>
#include <list>

using namespace std;

class Graph
{
private:
    int num_v;//number of vertices
    list<int> *adj;//这里adj用指针的话，相当于一个特殊的二维数组
    void dfs_helper(int v, bool visited[]);

public:
    Graph(int num_v);
    void addEdge(int v, int u);
    
    void dfs(int v);
};

    Graph::Graph(int num_v)
    {
        this->num_v=num_v;
        adj=new list<int>(num_v);//生成num_v个list<int>型指针
    }

    //Add an edge from v to u
    void Graph::addEdge(int v, int u)
    {
        adj[v].push_back(u);
    }

    //Traverse all adjacent vertices
    void Graph::dfs_helper(int v, bool visited[])
    {
        //Mark this vertice as visited
        visited[v]=true;//

        for(auto it=adj[v].begin();it!=adj[v].end();it++)
        {
            if(visited[*it]==false) dfs_helper(*it, visited);
        }
    }

    void Graph::dfs(int v)
    {
        bool visited[v];

        //Mark current vertice as unvisited
        for(int i=0;i<v;i++)    visited[i]=false;
        
        //Visit all unvisited vertices
        dfs_helper(v, visited);
    }


int main(int argc, char** argv)
{
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    g.dfs(0);
    return 1;
}