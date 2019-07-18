/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-04 19:09:10
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-18 16:01:30
 * @Description: This file uses Fibonacci problem
 * as an example for Dynamic Programming explanation.
 * Top-down and Bottom-up approaches are introduced.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution_1
{
public:

    //Top-Down 
    //Top-Down is a recursion approach
    //it requires extra memory for array
    //and recursion(stack).
    int Fib_helper(int n)
    {
        if(n<=0) return n;
        int vals[n+1];

        for(int i=0;i<=n;i++)
            vals[i]=-1;

        return Fib(n,vals);    
    }
    
    int Fib(int n, int vals[])
    {
        if(vals[n]!=-1) return vals[n];
        
        else if(n<=2) vals[n]=1;

        //Save previous results
        else vals[n]=Fib(n-1,vals)+Fib(n-2,vals);

        return vals[n];
    }

    //Bottom-Top
    //Bottom-top is an iteration approach
    //Less memory usage compared to
    //the previous approach
    int Fib_Bottom_Top(int n)
    {
        if(n<=1) return n;
        
        int val_pre_2=0;
        int val_pre_1=1;
        int val=1;

        for(int i=2;i<=n;i++)
        {
            val=val_pre_1+val_pre_2;
            val_pre_2=val_pre_1;
            val_pre_1=val;
        }
        
        return val;
    }  
};


class Solution_2
{
public:
    //DP with Memorization
    int Fib(int n)
    {
        if(n<=1) return n;
        vector<int> vals(n+1, 0);
        vals[0]=0;
        vals[1]=1;

        for(int i=2;i<=n;i++)
            vals[i]=vals[i-1]+vals[i-2];

        return vals[n];
    }    
};

//Test Stub
int main(int argc, char* argv[])
{
    if(argc<1 || argc>1) return 1;
    Solution_1 fib;
    int input=0;
    
    std::cin >> input;
    int res=0;
    // res = fib.Fib_Bottom_Top(input);
    // std::cout << res << std::endl; 
    res=fib.Fib_helper(input);
    std::cout << res << std::endl;
    

    getchar();
    return 0;
}

