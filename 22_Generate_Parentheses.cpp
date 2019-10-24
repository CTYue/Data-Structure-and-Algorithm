/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-05-24 15:53:28
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-24 16:15:52
 * @Description: 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * [
 *  "((()))",
 *  "(()())",
 *  "(())()",
 *  "()(())",
 *  "()()()"
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    //BackTracking
    //Time Complexity: 
    //Space Complexity: 
    vector<string> res;
    //open: dict[0], close: dict[1]
    vector<string> dict={"(",")"};
    vector<string> generateParenthesis(int n) 
    {
       if(n<1) return res;
        string local;
        backtracking(n, 0, 0, local);
        return res;
    }
    
    void backtracking(int n, int open, int close, string local)
    {
        if(local.length()==(2*n))    
        {
            res.push_back(local);
            return;
        }
        
        // cout<<"open = "<<open<<endl;
        // cout<<"close = "<<close<<endl;
        //open==close==n/2
        if(open<n)  backtracking(n, open+1, close, local+dict[0]);
        if(close<open) backtracking(n, open, close+1, local+dict[1]);
    }
};


int main(int argc, char* argv[])
{
    if(argc<1)  return 1;

    std::cout << "Input your number: " << std::endl;
    int num;
    std::cin >> num;

    vector<string> res;
    Solution s;
    res=s.generateParenthesis(num);

    for(string item:res)
        std::cout << item << " ";

    std::cout << std::endl;

    return 0;
}