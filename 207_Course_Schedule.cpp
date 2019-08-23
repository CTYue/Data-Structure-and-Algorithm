/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-21 21:11:28
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-22 22:02:30
 * @Description: To be added.
 * @AC:
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
    //Time Complexity: 
    //Space Complexity: 
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) 
    {        
        vector<vector<int> > graph(numCourses);//Adjacent list
        vector<int> degrees(numCourses,0);//指向某点的in-degree个数
        
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//临近index的vector of nodes.对于该有向图，graph[i]                                                                         //[j]表示i指向j(先序课指向课程)
        }
        
        for(auto v:graph)
        {
            for(int node:v) degrees[node]++;//degrees[node]==1, 指向node的in-degree的数量++
        }        
        
        //Topological Sorting
        for(int i=0;i<numCourses;i++)
        {
            int j=0;
            for(;j<numCourses;j++)
            {
                if(degrees[j]==0)   break;//找到至少一个in-degree为0的node，则退出
            }
            
            if(j==numCourses)   return false;
            
            else
            {
                std::cout << "degrees[j] = " << degrees[j] << std::endl;
                degrees[j]--;//这一行什么意思? 
                for(int node: graph[j])     degrees[node]--;//更新
            }
        }
        
        return true;//存在至少一个in-degree为0的node
    }
};