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

//Q3
class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {	//times of turing wheels to target
    		//deadends cannot appear
    		vector<string> allPath;
    		vector<string>
    		vec
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



//Q2
//class Solution {
//public:
//    vector<string> ipToCIDR(string ip, int range)
//	{
//    		//Interprete string to separate binary numbers
//    		string str1,str2,str3,str4;
//    		int p1,p2,p3,p4;
//    		int binaryIP;
//    		str1 = ip.substr(0,3);
//    		str2 = ip.substr(4,3);
//    		str3 = ip.substr(8,3);
//    		str4 = ip.substr(12,3);
//    		p1 = stoi(str1);
//    		p2 = stoi(str2);
//		p3 = stoi(str3);
//		p4 = stoi(str4);
//
////		cout << "strings" << endl;
////		cout << str1 << endl;
////		cout << str2 << endl;
////		cout << str3 << endl;
////		cout << str4 << endl;
////
////		cout << "integers" << endl;
////		cout << p1 << endl;
////		cout << p2 << endl;
////		cout << p3 << endl;
////		cout << p4 << endl;
//
//		//What is range?
//    }
//};
// int main()
// {
//	 Solution s;
//	 string ip = "255.255.255.222";
//	 s.ipToCIDR(ip,100);
// }



//class Solution {
//public:
//
//	int findMax(vector<int>& nums)
//	{
//	//find the largest num in array
//			int max = 0;
//			int temp;
//			for(int i = 0 ; i < nums.size(); i++)
//			{
//				if(nums[i] > max)
//					max = nums[i];
//			}
//			return max;
//	}
//
//    int dominantIndex(vector<int>& nums)
//    {
//    		int max = findMax(nums);
//    		vector<int> arrayRest;
//    		for(int i = 0; i < nums.size(); i++)
//    		{
//    			if(nums[i] != max)
//    			{
//    				arrayRest.push_back(nums[i]);
//    				//cout << nums[i] << endl;
//    			}
//
//    		}
//    		int max_rest = findMax(arrayRest);
//    		if(max >= 2*max_rest)
//    			//return the index of the max in arrayRest
//    		{
//    			for(int i = 0; i < nums.size();i++)
//    			{
//    				if(nums[i] == max)
//    					return i;
//    			}
//    		}
//
//    		else
//    			return -1;
//    }
//};
//
//int main()
//{
//	Solution s;
//	//int nums[] = {3,6,1,0};
//	int nums[] = {1,2,3,4};
//	vector<int> a(begin(nums),end(nums));
//	int result;
//	result = s.dominantIndex(a);
////	result = s.findMax(a);
////	for(int i = 0; i < a.size(); i++)
////		cout << a[i] << endl;
//	cout << result << endl;
//
//	return 0;
//}
