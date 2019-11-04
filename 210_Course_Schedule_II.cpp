/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-23 08:50:00
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-04 14:44:00
 * @Description: To be added.
 */


#include<iostream>
#include<vector>

using namespace std;
class Solution_1 {
public:
    //BFS Solution (Using node in-degree )
    //Time Complexity: O(N) (Scan all nodes)
    //Space Complexity: O(N) ???
    //Graph: prerequisite course points to course-to-take
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        vector<int> degrees(numCourses,0);
        
        for(auto v: prerequisites)  graph[v[1]].push_back(v[0]);
        
        for(int i=0;i<numCourses;i++)   
            for(int j=0;j<graph[i].size();j++)  
                degrees[graph[i][j]]++;
        
        //Topological sort
        //Find course with 0 in-degree
        for(int i=0;i<numCourses;i++)
        {
            int j=0;
            for(;j<numCourses;j++)
            {
                if(degrees[j]==0)
                {
                    res.push_back(j);
                    break;
                }
            }
                
                if(j==numCourses)   return vector<int>{};
                else
                {
                    degrees[j]--;//j本身的入度--
                    for(auto v: graph[j])    degrees[v]--;
                }
        }
        
        return res;        
    }
};