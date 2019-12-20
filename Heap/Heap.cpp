/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-19 20:36:55
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2019-12-19 20:37:05
 * @Description: To be added.
 */

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main(int argc, char** argv)
{
    //Max heap by default
    // priority_queue<std::pair<int,int> > p_queue;

    //Lets make a min heap
    //less: Max heap
    //greater: Min heap
    //
    priority_queue<std::pair<int,int>, vector<std::pair<int, int> >, greater<pair<int,int> > > p_queue;


    //对于pair，priority_queue会默认按照以下规则排序
    //1: 首先按照first排序，
    //2: 在first相同的情况下，根据second排序
    p_queue.push(pair<int, int>(1,2));
    p_queue.push(pair<int, int>(2,9));
    p_queue.push(pair<int, int>(9,666));
    p_queue.push(pair<int, int>(8,1));
    p_queue.push(pair<int, int>(10,21));
    p_queue.push(pair<int, int>(2,2));


    while(!p_queue.empty())
    {
        auto p=p_queue.top();
        std::cout<<p.first<<", "<<p.second<<endl;
        p_queue.pop();
    }


}
