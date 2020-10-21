package com.leetcode.matrix;

import java.util.*;

public class Find_Number_Appears_K_Times_In_Matrix
{
//      Target: 3 (find smallest number that appears 3 times)
//      [1,   1,  0,  7],
//      [10, 23, 1, 26],
//      [23, 23, 23, 1]
//      For example,

    private static int solution()
    {
        int[][] input = {{1, 1, 0, 7},{10, 16, 1, 26},{23, 23, 23, 1}};
        int[] d={0,1,-1};
        int target=3;//Find the number which appears for 3 times (horizontally/vertically/obliquely)
        int m = input.length, n = input[0].length;

        int count=0;
        List<Integer> ans = new ArrayList<>();

        //这里应该不能用BFS，只能用DFS
        //只要任意方向的
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<d.length;++k)
                {
                    for(int l=0;l<d.length;++l)
                    {
                        //这个循环有问题，跳不出来！
                        System.out.println("Hello World!");

                        int r=i+d[k], c=j+d[l];

                        if(count==target)
                        {
                            ans.add(input[r][c]);
                            break;
                        }

                        if(r>0 && r<m-1 && c>0 && c<n-1 && input[r][c]==input[i][j] )
                        {
                            //这里有问题！
                            //应该跳转到哪里？

                            count++;
                            i=r;j=c;//跳转到相应的点
                        }

                        else
                            count=0;
                    }
                }
            }
        }

        Collections.sort(ans);

        return ans.size()==0?-1:ans.get(0);
    }

    public static void main(String[] args)
    {
        int res = solution();
        System.out.println(res);
    }
}
