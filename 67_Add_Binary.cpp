/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-03 21:03:55
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-04 12:53:27
 * @Description: To be added.
 */

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) 
    {
        if(a.length()==0) return b;
        if(b.length()==0) return a;
        if(a.length()==0 && b.length()==0) return " ";
        
        string res="";
        int len_a=a.length(), len_b=b.length();
        int i=len_a-1;int j=len_b-1;
        int sum=0;
        
        while(i>=0 || j>=0 || sum==1)
        {
            //Compute sum of the last digits and carry
            sum+=(i>=0)?a[i]-'0':0;
            sum+=(j>=0)?b[j]-'0':0;
            
            std::cout << "==============" << std::endl;
            std::cout << "i = " << i << std::endl;
            std::cout << "j = " << j << std::endl;
            std::cout << "sum = " << sum << std::endl;
            std::cout << "sum%2 = " << sum%2 << std::endl;
            std::cout << "sum/2 = " << sum/2 << std::endl;
            std::cout << "==============" << std::endl;

            //本位
            res=char(sum%2+'0')+res;
            //进位
            sum/=2;
            
            i--;
            j--;
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}