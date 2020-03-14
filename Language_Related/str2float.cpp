/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-14 12:33:02
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-14 13:11:23
 * @Description: To be added.
 */

#include<iostream>
#include<string>
#include <limits>
#include <cmath>

using namespace std;
//Input: no "E", just numbers with dot
float str2float(string num)
{
  size_t length=num.length();
  float flt_min=std::numeric_limits<float>::min();
  float flt_max=std::numeric_limits<float>::max();
  
  if(length==0) 
  {
    cout<<"Empty string!"<<endl;
    return flt_min;
  }
  
  //Count dot, if not found or more than 1, return flt_min
  if(std::count(num.begin(), num.end(), '.')!=1) 
  {
    cout<<"No dot, not a valid float number!"<<endl;
    return flt_min;
  }

  int sign=1;
  size_t pos=0;
  double res=0;//Use double to handle float overflow 
  double dec=0;
  if(num[0]=='-') sign=-1;
  
  while(num[pos]=='-' || num[pos]=='+') ++pos;

  //Handle integer
  for(size_t i=pos;i<length;++i)
  {
      if(num[i]=='.')
      {
        pos=i;
        break;
      }
    
    else if(num[i]>='0' && num[i]<='9')
    {
       res=res*10+(num[i]-'0');

       if(sign==-1 && res*(-1)<flt_min) 
       {
         cout<<"Integer part: less than flt_min, return flt_min!"<<endl;
         return flt_min;
       }
       if(sign==1 && res>flt_max) 
       {
          cout<<"Integer part: greater than flt_max, return flt_max!"<<endl;
          return flt_max;
       }
    }
    //If not number, then return flt_min
    else 
    {
      cout<<"Integer part: "<<num[i]<<"Not a number! Return flt_min."<<endl;
      return flt_min;
    }
  }

  //Handle decimal
  for(size_t i=pos+1;i<length;++i)
  {
    if(num[i]>='0' && num[i]<='9') 
    {
        dec=dec*10+(num[i]-'0');
    }
    else 
    {
      cout<<"Dec part: "<<num[i]<<"Not a number! Return flt_min"<<endl;
      return flt_min;
    }
  }
  
  int precision=(length-pos-1);
  precision*=-1;

  dec*=pow(10, precision);
  res+=dec;
  res*=sign;

  if(sign==-1 && res<=flt_min) 
  {
    cout<<"res is less than flt_min!"<<endl;
    return flt_min;
  }
  else if(sign==1 && res>=flt_max) 
  {
    cout<<"res is greater than flt_max!"<<endl;
    return flt_max;
  }
  else return res;
}


int main()
{
  //String to float in brute force
  string float_str="6.66666";
  cout<<"Input: "<<float_str<<endl;
  cout<<"float min: "<<std::numeric_limits<float>::min()<<endl;
  cout<<"float max: "<<std::numeric_limits<float>::max()<<endl;
    
  auto res=str2float(float_str);

  cout<<"res = "<<res<<endl;

  return 1;
}