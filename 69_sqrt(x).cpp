/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-16 22:03:01
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-16 22:03:53
 * @Description: To be added.
 */
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) 
    {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }

    return 0;
}