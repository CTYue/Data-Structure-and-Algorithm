/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-04 12:56:25
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-10 08:28:19
 * @Description: To be added.
 */

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    
//     //Recursion Approach
//     //Time Complexity:Unknown
//     //Space Complexity:Unknown
//     //Problem in this solution
//     bool isMatch(string s, string p)
//     {
//         if(s.empty() || p.empty())
//             return false;
        
//         //if length of pattern is 1
//         bool first_match=(!s.empty() && (p[0]==s[0] || p[0]=='.'));
        
//         //if length of pattern >= 2
//         //
//         if(p.length()>=2 && p[1]=='*')
//             return ( isMatch(s, p.substr(2,p[p.length()-1])) || (first_match && isMatch(s.substr(1,s[s.length()-1]),p)));

        
//         //if length of pattern <2 or p[1]!='*'
//         //
//         else
//             return (first_match && isMatch(s.substr(1,s[s.length()-1]),p.substr(1,p[p.length()-1])));
//     }
    

    //Dynamic programming
    //Time Complexity: ???
    //Space Complexity: ???
    bool isMatch(string s, string p) 
    {        
        //Construct the DP array.
        bool T[s.length()+1][p.length()+1]={};
        
        T[0][0]=true;
        //Handle patterns like a* a*b or a*b*c*
        for(int i=1;i<(sizeof(T[0])/sizeof(T[0][0]));i++)
        {
            if(p[i-1]=='*')
            {
                T[0][i]=T[0][i-2];
            }   
        }
        
        //std::cout << "s.length() = " << s.length() << std::endl;
        //std::cout << "p.length() = " << p.length() << std::endl;
        // std::cout << "sizeof(T)/sizeof(T[0]) = " << sizeof(T)/sizeof(T[0]) << std::endl;
        // std::cout << "sizeof(T[0])/sizeof(T[0][0]) = " << sizeof(T[0])/sizeof(T[0][0]) << std::endl;
        // std::cout << "sizeof(T[1])/sizeof(T[1][0]) = " << sizeof(T[1])/sizeof(T[1][0]) << std::endl;// sizeof(T[1])/sizeof(T[1][0]) = 6
        
        for(int i=1;i<(sizeof(T)/sizeof(T[0]));i++)
        {
            for(int j=1;j<(sizeof(T[0])/sizeof(T[0][0]));j++)
            {
                if(p[j-1]=='.' || p[j-1]==s[i-1])
                    T[i][j]=T[i-1][j-1];
                else if(p[j-1]=='*')
                {  
                    T[i][j]=T[i][j-2];
                    if(p[j-2]=='.' || p[j-2]==s[i-1])
                    {
                        std::cout << "i = " << i << std::endl;
                        std::cout << "j = " << j << std::endl;
                        T[i][j]=T[i][j] | T[i-1][j];
                    }
                }  
                else
                        T[i][j]=false;
            }
        }
        
        return T[s.length()][p.length()];
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