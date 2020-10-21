/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-26 02:13:34
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-28 13:39:28
 * @Description: To be added.
 * @AC: Solution_1 Yes
 */

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;
//Leetcode
class Solution_1 {
public:
    using Interval=vector<int>;
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        vector<Interval> res;
        if(intervals.empty())   return res;
        //sort(vec.begin(), vec.end(), myfunction);//还没理解！这里的function如何被调用？
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
        {            
            if(*(intervals[i].begin()) <= *(res.back().end()-1))
            {   
                Interval temp(2,0);
                temp[0]=*res.back().begin();
                temp[1]=max(*(res.back().end()-1), *(intervals[i].end()-1));
                //注意，vector中的末元素，其地址为vec.end()-1
                // std::cout << "intervals[i].end()-1 = " << *(intervals[i].end()-1) << std::endl;
                // std::cout << "temp = " << "[" << temp[0] << ", " << temp[1] << "]" << std::endl;
                res.pop_back();
                res.push_back(temp);
            }
            else 
                res.push_back(intervals[i]);
        }        
        
        return res;
    }
};

int main(int argc, char* argv[])
{


    return 1;
}