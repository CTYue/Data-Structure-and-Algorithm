/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-06 22:19:24
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-14 23:48:18
 * @Description: Is this really a DP problem?
 */

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution_1 {
public:
    //One Pass
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    int maxProfit(vector<int>& prices) 
    {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        
        return maxprofit;
    }
};

class Solution_2 {
    //A DP-Like Solution:
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    int maxProfit(vector<int>& prices) 
    {
        int len=prices.size();
        if(len<1)
            return 0;
        
        vector<int> profit(len,0);
        
        int min=prices[0];
        
        for(int i=1;i<len;i++)
        {
            if(prices[i]<min)
                min=prices[i];
          
            //Update profit[i], so that
            //profit[len-1] is the maximum one
            //Formula:
            //Profit(i)=max(Profit(i)-min,Profit(i-1);
            profit[i]=std::max(prices[i]-min,profit[i-1]);
        }
        
        return profit[len-1];
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

//需要复习Lambda表达式
void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution_1().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}