#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int length = 0; 
        long long pow2 = 1;
        int nextPower = 1; 

        for (int i = 1; i <= n; i++) {
            if (i == nextPower) {
                length++;
                pow2 = (pow2 * 2) % MOD;
                nextPower *= 2;
            }

            result = (result * pow2 + i) % MOD;
        }

        return result;
    }
};
