/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-08 16:39:58
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-08 22:09:22
 * @Description: To be added.
 * @AC: Solution_1:YES(Low Performance)
 *      Solution_2: Yes(faster than 20.15%, less than 44.57%)
 *      Solution_3: 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution_1 {
public:
    //Brute force Solution
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        int res=0;
        //按v[i][0]从小到大排序
        std::sort(intervals.begin(),intervals.end());
        
        int len=intervals.size();
        int max=0;
        for(auto v:intervals)
        {
            //找出最大长度！
            if(v[1]>max)
                max=v[1];
        }
        int overlap_len=max;
        std::cout << "overlap_len = " << overlap_len << std::endl;
        vector<int> overlap(overlap_len+1,0);
        
        std::cout << "[" ;
        for(auto v:intervals)
        {
            std::cout << "[" << v[0] << ", " << v[1] << "], ";
        }
        std::cout << "]" << std::endl;
        
        for(auto v:intervals)
        {
            for(int i=v[0];i<v[1];i++)
                overlap[i]+=1;
        }
        
        res=*(std::max_element(overlap.begin(),overlap.end()));
        
        return res;
    }
};

class Solution_2 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        //Onepass Solution
        //Explanation: 
        //rooms++ when multiple start points share a same fixed end point.
        //Time Complexity: O(n)
        //Space Complexity: O(n)
        int len=intervals.size();
        vector<int> start(len,0);
        vector<int> end(len,0);
        
        for(int i=0;i<len;i++)
        {
            start[i]=intervals[i][0];
            end[i]=intervals[i][1];
        }
        //
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int rooms=0;
        int end_pos=0;
        
        // for(int i=0;i<len;i++)
        // {
        //     std::cout << "start[" << i << "] = " << start[i] << std::endl;
        //     std::cout << "end[" << i << "] = " <<  end[i] << std::endl;
        // }
        
        for(int i=0;i<len;i++)
        {
            std::cout << "start[i] = " << start[i] << std::endl;
            std::cout << "end[end_pos] = " << end[end_pos] << std::endl;
            //此处end point固定
            //若start points共用一个end point，那么rooms++
            if(start[i]<end[end_pos])
            {
                std::cout << "rooms++" << std::endl;
                rooms++;
            }
            //若起始时间大于等于结束时间，则调到下一个结束时间
            else
            {
                end_pos++;
                std::cout << "end_pos++" << std::endl;
            }
        }
        return rooms;
    }
};

int main(int argc, char* argv[])
{
    //TODO



}