/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-24 08:18:25
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-08 16:24:47
 * @Description: To be added.
 * @AC: Solution_1: NO
 *      Solution_2: Yes
 * @Realated: 253@Leetcode
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution_1 {
public:
    //My Brute force solution(Wrong answer)
    // 34 of 53 test cases passed.
    //Input:
    // [[7,5,6],[6,7,8],[10,1,6]]
    // 16
    // Output:
    // true
    // Expected:
    // false
    bool carPooling(vector<vector<int> >& trips, int capacity) 
    {
        int len=trips.size();
        int seat=0;//Least seats needed. Capacity>=seat.
        if(len<1 || capacity<2)   return false;
        if(len==1 && trips[0][0]<=capacity)  return true;
        if(len==2 && trips[0][0]<=capacity && trips[1][0]<+capacity)
        {
            if(trips[1][1]<trips[0][2])
            {
                seat=trips[0][0]+trips[1][0];
                if(seat>capacity) return false;
                else 
                    return true;
            }
        }

        std::cout << "len = " << len << std::endl;
        for(int i=0;i<len-2;i++)
        {
            //if(overlap的旅程，乘客数相加<=capacity && 所有的旅程，乘客数都<=capacity) return true;
            //输入的trips是有序排列的，即
            //可以将trips分类，how？
            //如何找出overlap的trip？
            //若存在子(全overlap)trip，如何操作？按sample，不存在全overlap的情况！对，因为不开回头车!
            //if(start[i]<end[i-1])
            // std::cout << "Hello = " << std::endl;
            std::cout << "i = " << i << std::endl;
            std::cout << "number of people: " << trips[i][0] << std::endl;
            // std::cout << "start[i+1] = " << trips[i+1][1] << std::endl;
            // std::cout << "end[i] = " << trips[i][2] << std::endl;
            //若后一段trip的start小于前一段trip的end,则视为同一类trip
            //
            if(trips[i+1][1]<trips[i][2])//if overlap trips
            {
                seat+=trips[i+1][0];
                std::cout << " overlap seat = " << seat << std::endl;
                if(seat>capacity)   return false;
            }
            //Separate trips
            else
            {
                std::cout << "Separate seat = " << seat << std::endl;
                if(seat>capacity) 
                {
                    return false;
                }
                else
                    seat=0;
            }
        }
        //怎样处理最后一段trip？
        //不知道！
        
        return true;
    }
};

class Solution_2 {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        //注意：题目说明了，车辆仅往东开！！！
        //只要单独trip的人数>capacity 或 overlap的人数>capacity
        //则返回false，其余情况，均返回true
        //注意：trip结束点<=1000，所以res长度为1001
        //Onepass Solution
        //Time Complexity: O(n)
        //Space Complexity: O(1)
        vector<int> res(1001,0);//保存每段trip的乘客数
        
        for(auto v:trips)
        {
            if(v[0]>capacity)  return false;
            
            //要不要考虑从起点到终点的中间部分???
            //不用考虑！
            //因为车辆仅向东行驶，所以trips[i][1]>trips[j][1](i>j)
            //上车：res[v[1]]+=v[0]
            res[v[1]]+=v[0];
            //下车: res[v[2]]-=v[0]
            res[v[2]]-=v[0];
        }
        
        
        for(int i=0;i<res.size();i++)
        {
            if(res[i]!=0)
                std::cout << "res[" << i << "] = " << res[i] << std::endl;
        }
        
        //对于overlap的trip,
        //由于车辆向东行驶，一旦trip[i][0]+trip[j][0]>capacity(j>i)
        //则返回false
        int sum=0;
        for(auto v:res)
        {
            // capacity-=v;
            // if(capacity<0)  return false;
            sum+=v;
            if(sum>capacity)    return false;
        }
        
        return true;
    }
};


int main(int argc, char* argv[])
{
    if(argc<1) return 0;



    return 1;
}