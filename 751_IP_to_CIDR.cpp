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
//Q2
class Solution {
public:
    vector<string> ipToCIDR(string ip, int range)
	{
    		//Interprete string to separate binary numbers
    		string str1,str2,str3,str4;
    		int p1,p2,p3,p4;
    		int binaryIP;
    		str1 = ip.substr(0,3);
    		str2 = ip.substr(4,3);
    		str3 = ip.substr(8,3);
    		str4 = ip.substr(12,3);
    		p1 = stoi(str1);
    		p2 = stoi(str2);
		p3 = stoi(str3);
		p4 = stoi(str4);

//		cout << "strings" << endl;
//		cout << str1 << endl;
//		cout << str2 << endl;
//		cout << str3 << endl;
//		cout << str4 << endl;
//
//		cout << "integers" << endl;
//		cout << p1 << endl;
//		cout << p2 << endl;
//		cout << p3 << endl;
//		cout << p4 << endl;

		//What is range?
    }
};
 int main()
 {
	 Solution s;
	 string ip = "255.255.255.222";
	 s.ipToCIDR(ip,100);
 }


