class Solution {
public:
    int reverse(int n) {
        long long num = n;  
        bool isNegative = (num < 0);
        if (isNegative) num = -num;  

        long long rev = 0;
        while (num > 0) {
            int d = num % 10;
            rev = rev * 10 + d;
            num /= 10;
        }

        if (isNegative) rev = -rev;

        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }

        return (int)rev;
    }
};