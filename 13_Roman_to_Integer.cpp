#include <iostream>
#include <string>
using namespace std;
class Solution {
public:    
    
      //Approach 1
    //Time complexity:O(n)
    //Space complexity:O(1)
    //Optimal solution
    //Hash map
//     int romanToInt(string s) 
//     {
//         int res=0;
//         if(s.empty() || s.length()==0)
//             return res;

//         int len=s.length();
//         unordered_map<char,int> map;
//         map.insert(std::make_pair<char,int>('I', 1));
//         map.insert(std::make_pair<char,int>('V', 5));
//         map.insert(std::make_pair<char,int>('X', 10));
//         map.insert(std::make_pair<char,int>('L', 50));
//         map.insert(std::make_pair<char,int>('C', 100));
//         map.insert(std::make_pair<char,int>('D', 500));
//         map.insert(std::make_pair<char,int>('M', 1000));
//         res=map[s[len-1]];
//         for(int i=len-2;i>=0;i--)
//         {
//             //If the left side is bigger than the right side
//             if(map[s[i]]>=map[s[i+1]])
//                 res+=map[s[i]];
//             //if the left side is smaller than the right side
//             else
//                 res-=map[s[i]];
//         }
        
//         return res;
//     }
    
    //Approach 2
    //Time complexity: O(n)
    //Soace complextiy:O(n)
    //Approach 2 is better than approach 1
    //in both time comlexity and 
    //space complexity
    int romanToInt(string s)
    {
        int res=0;
        if(s.empty() || s.length()==0)
            return res;
        
        if(s.find("IV")!=std::string::npos) res-=2;
        if(s.find("IX")!=std::string::npos) res-=2;
        if(s.find("XL")!=std::string::npos) res-=20;
        if(s.find("XC")!=std::string::npos) res-=20;
        if(s.find("CD")!=std::string::npos) res-=200;//Why CD?
        if(s.find("CM")!=std::string::npos) res-=200;
     
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I')   res+=1;
            if(s[i]=='V')   res+=5;
            if(s[i]=='X')   res+=10;
            if(s[i]=='L')   res+=50;
            if(s[i]=='C')   res+=100;
            if(s[i]=='D')   res+=500;
            if(s[i]=='M')   res+=1000;
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

//Test Stub
int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}