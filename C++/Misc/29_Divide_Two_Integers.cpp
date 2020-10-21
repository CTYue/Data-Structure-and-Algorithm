/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-31 21:51:38
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-04-03 01:17:20
 * @Description: To be added.
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        //DO NOT USE MULTIPLICATION!
        if(divisor==0)  return INT_MIN;
        long ans=0;
        //If dividend and divisor have different signs, then set sign=-1
        //otherwise sign=1
        
        int sign=(dividend>0)^(divisor>0)?-1:1;
        
        if(dividend==INT_MIN && divisor==-1) 
            return INT_MAX;
        
        long dvdd=labs(dividend), dvs=labs(divisor);     
        
        while(dvdd>=dvs)
        {
            long temp=dvs, count=1;
            while(temp<<1 <= dvdd)
            {
                temp<<=1;
                count<<=1;
                cout<<"temp = "<<temp<<endl;
                cout<<"count = "<<count<<endl;
            }
            
            dvdd-=temp;
            ans+=count;
        }
        
        return sign*ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);
        
        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}