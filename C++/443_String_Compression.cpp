/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2020-03-12 16:30:33
 * @LastEditors: Zidong Yu
 * @LastEditTime: 2020-03-12 16:33:58
 * @Description: To be added.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) 
    {
        if(chars.size()<=1) return chars.size();
        int size=chars.size();
        
        int start=0, write=0;//start: starting point of unique chars
                             //write: modification point where we put count and change the existing char
        
        for(int i=0;i<size;++i)
        {
            //Do modifications when reach a turning point
            //For the last element, revise it anyway
            if(i+1==size || chars[i+1]!=chars[i])
            {
                chars[write++]=chars[start];//
             
                //确保当前element出现的次数大于1
                if(i>start)
                {
                    for(char c: std::to_string(i-start+1))
                        chars[write++]=c;
                }
                
                start=i+1;
            }
        }
        
        return write;
    }
};

int main(int argc, char** argv)
{
    //You define the input here
    vector<char> input={};
    // Input:
    // ["a","a","b","b","c","c","c"]

    // Output:
    // Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

    // Explanation:
    // "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".

    Solution s;
    int res = s.compress(input);

    cout<<"res = "<<res<<endl;
    cout<<"[";
    for(char c: input) cout<<c<<", ";
    cout<<"]"<<endl;
    
    return 1;
}