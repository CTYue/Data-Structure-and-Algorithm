/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-05 22:32:30
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-07 21:22:28
 * @Description: To be added.
 * @AC: faster than 100%, less than 8.5%
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
class Solution {
public:
    //注意：将int型强制转换为long型!
    //Corner case: 
    //#1: [] 1 1
    //#2: [-2147483648,-2147483648,0,2147483647,2147483647] 
    //    -2147483648   2147483647
    
    void addRange(vector<string> &res, long int start, long int end)
    {
        if(start>end)  return;

        //Add point
        if(start==end)  
        {
           res.push_back(to_string(start));
           return;
        }
        
        //Add ranges
        ostringstream os;
        os << start << "->" << end;
        string temp=os.str();
        
        res.push_back(os.str());
    }


    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) 
    {
        vector<string> res;
        if(nums.empty())
        {
            addRange(res, lower, upper);return res;
        }
        
        size_t len=nums.size();
        if(nums[0]>lower)   addRange(res,(long)lower, (long)nums[0]-1);
                
        for(int i=1;i<nums.size();i++)  addRange(res, (long)nums[i-1]+1, (long)nums[i]-1);
        
        if(nums[len-1]<upper)   addRange(res, (long)nums[len-1]+1, (long)upper);
        
        return res;
    }
};

int main(int argc, char* argv[])
{

    return 1;
}