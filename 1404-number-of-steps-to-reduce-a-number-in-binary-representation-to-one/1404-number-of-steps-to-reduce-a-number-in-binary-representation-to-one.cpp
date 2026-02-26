class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        int n = s.length();

        for (int i = n - 1; i > 0; i--) {
            int current = (s[i] - '0') + carry;

            if (current == 1) {
                steps += 2;
                carry = 1; 
            } else {
                steps += 1;
                if (current == 2) carry = 1;
                else carry = 0;
            }
        }

        return steps + carry;
    }
};
