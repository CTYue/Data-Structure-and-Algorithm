/*
 * main.cpp
 *
 *  Created on: Jan 5, 2018
 *      Author: yuzidong
 */
//Some swap methods without using a temp variable
#include <iostream>
#define swap(a,b) a^=(b^=(a^=b));//优先级为从右往左
//运算优先级??
//#define swap(a,b)\
//a^=b;\
//b^=a;\
//a^=b;

using namespace std;
int x = 888, y = 666;

class exchange
{

	public:
	int swap_return(int a, int b)
	{
		return b;
		//cout << "Hi" << endl;
		//a = swap_return(x, y);
		//cout << "Hello World!" << endl;
	}


};

int main(void)
{
	cout << x << endl << y << endl;
	swap(x,y);
//	x^=y;
//	y^=x;
//	x^=y;
	cout << x << endl << y << endl;
}
