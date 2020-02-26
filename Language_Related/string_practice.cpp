/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-23 00:25:07
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-02-23 23:49:07
 * @Description: To be added.
 */
#include<iostream>
#include<string>

using namespace std;
//Practice C++ String
class insert_string
{
  
int n=111;//默认为private
public:int m=222;

};

int main()
{
  string A="Heo";
  string B="ll";
  //String insertion
  A.insert(2,B);
  cout<<A<<endl;

  insert_string s;
  cout<<s.m<<endl;

  //

  return 1;
}
