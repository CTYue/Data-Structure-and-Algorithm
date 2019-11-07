/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-05 23:12:08
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-06 22:06:35
 * @Description:
 * There is a new language which we don't know how the 
 * letters were ordered, you are provided with a dictionary
 * like below.
 * 
 * Example 1:
 * Input:
 * [
 * "wrt",
 * "wrf",
 * "er",
 * "ett",
 * "rftt"
 * ]
 * Output: "wertf"
 *
 * Example 2:
 * Input:
 * [
 *  "z",
 *  "x"
 * ]
 * Output: "zx"
 * 
 * Example 3:
 * Input:
 * [
 *  "z",
 *  "x",
 *  "z"
 * ] 
 * Output: "" 
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution_dfs {
public:
    //Topological Sort+DFS
    //Time Complexity: 
    //Space Complexity: 
    string alienOrder(vector<string>& words) 
    {
        if(words.size()==1)  return words.front();
        
        unordered_map<char, unordered_set<char>> graph;
        
        for(int i=1;i<words.size();i++)
        {
            string t1=words[i-1];//
            string t2=words[i];//
            
            bool found=false;
            //为什么要比较t1和t2的长度？？？
            //因为word之间也有connection
            // cout<<"t1: "<<t1<<endl;
            // cout<<"t2: "<<t2<<endl;
            
            for(int j=0;j<std::max(t1.length(), t2.length());j++)
            {
                if(j<t1.length() && graph.count(t1[j])==0)
                {
                    graph.insert(make_pair(t1[j],unordered_set<char>()));
                }
                
                if(j<t2.length() && graph.count(t2[j])==0)
                {
                    graph.insert(make_pair(t2[j],unordered_set<char>()));
                }
                
                //前者中的letter指向后者中的letter
                if(j<t1.length() && j<t2.length() && t1[j]!=t2[j] && !found)
                {
                    cout<<"t1["<<j<<"]: "<<t1[j]<<endl;
                    cout<<"t2["<<j<<"]: "<<t2[j]<<endl;
                    graph[t1[j]].insert(t2[j]);//
                    found=true;
                }
            }
            
        }
        
        //there's a connection between each single word
        cout<<"====Print graph===="<<endl;
        for(auto p: graph)
        {
            cout<<p.first<<": ";
            for(auto v: p.second)   cout<<v<<" ";
            cout<<endl;
        }
    
        return topsort(graph);
    }
    
    
    string topsort(unordered_map<char, unordered_set<char>>& graph)
    {
        unordered_set<char> visited;
        unordered_set<char> cycle;
        string order;
        
        for(auto it=graph.begin();it!=graph.end();++it)
        {
            cout<<"it->first = "<<it->first<<endl;
            if(dfs(graph, visited, cycle, order, it->first)==false)   return "";
        }
                    
        //通常情况下，dfs做topological sort用stack
        std::reverse(order.begin(), order.end());
        return order;
    }
    
    //Return if the node is visited or not
    //push back visited letter to order
    bool dfs(unordered_map<char, unordered_set<char>>& graph, unordered_set<char>& visited, unordered_set<char>& cycle, string& order, char n)
    {
        //cycle is for checking acyclic cycle
        if(cycle.count(n))    return false;
        if(visited.count(n))    return true;
        
        visited.insert(n);
        cycle.insert(n);
        
        for(auto it=graph[n].begin(); it!=graph[n].end();it++)
            if(dfs(graph, visited, cycle, order, *it)==false)     return false;
        
        
        //print cycle
        cout<<"====Print cycle===="<<endl;
        for(auto item: cycle)
            cout<<item<<" ";
        cout<<endl;
        
        //cycle is for checking acyclic cycle
        cycle.erase(n);//保证单向，无环
        cout<<"order = "<<order<<endl;
        order+=n;//(size_t n, char c)
        
        return true;
    }    
};


int main(int argc, char* argv[])
{
    vector<string> dict={"wrt", "wrf", "er", "ett", "rftt"};
    
    Solution_dfs dfs;
    string res=dfs.alienOrder(dict);
    cout<<"===================="<<endl;
    cout<<"ORDER = "<<res<<endl;
    return 0;
}
