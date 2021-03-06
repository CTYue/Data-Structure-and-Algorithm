package com.leetcode.heap;

import java.util.*;

class myComparator implements Comparator<int[]>
{
    @Override
    public int compare(int[] x, int[] y)
    {
        if(x[0]==y[0])
            return x[1]-y[1];//lower index first
        else
            return y[0]-x[0];//higher score first
    }
}

//Audible/Ford Online Assessment
public class Team_Formation
{
    public static long getScores(int[] scores, int team_size, int m) {
        long res=0;

        //将原有的列表分成左右两部分，左边保存的是first m个人，右边保存的是last m个人
        PriorityQueue<int[]> leftPart = new PriorityQueue(new myComparator());
        PriorityQueue<int[]> rightPart = new PriorityQueue(new myComparator());

        int left = m - 1;
        int right = scores.length - m;
        for (int i = 0; i <= left && i < scores.length; i++)
        {
            leftPart.offer(new int[]{scores[i], i});//{score, index}
        }

        for (int i = scores.length - 1; i >= right && i > left && i >= 0; i--)
        {
            rightPart.offer(new int[]{scores[i], i});//{score, index}
        }

        while (team_size-- > 0 && (!leftPart.isEmpty() || !rightPart.isEmpty())) {
            int leftMax = !leftPart.isEmpty() ? leftPart.peek()[0]: -1;
            int rightMax = !rightPart.isEmpty() ? rightPart.peek()[0]: -1;

            if (leftMax >= rightMax) {
                res += leftMax;
                leftPart.poll();
                if (left + 1 < right && left + 1 < scores.length) {
                    leftPart.offer(new int[]{scores[++left], left});
                }
            } else {
                res += rightMax;
                rightPart.poll();

                //Refill the priorityQueue in case the team size is larger than 2*m
                if (right - 1 > left && right - 1 >= 0)
                {
                    rightPart.offer(new int[]{scores[--right], right});
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums1 = {17, 12, 10, 2, 7, 2, 11, 20, 8};
        int size1 = 3, m1 = 8;
        System.out.println(getScores(nums1, size1, m1));

        int[] nums2 = {6, 18, 8, 14, 10, 12, 18, 9};
        int size2 = 80, m2 = 3;
        System.out.println(getScores(nums2, size2, m2));

        int[] nums3 = {18, 5, 15, 18, 11, 15, 9, 7};
        int size3 = 5, m3 = 1;
        System.out.println(getScores(nums3, size3, m3));


        ArrayList<Integer> new_arr = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 6));
        Collections.sort(new_arr, (a,b)->b-a);

        System.out.println(new_arr);
    }
}