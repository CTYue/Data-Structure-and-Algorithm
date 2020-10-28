package com.leetcode.array;

import java.util.HashMap;
import java.util.Map;

public class SubarraySumEqualsK
{
    //Given an array of integers and an integer k,
    //you need to find the total number of continuous subarrays whose sum equals to k.
    //Input:nums = [1,1,1], k = 2
    //Output: 2
    public static int subarraySum(int[] nums, int k)
    {
        if(nums==null || nums.length==0)
            return 0;

        Map<Integer, Integer> hashmap = new HashMap<>();
        hashmap.put(0,1);
        int sum=0, count=0;

        for(int i=0;i < nums.length;++i)
        {
            sum+=nums[i];

            count+=hashmap.getOrDefault(sum-k,0);
            hashmap.put(sum, hashmap.getOrDefault(sum, 0)+1);
        }

        return count;
    }

    public static void main(String[] args)
    {
        int[] nums = {1,2,3};
        int k = 3;

        int res = subarraySum(nums, k);
        System.out.print(res);
    }

}
