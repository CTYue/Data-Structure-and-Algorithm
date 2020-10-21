#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) 
    {
        if(n<1)
            return "";

        if(n==1) return "1";
        if(n==2) return "11";

        string str="11";
        for(int i=3;i<=n;i++)
        {
            //Traversing the nth(n>=3) string 
            //新建空白str(current string)
            str+='0';//resize the string
            int len=str.length();
            int count=1;
            string tmp;

            //Build the current string
            //填充当前string
            for(int j=1;j<len;j++)
            {
                //Non-duplicate number
                if(str[j]!=str[j-1])
                {
                    tmp+=count+'0';
                    tmp+=str[j-1];
                    count=1;
                }
                //Find duplicate number
                else count++;
            }
            //Update current string
            str=tmp;
        }
        return str;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main(int argc, char* argv[]) {
    if(argc<1) return 1;

    string line;
    while (getline(cin, line)) 
    {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }

    getchar();
    return 0;
}