#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    
    //Approach 1: Recursion
    //Time complexity:
    //Space complexity:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        if(n<1) return res;
        if(n==1)
        {
            res.push_back("()");
            return res;
        }
        
        //Why the Length is 2*n?
        string str(2*n,'\0');
        generate(0,n,0,0,res,str);
        
        return res;
    }
    
 
    void generate(int pos, int n, int open, int close, vector<string>& res,string& str)
    {      
        if(close!=n)
        {
            if(open>close)
            {
                str[pos]=')';
                generate(pos+1,n,open,close+1,res,str);//
            }
            
            if(open<n)
            {
                str[pos]='(';
                generate(pos+1,n,open+1,close,res,str);//
            }
        }
        
        else if(close==n)
        {
            res.push_back(str);
        }
        
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