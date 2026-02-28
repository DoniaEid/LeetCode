
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        string s = "";

        for (int i = 1; i <= n; i++) {
            int x = i;
            string temp = "";
            while (x > 0) {
                temp += (x % 2) + '0';
                x /= 2;
            }
            reverse(temp.begin(), temp.end());
            s += temp;
        }

        long long result = 0;
        for (char c : s) {
            result = (result * 2 + (c - '0')) % MOD;
        }

        return result;
    }
};
