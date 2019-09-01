/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-28 16:03:22
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-31 23:58:26
 * @Description: To be added.
 * @AC: Yes
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
class Solution {
public:
    //Time Complexity:  
    //Space Complexity: 
    //滑动窗口
    //这种方法比较难理解!
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> res;
        int sum[30]={0};//为什么是30？
        
        int p_len=p.length(), s_len=s.length();
        for(int i=0;i<p_len;i++)    sum[p[i]-'a']++;
        
        int start=0, end=0, matched=0;
        //还没有理解！！！
        //???
        while(end<s_len)
        {
            //如果s[end]在sum中出现过
            if(sum[s[end]-'a']>=1)  matched++;
            
            //清空sum???
            sum[s[end]-'a']--;
            end++;//什么意思？
            
            if(matched==p_len)  res.push_back(start);
            
            //这是什么意思？
            if(end-start==p_len)
            {
                if(sum[s[start]-'a']>=0)    matched--;
                sum[s[start]-'a']++;
                start++;
            }
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        vector<int> ret = Solution().findAnagrams(s, p);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}