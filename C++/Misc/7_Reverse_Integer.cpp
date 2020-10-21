#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
        //取位操作：先余后除！
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        int ret = Solution().reverse(x);
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}