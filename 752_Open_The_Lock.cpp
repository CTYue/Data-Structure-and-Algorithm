/*
 * main.cpp
 *
 *  Created on: Dec 23, 2017
 *      Author: yuzidong
 */

//Wrong Code
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Q3
class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {	//times of turing wheels to target
    		//deadends cannot appear
    		vector<string> allPath;
    		for(int i=0; i < deadends.size(); i++)
    		{
    			if(deadends[i] == "0000")
    				return -1;
    		}
    		int count = 0;
    		int binaryTarget = stoi(target);
    		cout << binaryTarget << endl;
    		int t4 = binaryTarget%10;//
    		binaryTarget /= 10;
    		int t3 = binaryTarget%10;
    		binaryTarget /= 10;
    		int t2 = binaryTarget%10;
    		binaryTarget /= 10;
    		int t1 = binaryTarget%10;

    		cout << t1 << endl;
    		cout << t2 << endl;
    		cout << t3 << endl;
    		cout << t4 << endl;

    		//calculate times from 0 to target number
    		if( t1!= 9)
    		{
    			count += t1;

    			if( t2 != 9)
    			{
    				count += t2;
    				if( t3 != 9)
    				{
    					count += t3;
    					if( t4 != 9)
    					{
    						count += t4;
    					}
    					else
    						count += 1;
    				}
    				else
    					count += 2;
    			}
    			else
    				count += 3;
    		}
    		else
    			count += 4;



    		//return -1;//cannot reach the target without deadends
    }
};

int main()
{
	Solution s;
	vector<string> test(10);
	string target = "9999";
	int result;
	result = s.openLock(test,target);
	cout << result << endl;
}
