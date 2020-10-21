/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-02-20 09:02:44
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-02-20 09:18:58
 * @Description: To be added.
 */
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int bits=0;
        unsigned int mask=1;
        // int mask=1;//
        for(int i=0;i<32;i++)
        {
            if((n&mask)!=0)   {bits++;}
            mask <<= 1;
            //为什么要将mask定义成unsigned型？
            //The left shift and right shift operators should not be used for negative numbers. The result of is undefined behaviour if any of the operands is a negative number. For example results of both -1 << 1 and 1 << -1 is undefined.
            // If the number is shifted more than the size of integer, the behaviour is undefined. For example, 1 << 33 is undefined if integers are stored using 32 bits. See this for more details.
            // The left-shift by 1 and right-shift by 1 are equivalent to the product of first term and 2 to the power given element(1<<3 = 1*pow(2,3)) and division of first term and second term raised to power 2 (1>>3 = 1/pow(2,3)) respectively.
            // As mentioned in point 1, it works only if numbers are positive.
        }
        
        return bits;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().hammingWeight(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}