package com.leetcode.array;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class LongestSubArray
{
    /**
     * Find the longest subarray that sum up to 0
     * Test case:
     * input:  [ 1,2,3,5,-5,4,6,7,3,-10,-3,3,-10,40,200,-5,4]
     * output: [5,-5,4,6,7,3,-10,-3,3,-10]
     * @param args the input arguments
     */
    public static void main(String[] args) {

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
