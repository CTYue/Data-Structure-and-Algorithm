/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-11 18:42:18
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-11 18:43:16
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> v;
bool comp(const v a, const v b)
{
    //Ascending order
    if(a[0]<b[0])   return true;
    if(a[0]==b[0])  
    {
        return a[1]<b[1];
    }
    else    return false;
}

class Solution {
public:
    //Check if there's overlap between each time slot
    //Are slots sorted? No, we should sort them according to the starting time.
    //Time Complexity: O(N*logN+N)=O(logN)
    //Space Complexity: O(1)
    bool canAttendMeetings(vector<vector<int>>& intervals) 
    {
        if(intervals.size()<=1) return true;
        
        //进行排序的不是vv_it，而是单个的vector
        std::sort(intervals.begin(), intervals.end(), comp);
        
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i][1]>intervals[i+1][0])   return false;
        }
        
        return true;
    }
};

int main(int argc, char** argv)
{
    //TODO
    return 1;
}