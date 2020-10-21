#include<iostream>

using namespace std;

void foo(char* input, int shift)
{
	while(input) printf("%c",*(input++)+shift);
}

int main()
{
	char input[10]="K*XOa*NKc";
	foo(input,1);
	return 1;
}
