#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class Solution {
public:

    //Time complexity:
    //Space complexity:
    //Brute force Approach
    string multiply(string num1, string num2) 
    {
        if(num1.empty() || num2.empty())
            return "";
        if(num1=="0" || num2=="0")
            return "0";

        int len_1=num1.length();
        int len_2=num2.length();
        std::cout << "len_1: " << len_1 << std::endl;
        std::cout << "len_2: " << len_2 << std::endl;
        string res;
        int p[len_1+len_2];
        
        //Truncation position: i+j
        //Carry position: i+j+1
        for(int i=len_1-1;i>=0;i--)
        {
            for(int j=len_2-1;j>=0;j--)
            {
                int tmp=(num1[i]-'0')*(num2[j]-'0');
                std::cout << "tmp = " << tmp << std::endl;
                
                //i+j+1是数字低位
                //i+j是数字高位
                int sum=tmp+p[i+j+1];
                
                p[i+j]+=sum/10;//进位: carry
                p[i+j+1]=sum%10;//本位: truncation
                std::cout << "carry = " << p[i+j] << std::endl;
                std::cout << "truncation = " << p[i+j+1] << std::endl;
            }
        }
        
        ostringstream os;
        for(auto i:p)
        {
            std::cout << i << "";
            os<< i;
        }
        res=os.str();
        os.clear();
        
        // if(res[0]=='0')
            // res.erase(res.begin());
        
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
        
        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}