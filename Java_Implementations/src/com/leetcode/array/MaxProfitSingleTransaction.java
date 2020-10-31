package com.leetcode.array;

public class MaxProfitSingleTransaction
{
    //Return the maximum profit by performing multiple stock transactions
    public static int SellStock(int[] prices) {
        int maxprofit = 0, min = Integer.MAX_VALUE;

        for(int i=0;i<prices.length;++i)
        {
            min=Math.min(min, prices[i]);
            maxprofit = Math.max(maxprofit, prices[i]-min);
        }

        return maxprofit;
    }

    public static void main(String[] args)
    {
        int[] input = {26,52,22,24,30,28,50};
        int res = SellStock(input);
        System.out.println(res);
    }
}
