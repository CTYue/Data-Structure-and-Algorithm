package com.Leetcode.math;

import java.util.ArrayList;
import java.util.List;

public class fisher_yates_shuffle
{
    public static List<Integer> generateList(int n)
    {
        List<Integer> res = new ArrayList<>();

        for(int i=0;i<n;++i)
            res.add(i);

        return res;
    }

    public static void swap(List<Integer> input,int a, int b)
    {
        int temp=input.get(a);
        input.set(a, input.get(b));
        input.set(b, temp);
    }

    public static int getRandomNumber(int min, int max)
    {
        //这里没看懂！
        return (int)(Math.random()*(max-min)+min);
    }

    public static void main(String[] args)
    {
        List<Integer> input = generateList(10);
        System.out.println(input);
        int size = input.size();

//      Fisher–Yates shuffle
//        -- To shuffle an array a of n elements (indices 0..n-1):
//        for i from n−1 downto 1 do
//        j ← random integer such that 0 ≤ j ≤ i
//        exchange a[j] and a[i]

        //原理是：
        //将出现过的数字，放在当前array的末尾
        //每次循环，array的size都--,所以上次出现过的数字，下次绝对不会出现。
        //
        for(int i=size-1;i>=0;--i)
        {
            //Pick a random number between [0, i]
            int r = getRandomNumber(0,i);
            //Swap value at index r and i
            swap(input, r, i);//将已出现的数字放到array末尾，下次不会再出现。
        }

        System.out.println(input);
    }
}
