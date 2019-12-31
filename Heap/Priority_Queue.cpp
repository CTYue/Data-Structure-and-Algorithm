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
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    //Max heap by default
    // priority_queue<std::pair<int,int> > p_queue;

    //Lets make a min heap
    //less: Max heap
    //greater: Min heap
    //注意，C++的优先队列，队首指向队列末尾，所以调用less和greater时，效果与在数组中使用时效果相反.
    //之所以这样设计，是为了防止访问数组的时候越界（Array out of bounds）
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


    // while(!p_queue.empty())
    // {
    //     auto p=p_queue.top();
    //     std::cout<<p.first<<", "<<p.second<<endl;
    //     p_queue.pop();
    // }

    //Try sorting
    vector<int> srt={1,2,3,4,5,6,7,8,9,10,11};
    //less: 小的在前
    //greater: 大的在前
    // std::sort(srt.begin(), srt.end(), less<int>());
    std::sort(srt.begin(), srt.end(), greater<int>());
    
    for(auto item: srt)
    {
        cout<<item<<" ";
    }

    cout<<endl;

}
