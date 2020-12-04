/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-07-02 17:27:47
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-07-03 00:05:41
 * @Description: To be added.
 * @AC: NO(C++) YES(Java)
 */

#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    //多位二进制加法：
    //本位:XOR
    //进位:先与再左移位
    //负数：补码+1
    //负数加减时有问题！
    //runtime error: left shift of negative value-4
    //C++对于
    int getSum(int a, int b) 
    {
        if(a==0 || b==0) return a==0?b:a;
        
        int sum = 0;
        int carry = 1;
        
        while(carry)
        {
            int temp = sum;
            sum = a^b;//本位
            // std::cout << "sum = " << sum << std::endl;
            // std::cout << "carry = " << carry << std::endl;
            // int c=carry<<1;
            // std::cout << "carry<<1 = " << c << std::endl;
            carry = (a & b) << 1;//进位
            sum+=carry;
        }          
        return sum;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        
        int ret = Solution().getSum(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}