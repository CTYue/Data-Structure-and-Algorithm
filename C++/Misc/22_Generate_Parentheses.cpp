/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-05-24 15:53:28
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-12-13 23:02:51
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


class Solution_Brute_Force {
public:
    //Brute force solution (Recursion)
    //小括号：Parentheses
    //Time Complexity: O(2^(2*n)*n)
    //Space Complexity: O(2^(2*n)*n)
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        if(n<1) return res;
        
        string current(2*n,' ');
        genAll(current, 0, res);
        
        return res;
    }
    
    void genAll(string& current, int pos, vector<string>& res)
    {
        if(pos==current.length())
        {
            //注意：一定要验证后才能加进res
            //从数次recursion中选出满足条件的push进result
            if(valid(current))  res.push_back(current);
        }
        
        else
        {
            current[pos]='(';
            genAll(current, pos+1, res);
            current[pos]=')';
            genAll(current, pos+1, res);
        }
    }
    
    bool valid(string current)
    {
        int balance=0;
        for(char c: current)
        {
            if(c=='(') balance++;//Count open parentheses
            else balance--;//Count close parentheses
            if(balance<0)   return false;
        }
        
        return balance==0;
    }
};

class Solution_Back_Tracking{
public:
    //Backtracking
    //Time Complexity: O(???) 太复杂，没理解
    //Space Complexity: O(???) 没理解
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        if(n<1) return res;
        
        string cur;
        backtracking(cur, 0, 0, n, res);
        
        return res;
    }
    
    //backtracking的核心思想是，尽早丢弃不合适的答案
    //The "solution" should follow certain constraint satisfaction.
    //这里的constraint就是if(open<max)和if(close<open)
    //通过限定close<open, 使得左括号和右括号始终成对出现，反观暴力solution，
    //生成的candidates中，左右括号并不一定成对出现，导致大量的time和space被浪费。
    void backtracking(string cur, int open, int close, int max, vector<string>& res)
    {
        if(cur.length()==2*max)
        {
            res.push_back(cur);
            return;
        }
        //注意左值右值的问题！不要用string& cur传参数，否则cur会被不停的追加
        //这里只能传右值???
        if(open<max)    backtracking(cur+"(", open+1, close, max, res);
        //close<open 是为了保证右括号的数量始终与左括号相等。
        if(close<open)   backtracking(cur+")", open, close+1, max, res);
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