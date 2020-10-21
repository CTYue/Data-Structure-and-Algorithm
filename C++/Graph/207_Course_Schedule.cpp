/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-21 21:11:28
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-28 21:07:13
 * @Description:
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
 * which is expressed as a pair: [0,1](in the graph, 0 points to 1), return true if it's possible
 * to finish all courses, otherwise, return false.
 * Example 1:
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    //BFS
    //Time Complexity: O(Vertex+Edge)
    //Space Complexity: 
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) 
    {        
        vector<vector<int> > graph(numCourses);//Adjacent list
        vector<int> degrees(numCourses,0);//指向某点的in-degree个数
        
        for(int i=0;i<prerequisites.size();i++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//临近index的vector of nodes.对于该有向图，graph[i]                                                                         //[j]表示i指向j(先序课指向课程)
        
        for(auto v:graph)
            for(int node:v) degrees[node]++;//degrees[node]==1, 指向node的in-degree的数量++

        //Topological Sorting
        for(int i=0;i<numCourses;i++)
        {
            int j=0;
            for(;j<numCourses;j++)
            {
                //if found a node with no in-degree
                if(degrees[j]==0)   break;
            }
            
            if(j==numCourses)   return false;
            
            else
            {
                std::cout << "degrees[j] = " << degrees[j] << std::endl;
                degrees[j]=-1;//mark as visited
                for(int node: graph[j])     degrees[node]--;
            }
        }
        
        return true;//存在至少一个in-degree为0的node
    }
};