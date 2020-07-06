/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-07-05 23:07:13
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-07-05 23:07:46
 * @Description: To be added.
 */ 
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int p1=num1.size()-1, p2=num2.size()-1;
        int carry=0;
        string res="";
                        
        while(p1>=0 || p2>=0)
        {
            int x= p1>=0?num1[p1]-'0':0;
            int y= p2>=0?num2[p2]-'0':0;
            
            // cout<<x<<endl;
            // cout<<y<<endl;
            
            int sum=(x+y+carry)%10;
            // cout<<sum<<endl;
            
            res.push_back('0'+sum);
            
            carry=(x+y+carry)/10;
            
            p1--,p2--;
        }
        if(carry>0)    res.push_back('0'+carry);//java和c++在处理'0'+num的时候不同，c++会将结果强制转换成char，而java则会输出'0'的ascii码和数字的和
        
        std::reverse(res.begin(),res.end());
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().addStrings(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}