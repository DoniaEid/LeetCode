class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;

        long long num = x;
        bool neg = (num < 0);

        if (neg) num = -num;

        string s = "";

        while (num != 0) {
            s += (num % 10) + '0';
            num /= 10;
        }

        if (neg) s = "-" + s;

        long long val = stoll(s);

        if (val > INT_MAX || val < INT_MIN)
            return 0;

        return (int)val;
    }
};