/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-05 00:06:39
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-02-06 01:44:28
 * @Description: To be added.
 */
#include <iostream>

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
    //如果int和double相减会怎样？
    double diff(int n, double m)
    {
        if(n>(m*m*m)) return n-m*m*m;
        else  return m*m*m-n;
    }

    //这里有问题！
    double cbrt(int x)
    {
      int left=0,right=x;
      double pivot=0;
      double e=0.000000000000001;//double的精度是15位？
      long num=0;
      while(left<=right)
      {
        pivot=left+(right-left)/2;
        double error=diff(x, pivot);        
        if(error<=e)  return pivot;        
        
        else if(pivot*pivot*pivot>x)  right=pivot-1;
        else  left=pivot;
      }
      
      return right;
    }
};

int main(int argc, char** argv)
{
  int x=0;
  cin>>x;

  Integer_Solution i_s;
  auto res=i_s.cbrt(x);

  cout<<"Integer res == "<<res<<endl;

  Decimal_Solution d_s;
  res=d_s.cbrt(x);
  cout<<"Decimal res == "<<res<<endl;

}
