/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-21 21:11:28
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-21 23:33:05
 * @Description: To be added.
 * @AC:
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        //有向无环图(DAG)
        //拓扑排序的本质:维持一个入度为0的顶点的集合
        //将每个课程pair看做邻接表, prerequisites[i][0](课程)指向prerequisites[i][1](先序课程)
        //
        //如果图中找不到任何in-degree为0的点，那么说明存在环
        vector<vector<int>> graph(numCourses);//邻接表，保存指向index的点
        for(auto p:prerequisites)
        {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> degrees(numCourses,0);//保存每个点indegree的个数
        for(auto v: graph)
        {
            for(auto node:v)
            {
                degrees[node]++;//in-degree++ 
            }
        }
        
        for(int i=0;i<numCourses;i++)
        {
            int j=0;
            for(;j<numCourses;j++)
            {
                if(degrees[j]==0)   break;//jth node has no in-degree edge                
            }
            
            if(j==numCourses)   return false;//如果所有node都有in-degree edge，则返回false；
                                             //必须找到至少一个，不需要先序课程的课程(无环)
            
            else
            {
                degrees[j]--;//mark jth node as visited(-1)
                for(int v: graph[j])    degrees[v]--;//不理解
            }
        }
        
        return true;//默认返回true，为什么？
    }