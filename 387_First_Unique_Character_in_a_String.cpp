/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-06 22:55:18
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-11 00:07:36
 * @Description: To be added.
 */

#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;
class Solution_map {
public:
    //Linear Time Solution
    //Time Complexity: O(N)
    //Space Complexity: O(N)
    int firstUniqChar(string s) 
    {
        map<char, int> count;
        
        for(char ch: s)
        {
            if(count.find(ch)==count.end()) count.insert(pair<char,int>(ch, 1));
            else count[ch]++;
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(count[s[i]]==1)   return i;
        }
        
        return -1;
    }
};


class Solution_array
{
public:
    int firstUniqChar(string s)
    {
        int arr[256];
        memset(arr,0,sizeof(arr));//Initialize the array with all 0s explicitly
        for(char ch:s)  arr[ch-'a']++;

        for(int i=0;i<s.length();i++)
        {
        if(arr[s[i]-'a']==1)    return i;
        }

        return -1;
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
        
        int ret = Solution_map().firstUniqChar(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}