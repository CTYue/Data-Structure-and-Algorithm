/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-16 22:03:01
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2020-01-24 18:32:15
 * @Description: To be added.
 */
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    //Binary Search
    //Time Complexity: O(logN)
    //Space Complexity: O(1)
    int mySqrt(int x) 
    {
        if(x<=1)    return x;
        
        int left=2, right=x/2;//x/2是maximum possible upper bound.
        
        while(left<=right)
        {
            //为什么要单独设置一个pivot???
            //如果不设置中间值，只通过下界和上界夹逼出开放值的话，就失去了二分法的意义。
            //通过不断缩小上下边界，使得待选数字的区间越来越小。
            int pivot=left+(right-left)/2;
            
            //注意，两个中间值的积一定要用long型
            //注意，pivot*pivot不要加括号，否则依然会有无法用int表示的错误
            long product=(long)pivot*pivot;

            if(product<x)   left=pivot+1;
            
            else if(product>x)  right=pivot-1;
           
            else return pivot;
        }
        
        return right;
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