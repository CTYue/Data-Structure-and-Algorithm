/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-03-12 23:51:00
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-11-21 20:15:02
 * @Description: To be added.
 */

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) 
    {
        //Time complexity:O(n^2)
        //Space complexity:O(1)
         vector<vector<int> > res;
            if(nums.size()==0)  return res;
        
        //Time Complexity for std::sort funciton:
        //O(N*logN)
        std::sort(nums.begin(),nums.end(), less<int>());
        // for(auto i:nums) std::cout << i << " ";
        
        vector<int> res_item;
        for(int i=0;i<nums.size();i++)
        {
            int target=0-nums[i];
            int front=i+1;
            int back=nums.size()-1;
            
            while(front<back)
            {
                int sum=nums[front]+nums[back];
                
                if(sum<target)
                    front++;
                
                else if(sum>target)
                    back--;
                
                else
                {
                    vector<int> triplet(3,0);
                    triplet[0]=nums[i];
                    triplet[1]=nums[front];
                    triplet[2]=nums[back];

                    res.push_back(triplet);

                    while(front<back && nums[front]==triplet[1]) front++;
                    while(front<back && nums[back]==triplet[2]) back--;   
                }
            }
            while(i+1<nums.size() && nums[i+1]==nums[i])
                i++;
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    vector<int> input;
    int temp=0;
    do
    {
        cin>>temp;
        input.push_back(temp);
    }while(getchar()!='\n');

    Solution s1;
    auto res=s1.threeSum(input);
    for(auto v: res)
    {
        cout<<"[";
        for(int n: v)   cout<<n<<" ";
        cout<<"]"<<endl;
    }

    return 1;
}