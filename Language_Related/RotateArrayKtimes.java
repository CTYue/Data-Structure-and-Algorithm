/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-04-24 17:24:47
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-04-24 17:24:47
 * @Description: To be added.
 */
public class RotateArrayKtimes
{
    static int[] solution(int A[], int N, int K)
    {
        //Check if K is odd or even
        if(K%2==0) return A;

        else
        {
            int[] res=new int[N];
            int pos=N;
            for(int i=0;i<N;++i)
            {
                res[pos-1]=A[i];
                pos--;
            }
            return res;
        }
    }

    public static void main(String[] args)
    {
        int[] input={1,2,3,4,5,6,7,8,9};
        //Rotate 3 times
        int[] res= RotateArrayKtimes.solution(input, input.length, 3);

        for(int n: res)
            System.out.print(n+", ");
        System.out.println();

        int[] input1={1,2,3,4,5,6,7,8,9};
        //Rotate 50 times
        int[] res1= RotateArrayKtimes.solution(input1, input1.length, 50);

        for(int n: res1)
            System.out.print(n+", ");
        System.out.println();
    }
}