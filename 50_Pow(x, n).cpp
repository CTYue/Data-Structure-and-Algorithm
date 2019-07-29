/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-28 23:27:52
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-28 23:52:24
 * @Description: To be added.
 * @AC: Solution: Yes
 */

#include <iostream>

using namespace std;
class Solution {
public:
    //O(longN)
    //如何pass，在不修改myPow的情况下？
    //double myPow(double x, int n)
    double myPow(double x, long n) 
    {
        if(n<1)
        {
            x=1/x;
            n=-n;
        }
        double res=1, tmp=x;
        
        while(n)
        {
            if(n%2==1)  res*=tmp;
            tmp*=tmp;
            n/=2;
        }
        
        return res;
    }
};

int main(int argc, char* argv[])
{
    int num, n;
    std::cin >> num >> n;
    Solution s1;
    double res = s1.myPow(num, n);
    std::cout << res << std::endl;

    return 1;
}