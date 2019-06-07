/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-06-06 22:19:24
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-06-07 15:51:42
 * @Description: 
 */

#include <iostream>
#include <vector>
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
public:
    //Brute Force
    //Time Complexity: O(n^2)
    //Space Complexity: O(1)
    int maxProfit(vector<int>& prices) 
    {
        int maxprofit=0;
        int profit=0;
        int len=prices.size();
        for(int i=0;i<len-1;++i)
        {
            for(int j=i+1;j<len;++j)
            {
                profit=prices[j]-prices[i];
                if(profit>maxprofit)
                    maxprofit=profit;
            }
        }
        return maxprofit;
    }
};



void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

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