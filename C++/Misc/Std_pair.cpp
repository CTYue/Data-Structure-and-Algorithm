/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-26 16:51:30
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-26 16:53:17
 * @Description: To be added.
 */

#include <utility>
#include <iostream>
using namespace std;

int main (int argc, char* argv[]) 
{
  std::pair <int,char> foo (10,'x');

  std::get<0>(foo) = 666;
  std::get<1>(foo) = 'y';

  std::cout << "foo contains: ";
  std::cout << std::get<0>(foo) << " and " << std::get<1>(foo) << '\n';

  return 0;
}
