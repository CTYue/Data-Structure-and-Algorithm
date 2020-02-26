#include <iostream>

using namespace std;

int main()
{
//	int m=(1&0xffffffff);
//	int n=(2<<m);
//	cout<<"m = "<<m<<endl;
//	cout<<"n = "<<n<<endl;
//	cout<<"1<<4 = "<< 1<<4 <<endl;

	int i=1;
	cout<<"sizeof i = "<<sizeof(i)<<endl;
	cout<<"i = "<<i<<endl;
 	int j=(i<<4);// i<<3 is different from 3<<i !!!
	cout<<"i<<4 = "<<j<<endl;
	int k=(4<<i);
	cout<<"4<<i = "<<k<<endl;
}
