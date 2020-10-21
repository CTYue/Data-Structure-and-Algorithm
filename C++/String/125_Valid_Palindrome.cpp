/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-21 00:34:07
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-21 00:34:15
 * @Description: To be added.
 */
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) 
    {
        if(s.length()==0)   return true;
        
        //不考虑标点符号和大小写
        int left=0, right=s.length()-1;
        
        //Two points
        while(left<=right)
        {
            char lchar=s[left], rchar=s[right];
            
            if(!isalnum(lchar)) left++;
            else if(!isalnum(rchar)) right--;
            
            else
            {
                if(tolower(lchar)!=tolower(rchar))  
                    return false;
                left++;right--;
            }
        }
        
        return true;
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
        
        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}