/*
 * main.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: yuzidong
 */
#include<iostream>
using namespace std;


int main(int argc, char* argv[])
{
    // This is just to demonstrate 32 vs. 64
	// You can use -m32 parameter in g++ to switch to
	// 32bit environment
    int* x = (int*)0xFFFFFFFFFFFFFFFF;
    int* y = (int*)0x00000000FFFFFFFF;
    std::cout << std::hex <<
        "&x = " << x << std::endl <<
        "&y = " << y << std::endl;
    if (y == x) {
        std::cout << "RIGHT!" << std::endl;
    } else {
        std::cout << "WRONG!" << std::endl;
    }
    return 0;
}
