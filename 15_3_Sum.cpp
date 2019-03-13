class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
            if(nums.size()==0)
                return res;
        
        //使用什么方法做？
        //1.Brute force
        
        
        //2.Hashing
        bool found=false;
        
        unordered_set<int> set;
        int extra=0;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> s;
            for(int j=i+1;j<nums.size();j++)
            {
                extra=-(nums[i]+nums[j]);
                
                if(set.find(extra)!=set.end())
                {
                    found=true;
                }
                else
                {          
                    set.insert(nums[j]);
                    set.insert(nums[j]);
                }
            }
            
            set.insert(nums[i]);
            if(found)
            {
                s.push_back(nums[i]);
                s.push_back(extra);
                
                res.push_back(s);
            }
        }
        
        return res;
        
        //3.Sorting
    }
};