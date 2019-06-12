#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //Dynanmic Programming Approach
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    int numDecodings(string s) 
    {
        if(s.empty() || s[0]=='0')
            return 0;
        
        if(s.length()==1)
            return 1;
        
        int len=s.length();
        
        int cur=0;
        int pre1=1, pre2=1;
        
        for(int i=1;i<len;i++)
        {
            cur=0;
            
            //读取第i个char
            int first=(s[i]-'0');//
            std::cout << "===============" << std::endl;
            std::cout << "i = " << i << std::endl;
            std::cout << "s[i] = " << s[i] << std::endl;
            std::cout << "first = " << first << std::endl;
            
            //stoi: string to integer
            //读取第i-1个char
            //从i-1开始的2个char
            int second=stoi(s.substr(i-1,2));
            std::cout << "i-1 = " << i-1 << std::endl;
            std::cout << "s.substr(i-1,2) = " << s.substr(i-1,2) << std::endl;
            std::cout << "second = " << second << std::endl;
            
            if(first>=1 && first<=9)
                cur+=pre1;

            if(second>=10 && second<=26)
                cur+=pre2;
            
            std::cout << "cur = " << cur << std::endl;
            
            //Update pre2 and pre1
            pre2=pre1;
            pre1=cur;
        }

        return cur;
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
        
        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}