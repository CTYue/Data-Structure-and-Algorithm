#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) 
    {
        string res="";
        if(s.empty())
            return res;
        if(numRows==1)  return s;
        
        int size=min(numRows,int(s.length()));
        vector<string> rows(size);
        bool goingDown=false;
        int curRow=0;
        for(int i=0;i<s.length();i++)
        {
            rows[curRow]+=s[i];//append char to each row(string)
            
            if(curRow==0 || curRow==numRows-1)
                goingDown=!goingDown;
            
            if(goingDown)   curRow++;
            else curRow--;
        }
        
        for(int i=0;i<rows.size();i++) res+=rows[i];
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}