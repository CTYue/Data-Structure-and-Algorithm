/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-21 21:11:28
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-22 10:09:38
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
                if(degrees[j]==0)   
                {
                    std::cout << "j = " << j << std::endl;
                    std::cout << "break" << std::endl;
                    break;//jth node has no in-degree edge                
                }
            }
            
            if(j==numCourses)   return false;//如果所有node都有in-degree edge，则返回false；
                                             //必须找到至少一个，不需要先序课程的课程(无环)
            
            //这里还没理解!
            else
            {
                degrees[j]--;
                for(int v: graph[j])    {std::cout << "v = " << v << std::endl;degrees[v]--;}
            }
        }
        
        return true;//当至少有一个0in-degree的node时，返回true
    }


//     //Sample Answer from CSDN
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
//     {
//         vector<int> degree(numCourses, 0);//adjacency matrice.标记了课程和先序课程的对应关系。
        
//         unordered_map<int, vector<int>> graph;//
//         queue<int> nodes;//Save those who don't need  prerequisite courses.
        
//         for(int i=0;i<prerequisites.size();i++)
//         {
//             //degree saves those which have prerequisite courses.
//             degree[prerequisites[i][0]]++;
//             graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//graph saves key-value pair of pre-course and course
//         }
        
//         for(int i=0;i<numCourses;i++)
//         {
//             if(degree[i]==0)//If course i doesn't need pre course
//             {
//                 nodes.push(i);//nodes存储了不需要前序课程的课程
//             }
//         }
        
//         while(!nodes.empty())
//         {
//             int node=nodes.front();
//             nodes.pop();
//             degree[node]=-1;//将不需要先序课程的课标记为-1
            
//             for(int i=0;i<graph[node].size();i++)
//             {
//                 degree[graph[node][i]]--;//Update graph, 将不需要先序课程的课程--.
//                 if(degree[graph[node][i]]==0)//如果需要的前序课程数量为0(--后为0),即update后的degree
//                     nodes.push(graph[node][i]);
//             }
//         }
        
//         for(int i=0;i<numCourses;i++)
//         {
//             if(degree[i]!=-1)   return false;//只要有一个课程需要先序课程，就返回false
//         }
        
//         return true;
//     }
    
};
