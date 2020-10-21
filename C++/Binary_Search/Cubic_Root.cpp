/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-05 00:06:39
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-06 13:50:05
 * @Description: To be added.
 */

#include <iostream>
#include <typeinfo>
#include <cmath>
using namespace std;

class Integer_Solution
{
  public:
    int cbrt(int x)
    {
      int left=0, right=x;
      int res=0;long num=0;
      while(left<=right)
      {
            int pivot=left+(right-left)/2;//In case of overflow
            num=(long)pivot*pivot*pivot;
            if(num>x) right=pivot-1;
            else if(num<x) left=pivot+1;
            else return pivot;
      }

      return right;//为什么return right
    }
};


class Decimal_Solution
{
  public:
    double diff(double n, double m)
    {
        if(n>=(m*m*m)) return n-m*m*m;
        else  return m*m*m-n;
    }

    // My solution
    double cbrt(double x)
    {
      double left=0,right=x;
      double e=0.00000001;//double的精度是15位？

       while(left<=right)
       {
            double pivot=left+(right-left)/2;

            double error=diff(x, pivot);

            if(error<=e)  return pivot;

            //不能使用pivot+1和pivot-1,这样会损失精度
            if((pivot*pivot*pivot)>x)  right=pivot;
            else  left=pivot;
      }

      return right;
    }

};


int main(int argc, char** argv)
{
  double x=0;
  cin>>x;

  Integer_Solution i_s;
  auto res=i_s.cbrt(x);

  cout<<"cbrt(x) = "<<cbrt(x)<<endl;

  cout<<"Integer res == "<<res<<endl;

  Decimal_Solution d_s;

  auto res_1=d_s.cbrt(x);
  
  cout<<"My cbrt(x) = "<<res_1<<endl;

}
