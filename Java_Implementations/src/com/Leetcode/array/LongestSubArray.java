package com.Leetcode.array;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class LongestSubArray
{
    public static void main(String[] args) {
        // [ 1,2,3,5,-5,4,6,7,3,-10,-3,3,-10,40,200,-5,4] longest subarray sum to 0
        // [5,-5,4,6,7,3,-10,-3,3,-10] length = 10 [3,12]
        //注意：subArray的定义是，不改变原数字的顺序下，从原array中截取一段。
        int[] input = {1, 2, 3, 5, -5, 4, 6, 7, 3, -10, -3, 3, -10, 40, 200, -5, 4};
        int sum = 0, maxLen = 0;
        int target = 0;
        int left = Integer.MAX_VALUE, right = Integer.MIN_VALUE;

        Map<Integer, Integer> hashmap = new HashMap<>();

        for(int i=0;i<input.length;++i)
        {
            sum+=input[i];

            if(sum==target)
                maxLen=i+1;

            //如果当前sum已经在前序subArray中出现过，那么说明中间有一段加起来为0
            if(hashmap.containsKey(sum-target))
            {
                maxLen=Math.max(maxLen, i - hashmap.get(sum-target));
                left=Math.min(left, hashmap.get(sum-target)+1);
                right=Math.max(right, i);
            }

            if(!hashmap.containsKey(sum))
                hashmap.put(sum,i);
        }

        System.out.println("\n==========\nmaxLen == "+maxLen);
        System.out.println("left: "+left+" right: "+right+"\n================");

        int[] res = Arrays.copyOfRange(input, left, right+1);//[)
        System.out.println("res array: ");
        for(int n: res)
            System.out.print(n+ " ");

        System.out.println();
    }

}
