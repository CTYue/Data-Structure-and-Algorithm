/*
 * main.cpp
 *
 *  Created on: Jan 13, 2018
 *      Author: yuzidong
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x)
    {
    		int k = 10;
    		int l = 1/10;
    		int res = 0;
    		int i = 0;
    		while(x/(k/10) != 0)
    		{
    			k *= 10;
    			l *= 10;
    			i++;
    			cout << "Value of l:" << l << endl;
    		}
    		k = 10;
    		while(x/(k/10) != 0)
    		{
//    			res += (x % k / (k/10)) * l;
    			int temp = (x % k / (k/10));
    			res += temp * l;
    			k *= 10;
    			l /= 10;
    			cout << endl;
    			cout << "Value of k:"<< k << endl;
    			cout << "Value of l:"<< l << endl;
    			cout << "Value of temp:" << temp << endl;
    			cout << res << endl << endl;
    		}
    }
};

int main(void)
{
	Solution s;
	int x = 123456789;
	cout << x << endl << endl;
	bool result = s.isPalindrome(x);
//	cout << result << endl;
}


