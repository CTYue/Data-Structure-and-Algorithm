package com.leetcode.string;

public class Shortest_Length_Substring_Containing_All_Characters
{
//    static String findShortestSubStr(String input)
//    {
//        int n=input.length();
//        int unique_count=0;
//
//        boolean[] seen = new boolean[256];
//        Arrays.fill(seen, false);
//
//        for(int i=0;i<n;++i)
//        {
//            if(seen[input.charAt(i)]==false)
//            {
//                seen[input.charAt(i)]=true;
//                unique_count++;
//            }
//        }
//
//        int left=0, start=0;
//        int minLen=Integer.MAX_VALUE;
//
//        int count=0;
//        int[] curr_count=new int[256];
//
//        for(int i=0;i<n;++i)
//        {
//            curr_count[input.charAt(i)]++;
//
//            if(curr_count[input.charAt(i)] == 1)
//                count++;//统计出现一次的字符的个数
//
//            //一旦original string的unique_count等于当前的unique count
//            //则开始minimize window
//            if(count == unique_count)
//            {
//                while(curr_count[input.charAt(left)] > 1)
//                {
//                    if(curr_count[input.charAt(left)]>1)
//                        curr_count[input.charAt(left)]--;//???
//                    left++;
//                }
//
//                //Update window size
//                minLen=Math.min(minLen, i-left+1);
//                start=left;
//            }
//        }
//
//        return minLen==Integer.MAX_VALUE? input:input.substring(start, start+minLen);
//    }

    //Watch: https://www.youtube.com/watch?v=qzYhjk-nDGU
    static String findShortestSubStr(String input)
    {
        if(input == null || input.length()==0)
            return "";

        int[] dict = new int[256];
        int unique_counter=0;

        for(char c: input.toCharArray())
        {
            if(dict[c-'a']==0)
            {
                unique_counter++;
                dict[c-'a']++;//这里是用+1还是++？
            }
        }

        int start=0, end=0, minStart=-1, minLen=Integer.MAX_VALUE;

        while(end<input.length())
        {
            char right = input.charAt(end);

            //如果右边界在hashmap中，则长度--
            if(dict[right-'a']>0)
            {
                unique_counter--;
                dict[right-'a']--;
            }
            end++;

            //当unique_counter为0的时候，说明已经找到了一个满足条件的窗口
            //这里接着minimizing the window
            while(unique_counter==0)
            {
                minLen = Math.min(minLen, end - start);
                //minStart有问题！
//                if(minLen > end-start)
//                minStart = start;
                //也有可能是start点出现了问题!
                if(minStart==-1)
                    minStart=start;

                char left = input.charAt(start);
                dict[left-'a']++;//这里为什么要++？

                if (dict[left-'a']>0)
                    unique_counter++;

                //这里怎么操作？
                start++;
            }
        }

        return minLen==Integer.MAX_VALUE?"":input.substring(minStart, minStart+minLen);
    }

    public static void main(String[] args)
    {
        String str = "aabcbcdbca";
        String res = findShortestSubStr(str);
        //Correct answer: dbca
        System.out.println("Input String: "+str +"\n"+"Shortest Substring: "+res);
    }
}
