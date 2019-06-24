/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-24 08:50:52
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-24 15:20:15
 * @Description: To be added.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    //TODO
    vector<double> sampleStats(vector<int>& count) 
    {
        vector<double> res={};
        if(count.size()<1) return res;
        int len=count.size();
        auto max=std::max_element(count.begin(),count.end());
        std::cout << "max = " << max << std::endl;
        res.push_back((double)(*max));
        auto min=std::min_element(count.begin(),count.end());
        std::cout << "min = " << min << std::endl;
        res.push_back((double)(*min));
        double mean=std::accumulate(count.begin(),count.end(),0)/len;
        std::cout << "mean = " << mean << std::endl;
        res.push_back(mean);
        // double mode= 
        
        return res;
    }
};

int main(int argc, char* argv[])
{
    if(argc<1) return 0;
    //TODO


    return 1;
}