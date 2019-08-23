/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-23 08:50:00
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-23 08:51:41
 * @Description: To be added.
 * @AC: Yes
 */

#include<iostream>
#include<vector>

using namespace std;
class Solution_1 {
public:
    //BFS Solution
    //Time Complexity: O(n)
    //Space Complexity: O(n^2)? 
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
         //Topological Sorting
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> degrees(numCourses,0);
        vector<int> res={};              
        //先修课指向course
        //[0,1],first is the course, second is the prerequisite course
        for(int i=0;i<prerequisites.size();i++)
        {
            //Second points to first
            // std::cout << "prerequisites[i].second = " << prerequisites[i].second << std::endl;
            // std::cout << "prerequisites[i].first = " << prerequisites[i].first << std::endl;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(auto v:graph)
        {
            for(auto node:v)    degrees[node]++;
        }
        
        //Topological Sorting Starts here
        for(int i=0;i<numCourses;i++)
        {
            int j=0;
            for(;j<numCourses;j++)
            {
                if(degrees[j]==0)   
                {
                    // std::cout << "degrees[j] == 0" << std::endl;
                    res.push_back(j);
                    break;
                }
            }
            
            if(j==numCourses)   return vector<int>();
            
            else
            {
                degrees[j]--;//j本身的in-degree减1
                for(auto node:graph[j]) degrees[node]--;//j所指向的node的in-degree--
            }
        }
      
        return res;
    }
};