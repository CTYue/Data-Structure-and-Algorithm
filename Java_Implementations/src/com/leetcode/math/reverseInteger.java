package com.leetcode.math;

//Reverse Integer using recursion
public class reverseInteger<StringBuild>
{
    //Input: 54321
    public long res = 0;
    public int reverse(int x)
    {
        recursion(x);

        int ans = (int)res;
        return ans;
    }

    public void recursion(int n)
    {
        if(n==0)
            return;

        int tmp = n%10;
        n/=10;

        res = res*10 + tmp;

        if(res >= Integer.MAX_VALUE || res<=Integer.MIN_VALUE)
        {
            res=0;
            return;
        }

        recursion(n);
    }

}
