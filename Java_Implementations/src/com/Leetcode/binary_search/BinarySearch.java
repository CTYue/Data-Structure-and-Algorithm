package com.Leetcode.binary_search;

import java.util.LinkedList;
import java.util.*;

public class BinarySearch
{
    public static List<Integer> generateList(int n)
    {
        List<Integer> input = new LinkedList<Integer>();
        for(int i=1;i<n+1;++i)
            input.add(i);

        return input;
    }

    public static void main(String[] agrs)
    {
        List<Integer> input = generateList(10);
        System.out.println(input);

        int target = 1;
        int left=0, right=input.size()-1;

        Collections.sort(input, Collections.reverseOrder());

        while(left<=right)
        {
            int mid = left+(right-left)/2;

            if(input.get(mid)>target)
            {
//                right=mid-1;
                left=mid+1;
            }
            else if(input.get(mid)<target)
            {
//                left=mid+1;
                right=mid-1;
            }
            else
            {
                System.out.println(mid);
                break;
            }
        }

    }

}
