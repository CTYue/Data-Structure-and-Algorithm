/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-08 14:27:40
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-09 17:07:17
 * @Description: To be added.
 * @AC: YES
 * @Related: 1109@Leetcode
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    //输入：[起点，终点，数值]
    //输出：[第1个位置的值，第2个位置的值...]
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        vector<int> res(length+1,0);
                
        for(auto& v:updates)
        {
            if(v[0]<length && v[1]<length)
            {
                res[v[0]]+=v[2];
                res[v[1]+1]-=v[2];//
            }
        }
        
        for(int i=1;i<length;i++)
        {
            res[i]+=res[i-1];
        }
        
        //注意这种trim方式!
        return {res.begin(),res.end()-1};
    }
};

int main(int argc, char* argv[])
{
    //TODO

    
}