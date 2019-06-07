#include <iostream>
using namespace std;

class Solution_1 {
public:
    
    //Iteration Approach
    //Time Complexity: O(1)
    //Space Complexity: O(1)
    int climbStairs(int n) 
    {
        if(n<=1) return n;

        int f1=1,f2=2;
        if(n==2)
            return f2;
        
        for(int i=3;i<=n;i++)
        {
            int f3=f1+f2;
            //
            f1=f2;
            f2=f3;
        }
        
        return f2;
    }
};





int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution_1().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}