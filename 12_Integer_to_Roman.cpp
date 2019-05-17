#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) 
    {
        int pop=0;
        string res="";
        if(num<1 || num>3999) return res;
        
        while(num!=0)
        {
            if(num>=1000)
            {   //Add M
                res.append(num/1000,'M');
                num%=1000;//
            }
            
            else if(num>=500)
            {
                if(num<900)
                {
                    res.append(num/500,'D');
                    num%=500;
                }
                
                else
                {
                    //Sub-digit
                    res.append(1,'C');
                    res.append(1,'M');
                    num%=100;//为什么%100
                }
            }
            
            else if(num>=100)
            {
                if(num<400)
                {
                    res.append(num/100,'C');
                    num%=100;
                }
                
                else
                {
                    //Sub_digit
                    res.append(1,'C');
                    res.append(1,'D');
                    num%=100;
                }
            }
            
            else if(num>=50)
            {
                if(num<90)
                {
                    res.append(num/50,'L');
                    num%=50;
                }
                
                else
                {
                    //Sub-digit
                    res.append(1,'X');
                    res.append(1,'C');                    
                    num%=10;//
                }
            }
            
            else if(num>=10)
            {
                if(num<40)
                {
                    res.append(num/10,'X');
                    num%=10;
                }
                
                else
                {
                    //Sub-digit
                    res.append(1,'X');
                    res.append(1,'L');                    
                    num%=10;
                }
            }
            
            else if(num>=5)
            {
                if(num<9)
                {
                    res.append(num/5,'V');
                    num%=5;
                }
                
                else
                {
                    //Sub-digit
                    res.append(1,'I');
                    res.append(1,'X');
                    num=0;//Clear
                }
            }
            
            else if(num>=1)
            {
                if(num<4)
                {
                    res.append(num,'I');
                    num=0;
                }
                
                else
                {
                    //Sub-digit
                    res.append(1,'I');
                    res.append(1,'V');
                    num=0;
                }
            }            
        }
        
        return res;
    }
    

};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}