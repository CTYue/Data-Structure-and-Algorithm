/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-15 01:42:59
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-15 01:43:39
 * @Description: To be added.
 */

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        //不能用to_string方法，因为这种方法将原数字按每4位转换成unicode???总之，不能用to_string
       uint32_t res;
       for(int i=0;i<32;i++)
       {
           res<<=1;
           res|=(n&1);//这句没理解；
           n>>=1;
       }
        
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().reverseBits(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}