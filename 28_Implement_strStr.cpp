#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    //Can you try Rabin Karp approach?
    int strStr(string source, string target) 
    {
//         if(target.empty())
//             return 0;
//         if(source.empty())
//             return -1;
        
//         int t_len = target.length();
//         int s_len = source.length();
//         int count = 0;
//         int index = 0;
//         std::cout << "target length: " << t_len << std::endl;
//         std::cout << "source length: " << s_len << std::endl;
        
//         for(int i = 0;i<=s_len-t_len;i++)//source
//         {
//             int j;
//             for(j = 0;j<t_len;j++)//target
//             {
//                 if(source[i+j]!=target[j]) break;
//             }
//             if(j==t_len)
//             {
//                 std::cout << "Hi world!" << std::endl;
//                 count++;
//                 index = i;
//                 break;
//             }
//         }        
        
//         if(count > 0)
//             return index;
//         else
//             return -1;
        
        if(target.empty())
            return 0;
        if(source.empty())
            return -1;
        
        int t_len = target.length();
        int s_len = source.length();
        int count = 0;
        int index = 0;
        
        for(int i = 0;i<s_len;i++)
        {
            int j;            
            for(j = 0;j<t_len;j++)
            {
                if(source[i+j] != target[j]) break;
            }
            
            if(j==t_len)
            {
                index = i;
                count++;
                break;
            }
        }
        
        if(count>0)
            return index;
        else
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
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);
        
        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}