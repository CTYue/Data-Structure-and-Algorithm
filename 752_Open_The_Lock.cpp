/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-02-21 00:43:31
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-08 17:55:49
 * @Description: To be added.
 * @AC: BFS Yes
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    //BFS
    //Time Complexity: O(???)
    //Space Complexity: O(N)
    //可以视为matrix遍历问题
    int openLock(vector<string>& deadends, string target) 
    {
        queue<string> queue;
        queue.push("0000");
        int step=0;
        
        unordered_set<string> visited;

        //将deadend里的每一项均当做已visited的项
        //为什么？
        for(auto d: deadends)   visited.insert(d);
        
        while(!queue.empty())
        {
            //BFS在需要计算步骤的时候，
            //需要获取queue的size
            //并遍历每个queue
            int size=queue.size();
            for(int i=0;i<size;i++)
            {
                string node=queue.front();queue.pop();
                
                //如果该node已访问过
                if(visited.count(node)!=0) continue;//这里为什么是continue？
                
                if(node==target)    return step;
                
                //对lock的每一位进行操作
                for(int j=0;j<4;j++)
                {
                    //每次减1或加1
                    for(int k=-1;k<=1;k+=2)
                    {
                        string next=node;
                        //注意这里的处理技巧！
                        //+1时取1，-1时取9
                        next[j]=(next[j]-'0'+k+10)%10+'0';
                        //将生成的lock压入queue
                        queue.push(next);
                    }
                }
                
                visited.insert(node);
            }
            step++;
        }
        //if impossible
        return -1;
    }
};