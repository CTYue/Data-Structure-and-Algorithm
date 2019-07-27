#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    //DP Solution
    //Time Complexity: O(???)
    //Space Complexity: O(???)
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;
        if(intervals.size()==0 || intervals.size()==1 ) return intervals;
        int len=intervals.size();
        
        //
        std::sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>::iterator last=intervals.begin();
        
        for(auto item:intervals)
        {
            if(last==intervals.end() || last[1]<item[0])//这里有问题
            {
                res.push_back(item);
                //Update last:
                last=item;
            }
                
            //否则就合并  
            else
            {
                last[1]=std::max(last[1],item[1]);
            }
            
            // std::cout << "item.size() == " << item.size() << std::endl; 
            // last=item;
            // std::cout << "item[0] =" << item[0] << std::endl;
            // std::cout << "item[1] =" << item[1] << std::endl;        
        
            std::cout << item.start() <<std::endl;
        }
        
        
        // std::cout << "last[0] = " << last[0][0] << std::endl;
        // std::cout << "last[1] = " << last[1][0] << std::endl;
        // std::cout << "last[2] = " << last[2][0] << std::endl;
        // std::cout << "last[3] = " << last[3][0] << std::endl;
        
        return res;
    }
};


int main(int argc, char* argv[])
{


    return 1;
}