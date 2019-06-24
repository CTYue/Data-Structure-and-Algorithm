/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-24 08:18:25
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-24 08:50:14
 * @Description: To be added.
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
            //若存在子(全overlap)trip，如何操作？按sample，不存在全overlap的情况！
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

class Solution_2
{
public:
    //
    //Time Complexity:
    //Space Complexity:
    bool carPooling(vector<vector<int> >& trips, int capacity) 
    {
        //TODO
    }

};

int main(int argc, char* argv[])
{
    if(argc<1) return 0;



    return 1;
}