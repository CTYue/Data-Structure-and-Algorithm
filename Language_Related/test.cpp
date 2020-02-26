#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int main()
{

        string str_1="Abc";
        string str_2="abc";
        string str_3="Abcd";
        string str_4="abcd";
        string str_5="ab";
	string str_6="dig1";
	string str_7="dig2";
	
	//cout<<str_1.compare(str_2)<<endl;
	//cout<<str_5.compare(str_2)<<endl;
	//cout<<str_2.compare(str_3)<<endl;	
	
	cout<<str_6.compare(str_7)<<endl;	
	vector<int> vec={0};
	for(auto item: vec)	cout<<item<<" ";
	cout<<endl;

//	vec.emplace_back(1,2,3,4);//You cannot push back more than one element here	
	vec.emplace_back(1);
	for(auto item: vec)	cout<<item<<" ";
	cout<<endl;

	return 1;
}
