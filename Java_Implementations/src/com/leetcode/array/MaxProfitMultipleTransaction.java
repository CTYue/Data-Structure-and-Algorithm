package com.leetcode.array;

public class MaxProfitMultipleTransaction
{
    //高频交易
    public static int SellStock(int[] prices)
    {
        int maxprofit = 0;

        for(int i = 1;i<prices.length;++i)
        {
            if(prices[i] > prices[i-1])
                maxprofit += prices[i] - prices[i-1];
        }

        return maxprofit;
    }

    public static void main(String[] args)
    {
        int[] input = {7,1,5,3,6,4};
        int res = SellStock(input);
        System.out.println(res);
    }
}
