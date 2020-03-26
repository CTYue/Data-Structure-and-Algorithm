/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-25 02:31:34
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-25 02:32:25
 * @Description: To be added.
 */
#include <#iostream>
#include <string>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);//No definition

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int lo=1, hi=n;
        
        //注意总结二分法
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            
            if(isBadVersion(mid)==true) hi=mid-1;
            else lo=mid+1;
        }
        
        return lo;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int bad = stringToInteger(line);
        
        int ret = Solution().firstBadVersion(n, bad);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}