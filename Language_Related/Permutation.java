/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-04-24 17:24:25
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-04-24 17:24:56
 * @Description: To be added.
 */
import java.util.HashSet;

public class Permutation
{
    static int solution(int[] A, int N)
    {
        HashSet<Integer> hashset = new HashSet<>();

        for(int n: A)
        {
            hashset.add(n);
        }

        boolean flag=true;
        for(int i=0;i<N;++i)
        {
            if(!hashset.contains(i+1))  flag&=false;
        }

        return flag==true?1:0;
    }

    public static void main(String[] args)
    {
        int[] input={4,1,3};
        int res=solution(input, input.length);

        if(res==1)
        {
            System.out.println("Input is an permutation!");
        }
        else
            System.out.println("Input is NOT an permutation!");

    }
}
