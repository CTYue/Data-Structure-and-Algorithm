/*
 * main.cpp
 *
 *  Created on: Dec 23, 2017
 *      Author: yuzidong
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int reverse(int x)
	{
				long long temp;//Why?
				long k = 10;//Problem~!
				long l = 1;
				long long ans = 0;
				int i = 0;
				while( x/k )//9 counts
				{
					l *= 10;
					k *= 10;//10 digit max when 9 counts
					i++;
				}

				k = 10;
				i = 0;
				while(x/(k/10))// 10 counts
				{
					i++;
					temp = (x%k) /(k/10);//extract each integer
					ans += (temp*l);	//combine to a number
					k *= 10;//11 digit max when 10 counts
					l /= 10;
				}
				if( ans < INT_MIN || ans > INT_MAX)//
					return 0;
				else
					return ans;
	}
};

int main()
{
	Solution s;
	int x = -2147483648;//My code doesn't work when 10-digit overflow number input
	int result = 0;
	result = s.reverse(x);
	cout << endl;
	cout << "The input is: " << x << endl;
	cout << "The result is: ";
	cout << result << endl;
}
