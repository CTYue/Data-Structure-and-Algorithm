/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-05-23 08:59:52
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-20 21:37:44
 * @Description: To be added.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution_1 {
public:
    //Approach 1: Assign chars to row
    //Time complexity:O(n)
    //Space complexity:???
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
        
        //将char分配到每个row
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


class Solution_2 {
public:
    
    //Approach 2
    //Interval: Normal Row
    //Setp:Oblique Row
    //Time Complexity: O(n^2)
    //Space Complexity: ???
    //This is a confusing solution!
    string convert(string s, int numRows) 
    {
        if(s.empty() || numRows<=1 || numRows>s.length())   return s;
        
        int len=s.length();
        string res(len,'\0');
        
        //Fixed interval
        int count=0,interval=2*numRows-2;
        
        std::cout << "interval = " << interval << std::endl;

        for(int i=0;i<numRows;i++)
        {
            //Why step = interval-2*i ???
            std::cout << "i = " << i << std::endl;
            int step=interval-2*i;
            // std::cout << "step = " << step << std::endl;

            //Traversing by lever order (Interval)
            //j=j+interval 
            for(int j=i;j<s.length();j+=interval)
            {
                // std::cout << "j = " << j << std::endl;
                res[count]=s[j];
                count++;

                //Traversing steps
                if(step>0 && step<interval && j+step<s.length())
                {
                    // std::cout << "count = " << count << std::endl;
                    //j+step is the index of step
                    std::cout << "j+step = " << j+step << std::endl;
                    //Add steps to the format string
                    res[count]=s[j+step];
                    count++;
                }
            }
        }
        return res;
    }
};


class Solution_3 {
public:
    
    //Approach 3
    //Time Complexity: O(n)
    //Space Complexity: ???
    string convert(string s, int numRows) 
    {
        if(s.empty() || numRows<=1 || numRows>s.length())   return s;
        
        int len=s.length();
        vector<string> sb(numRows,"");
        string res="";
        std::cout << "len = " << len << std::endl;
        
        int i=0;
        while(i<len)
        {
            // std::cout << "i = " << i << std::endl;
            
            //Traversing normal rows
            for(int index=0;index<numRows && i<len;index++)
            {
                std::cout << "index = " << index << std::endl;
                // std::cout << "i = " << i << std::endl;
                sb[index].push_back(s[i++]);
            }
                
            //Traversing oblique rows
            for(int index=numRows-2;index>=1 && i<len;index--)
            {
                // std::cout << "index = " << index << std::endl;
                sb[index].push_back(s[i++]);
            }
        }
        
        for(int index=0;index<sb.size();index++)
            res+=sb[index];
        
        return res;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);//Problem here!
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

//Test Stub
//Input:
int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = Solution_1().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    getchar();
    return 0;
}