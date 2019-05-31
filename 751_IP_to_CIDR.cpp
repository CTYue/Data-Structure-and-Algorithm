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
    }
};

 int main()
 {
	 Solution s;
	 string ip = "255.255.255.222";
	 s.ipToCIDR(ip,100);
 }


