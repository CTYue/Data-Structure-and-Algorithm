//
//  main.cpp
//  Length_of_last_word
//
//  Created by Zidong Yu on 5/30/18.
//  Copyright © 2018 Zidong Yu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    string s = "Hi World";
    //    string s = "";
    int len = 0;
    size_t length = s.length();//为什么用size_t？
    
    if(!s.empty())
    {
        for(size_t i = length - 1; i > 0; i--)
        {
            //string是如何存储的?
            if( s[i] != ' ' )
                len++;
            else if( len > 0 )//这里要注意
                break;
        }
    }
    else if(s.empty())
        len = 0;
    
    cout << "Length of last word in s: " << len << endl;
}
