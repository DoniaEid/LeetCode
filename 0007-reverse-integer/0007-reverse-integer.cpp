class Solution {
public:
    int reverse(int x) {
        long long res = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            res = res * 10 + digit;

            // check overflow
            if (res > INT_MAX || res < INT_MIN)
                return 0;
        }

        return (int)res;
    }
};