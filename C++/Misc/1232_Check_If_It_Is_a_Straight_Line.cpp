/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-20 17:26:56
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-20 17:27:31
 * @Description: To be added.
 */
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int x0=coordinates[0][0], y0=coordinates[0][1];
        int x1=coordinates[1][0], y1=coordinates[1][1];
        //If the third point has the same slope with the first two points respectively,
        //then they are on the same straight line.
        for(auto pos: coordinates)
        {
            //注意：不要使用除法
            if((pos[0]-x1)*(y1-y0)!=(x1-x0)*(pos[1]-y1)) return false;
        }
        return true;
    }
};