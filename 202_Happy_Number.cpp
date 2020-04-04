/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-08-16 21:02:33
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-04-03 19:16:41
 * @Description: To be added.
 * @AC: Solution_1: Yes, faster than 100%, less than 100%
 *      Solution_2: Yes, faster than 10%, less than 53%
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
class Solution_1 
{
public:
    int getNext(int n)
    {
         int sum=0;
       
        while(n!=0)
        {
            //先余后除
            int d=n%10;
            cout<<"d = "<<d<<endl;
            n=n/10;
            cout<<"n = "<<n<<endl;
            
            sum+=d*d;
        }
        
        return sum;
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