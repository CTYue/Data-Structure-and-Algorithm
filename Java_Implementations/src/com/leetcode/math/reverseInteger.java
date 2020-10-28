package com.leetcode.math;

//Reverse Integer using recursion
public class reverseInteger<StringBuild>
{
    //Input: 54321
    public static long res = 0;
    public static int reverseInteger(int x)
    {
        recursion(x);

        int ans = (int)res;
        return ans;
    }

    public static void recursion(int n)
    {
        if(n==0)
            return;

        int tmp = n%10;//取得当前digit
        n/=10;//

        res = res*10 + tmp;//res*10用于将上一次的digit增位，tmp是这次的本位
        if(res >= Integer.MAX_VALUE || res<=Integer.MIN_VALUE)
        {
            res=0;
            return;
        }
        recursion(n);
    }

    public static void main(String[] args)
    {
        int input = 54321;
        System.out.println("input: "+ input);

        int ans = reverseInteger(input);
        System.out.println("output: "+ans);
    }

}
