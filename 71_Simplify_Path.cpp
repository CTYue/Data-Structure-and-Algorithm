/*
 * Filename: /Users/yuzidong/Code/Data-Structure-and-Algorithm/71_Simplify_Path.cpp
 * Path: /Users/yuzidong/Code/Data-Structure-and-Algorithm
 * Created Date: Friday, May 31st 2019, 11:25:30 am
 * Author: yuzidong
 * 
 * Copyright (c) 2019 Your Company
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    std::vector<string> split(const std::string &source, const char* pattern)
    {
        std::vector<string> res;
        stringstream input(source);
        string temp;
        while(getline(input, temp, *pattern))
        {       
            res.push_back(temp);
        }
        return res;
    }
    
    string simplifyPath(string path) 
    {
        string res="";
        if(path.empty())
            return "";
                
        //stack
        std::stack<string> stack;
        //C++没有提供elegant的拆分函数
        vector<string> pos = split(path,"/");
        for(string s:pos)
        {
            //只要遇到.. 即返回上级，则pop
            //if s=".."
            if(!s.compare(".."))
            {    
                if(!stack.empty())
                {
                    stack.pop();
                    //这里需要pop？
                    //stack还没有push过呢！
                }
            }
            //.和""没用，所以仅仅push不是.和""的内容
            //if s!="." && s!=""
            else if(s.compare(".") && s.compare(""))
            {
                std::cout << "if s!=. && s= " << std::endl;
                std::cout << " s = " << s << std::endl;
                stack.push(s);
            }
        }
        while(!stack.empty())
        {
            //所有的path均以/打头
            res = "/" + stack.top() + res;
            stack.pop();
        }        
        
        if(res.length()==0)
            return "/";
        
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
        string path = stringToString(line);
        
        string ret = Solution().simplifyPath(path);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}