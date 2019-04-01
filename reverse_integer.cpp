class Solution {
public:
    int reverse(int x) 
    {
        //取位操作：先余后除！
        //没怎么弄明白！
        //INT_MAX是什么？
        //
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
//这种解法没怎么明白！

