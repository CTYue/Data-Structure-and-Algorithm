/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-16 21:02:33
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-08-16 22:02:46
 * @Description: To be added.
 * @AC: Solution_1: Yes, faster than 100%, less than 100%
 *      Solution_2: Yes, faster than 10%, less than 53%
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
class Solution_1 {
public:
    //Time Complexity:  
    //Space Complexity: 
    int SquareSum(int n)
    {
        int sum=0;
        // std::cout << "==========" << std::endl;
        // std::cout << "n = " << n << std::endl;
        while(n!=0)
        {
            sum+=(n%10)*(n%10);
            n/=10;
            // std::cout << "sum = " << sum << std::endl;
        }
        // std::cout << "==========" << std::endl;
        
        return sum;
    }
    
    bool isHappy(int n) 
    {
        int fast, slow;
        fast=slow=n;
        
        do{
            std::cout << "===========" << std::endl;
            slow=SquareSum(slow);
            std::cout << "slow = " << slow << std::endl;
            fast=SquareSum(fast);
            std::cout << "fast = " << fast << std::endl;
            fast=SquareSum(fast);
            std::cout << "fast = " << fast << std::endl;
            std::cout << "===========" << std::endl;

            if(fast==1) return 1;
        }while(slow!=fast);
        
        return 0;
    }
};


class Solution_2 {
public:
    bool isHappy(int n) 
    {
        unordered_set<int> set;
        
        while(set.find(n)==set.end())
        {
            set.insert(n);
            int sum=0;
            while(n>0)
            {
                sum+=(n%10)*(n%10);
                n/=10;
            }
            // std::cout << "sum = " << sum << std::endl;
            n=sum;
        }
        
        return !(set.find(1)==set.end());
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
        int n = stringToInteger(line);
        
        bool ret = Solution_2().isHappy(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}