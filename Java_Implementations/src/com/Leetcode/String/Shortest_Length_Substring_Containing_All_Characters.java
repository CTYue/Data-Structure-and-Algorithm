package com.Leetcode.String;

import java.util.Arrays;

public class Shortest_Length_Substring_Containing_All_Characters
{
    static String findShortestSubStr(String input)
    {
        int n=input.length();
        int unique_count=0;

        boolean[] seen = new boolean[256];
        Arrays.fill(seen, false);

        for(int i=0;i<n;++i)
        {
            if(seen[input.charAt(i)]==false)
            {
                seen[input.charAt(i)]=true;
                unique_count++;
            }
        }

        int left=0, start=0;
        int minLen=Integer.MAX_VALUE;

        int count=0;
        int[] curr_count=new int[256];

        for(int i=0;i<n;++i)
        {
            curr_count[input.charAt(i)]++;

            if(curr_count[input.charAt(i)] == 1)
                count++;//统计出现一次的字符的个数

            //一旦original string的unique_count等于当前的unique count
            //则开始minimize window
            if(count == unique_count)
            {
                while(curr_count[input.charAt(left)] > 1)
                {
                    if(curr_count[input.charAt(left)]>1)
                        curr_count[input.charAt(left)]--;//???
                    left++;
                }
                //Update window size
                minLen=Math.min(minLen, i-left+1);
                start=left;
            }
        }

        return minLen==Integer.MAX_VALUE? input:input.substring(start, start+minLen);
    }

    public static void main(String[] args)
    {
        String str = "aabcbcdbca";
        String res = findShortestSubStr(str);

        System.out.println("Input String: "+str +"\n"+"Shortest Substring: "+res);
    }

}
