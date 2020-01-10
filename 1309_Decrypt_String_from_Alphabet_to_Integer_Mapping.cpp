/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-01-06 00:01:05
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-06 00:13:59
 * @Description: To be added.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) 
    {
        string res;
        int len = s.length();
        
        for(int i=0;i<s.length();i++)
        {
            //Translate each number separately
            if(s[i+2]=='#' && i+2<len)//这里有问题! heap-buffer-overflow!
            // if(i+2<len && s[i+2]=='#')
            {               
                res+='j'+ (s[i]-'1')*10 + (s[i+1]-'0');//;
                i+=2;
            }
            
            //Translate the two digit number
            else    res+='a'+ (s[i]-'1');
        }

        return res;        
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}


int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().freqAlphabets(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}