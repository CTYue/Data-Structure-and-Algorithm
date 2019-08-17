/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-02-21 00:43:31
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-16 21:02:08
 * @Description: To be added.
 * @AC: Yes: faster than 98%, less than 92%
 */
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0) return false;
        long sum=0;int temp=x;
        
        //取位操作：先余后除
        while(x!=0)
        {
            sum=sum*10+x%10;
            x/=10;
        }
        
        return sum==temp;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}