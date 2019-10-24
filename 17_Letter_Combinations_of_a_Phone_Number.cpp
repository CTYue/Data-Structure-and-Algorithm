/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-05-21 20:11:02
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2019-10-23 23:58:02
 * @Description: 
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    //Backtracking
    //Time Complexity: O(3^N*4^M)
    //Space Complexity: O(3^N*4^M)
    unordered_map<int, string> map={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty())  return {};       
        string local;
        backtracking(digits, local, 0);

        return res;
    }
    
    void backtracking(string& digits, string& local, int index)
    {
        if(index==digits.size()) 
        {
            cout<<"local = "<<local<<endl;
            res.push_back(local);
        }
        else
        {
            for(int i=0;i<map[digits[index]-'0'].size();i++)
            {
                cout<<"local = " <<local<<endl;
                local.push_back(map[digits[index]-'0'][i]);
                backtracking(digits, local, index+1);
                
                cout<<"local.back() = "<<local.back()<<endl;
                local.pop_back();//清空本级的local
            }
        }
            
    }
};


//Test Stub
int main(int argc, char* argv[])
{
    if(argc<1)
        return 1;
    Solution approach_1;
    string digits;
    std::cout << "Input your digits: " << std::endl;
    std::cin >> digits;
    std::cout << std::endl;

    vector<string> res;
    res = approach_1.letterCombinations(digits);

    for(auto item:res)
        std::cout << item << " ";

    std::cout << std::endl;

    return 0;
}