/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-11-13 23:06:25
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-15 09:06:46
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) 
    {
        val = _val;
        neighbors = _neighbors;
    }
};

//You should return the reference of the graph
class Solution {
private:
    //<current node, copy>
    unordered_map<Node*, Node*> map;
public:
    //DFS
    Node* cloneGraph(Node* node) 
    {
        if(node==nullptr)  return nullptr;
        
        //If current node has not been visited
        if(map.find(node)==map.end())
        {
            map[node]=new Node(node->val, {});
            for(Node* n: node->neighbors)
            {
                map[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        
        return map[node];
    }
};


//Test Stub
int main(int argc, char* atgv[])
{
    //TODO
    
    return 1;
}