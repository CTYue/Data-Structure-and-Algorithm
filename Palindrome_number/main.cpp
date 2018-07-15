/*
 * main.cpp
 *
 *  Created on: Jan 13, 2018
 *      Author: yuzidong
 */
//Please be advised that negative numbers are not palindrome numbers.
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x)
    {
    		long int k = 10;
    		long int l = 1;
    		int res = 0;
    		int i = 0;
    		while(x/l != 0)//division by zero
    		{
    			l *= 10;
    			i++;
//    	cout << "Value of l:"<< l << endl;
   		}

    		l /= 10;
//    	cout << endl;
    		while(x/(k/10) != 0)//division by zero
    		{
    			int temp = (x % k / (k/10));
    			res += temp * l;
    			k *= 10;
    			l /= 10;
//    	cout << "Value of k:"<< k << endl;
    		}
    		if( x >= 0 && res >= 0 && x == res)
    			return true;
    		else
    			return false;
    }
};

int main(void)
{
	Solution s;
	int x = -2147447412;
	cout << x << endl << endl;
	bool result = s.isPalindrome(x);
	cout << result << endl;
}
