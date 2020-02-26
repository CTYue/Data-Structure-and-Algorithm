/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-18 20:39:53
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-02-24 00:13:03
 * @Description: To be added.
 */

#include <iostream>

using namespace std;

int main()
{
	int x=0;
	cout<<"size of int: "<<sizeof(x)<<endl;
	double y=0;
	cout<<"size of double: "<<sizeof(y)<<endl;
	char z='z';
	cout<<"size of char: "<<sizeof(z)<<endl;//注意，char是1byte
	
	return 1;
}
