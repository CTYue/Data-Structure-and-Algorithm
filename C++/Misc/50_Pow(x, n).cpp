/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-28 23:27:52
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-30 19:04:00
 * @Description: To be added.
 * @AC: Solution: Yes
 */

#include <iostream>

using namespace std;
class Solution {
public:
    //O(longN)
    //如何pass，在不修改myPow的情况下？
    //注意理解代码，并背诵.
    //double myPow(double x, int n)
    double myPow(double x, long n) 
    {
        if(n<1)
        {
            x=1/x;
            n=-n;
        }
        
        double tmp=x,res=1;
        while(n!=0)
        {
            //如果n为2,最后一步
            if(n%2==1)    res*=tmp;
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