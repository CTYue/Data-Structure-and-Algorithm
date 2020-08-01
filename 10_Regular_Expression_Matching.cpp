/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-04 12:56:25
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2020-08-01 19:14:54
 * @Description: To be added.
 */

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    
    //Recursion Approach
    //Time Complexity: O(n)
    bool isMatch(string str, string pattern)
    {
        if(pattern.size()==0) return str.size()==0;

        //Consider that the 2nd char of pattern is '*', following a preceding char
        if(pattern.size()>1 && pattern[1]=='*')
        {
            //If remaining chars in given string matches the pattern
            //Then return true
            if(isMatch(str, pattern.substr(2)))
                return true;
            
            if((str[0]==pattern[0] || pattern[0]=='.') && str.length()>0)
                return isMatch(str.substr(1), pattern);
            return false;
        }
        //If the second char is NOT '*', then
        else
        {
            //Consider if the first chars match (or if pattern begins with a wildcard)
            //then compare the remainning chars
            if( (str[0]==pattern[0] || pattern[0]=='.') && str.size()>0)
                return isMatch(str.substr(1), pattern.substr(1));
                
            //if the first char in given string doesn't match the pattern (consider two cases: 
            //1. the pattern begins with '*' or '.'), then return false.
            return false;
        }
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}