/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-10-18 03:24:08
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-23 21:06:51
 * @Description: To be added.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    //Time Complexity: O(logN)
    //Space Complexity: O(logN) (Worst case)
    vector<vector<int> > res;
    vector<vector<int> > getFactors(int n) 
    {
        vector<int> vec;
        if(n<2) return res;
        
        dfs(n,2,vec);
        return res;
    }
    void dfs(int n, int factor, vector<int> vec)
    {
        if(factor>sqrt(n))  return;
        
        dfs(n, factor+1,vec);
        
        if(n%factor==0)
        {          
            vec.push_back(factor);
            
            dfs(n/factor, factor, vec);
            
            //push back the last factor
            vec.push_back(n/factor);
            res.push_back(vec);
        }       
    }
};

int main(int argc, char* argv[])
{
    int n=0;
    Solution test;
    cout<<"Type a number: "<<endl;
    cin>>n;
    auto res=test.getFactors(n);
    cout<<"[";
    for(auto set: res)
    {
        cout<<"[";
        for(auto factor: set)
            cout<<factor<<", ";
        cout<<"] ";
    }
    cout<<"]"<<endl;
    return 1;
}