/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-05 00:06:39
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-02-06 16:08:12
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

    double cbrt(double x)
    {
      double left=0,right=x;
      double pivot=0;
      double e=0.0000001;//double的精度是15位？
      
      // while(left<=right)//这里为什么不能用传统的二分法？
      while(true)//要使用while(true)而不是传统的二分法
      {
        pivot=left+(right-left)/2;

        double error=diff(x, pivot);     

        if(error<=e)  return pivot;
        
        cout<<"right = "<<right<<endl;
        cout<<"left = "<<left<<endl;

        if((pivot*pivot*pivot)>x)  right=pivot-1;
        else  left=pivot+1;
      
        // if((pivot*pivot*pivot)>x)  right=pivot;
        // else  left=pivot;
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

  cout<<"Integer res == "<<res<<endl;

  Decimal_Solution d_s;

  auto res_1=d_s.cbrt(x);
  
  cout<<"Decimal res == "<<res_1<<endl;
  
  cout<<"cbrt(x) = "<<cbrt(x)<<endl;

}
