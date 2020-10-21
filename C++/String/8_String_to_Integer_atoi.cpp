#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int length = str.size();
        long long ret_64 = 0;
        int op = 1;
        int p = 0;
        while (str[p] == ' ') ++p;
        
        if (str[p] == '+' || str[p] == '-') 
        {
            if (str[p] == '-') op = -1;
            else op = 1;
            p++;
        }
 
        for(int i=p;i<length;i++)
            if ('0' <= str[i] && str[i] <= '9') 
            {
                ret_64 = ret_64 * 10 + (str[i] - '0');
                if(op==-1 && ret_64>(long long)(-1)*INT32_MIN)
                    return INT32_MIN;
                
                if(op==1 && ret_64 > (long long)INT32_MAX)
                    return INT32_MAX;
                
            }   else break;
                
        std::cout << "INT32_MAX = " << INT32_MAX << std::endl;
        std::cout << "INT32_MIN = " << INT32_MIN << std::endl;
        
        return ret_64*op;
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
        string str = stringToString(line);
        
        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}