/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-01-28 09:13:28
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-28 09:27:13
 * @Description: To be added.
 */

 import java.io.*
 import java.util.*

 class Graph
 {
    private int num_v;
    private LinkedList<Integer> adj[];

    Graph(int v)
    {
        this.num_v=v;
        adj=new LinkedList<Integet>[v];


    }
    void addEdge(int v, int u)
    {
        adj[v].add(u);
    }
 }

public static void main(String[] args) 
{
    System.out.print("Print something here...");     
}

