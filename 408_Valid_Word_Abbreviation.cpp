/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-23 14:51:18
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-25 14:52:35
 * @Description: To be added.
 * @AC: Yes: 
 */

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
    //Two pointers
    //Time Complexity: 
    //Space Complexity: O(1) (No auxiliary space needed)
    bool validWordAbbreviation(string word, string abbr) 
    {
        std::cout << "word.size() = " << word.size() << std::endl;
        std::cout << "abbr.size() = " << abbr.size() << std::endl;
        
        int i=0,j=0;
        while(i<word.size() && j<abbr.size())
        {
            if(std::isdigit(abbr[j]))
            {
                if(abbr[j]=='0')    return false;
                int count=0;
                //Make sure j is in bounds in the very begining.
                while(j<abbr.size() && std::isdigit(abbr[j]))
                    count=count*10+(abbr[j++]-'0');
                i+=count;
            }
            else if(word[i++]!=abbr[j++])   return false;
        }
        
        return i==word.size() && j==abbr.size();
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
        string word = stringToString(line);
        getline(cin, line);
        string abbr = stringToString(line);
        
        bool ret = Solution().validWordAbbreviation(word, abbr);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}