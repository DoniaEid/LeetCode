#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;

        unordered_set<string> seen;
        int total_required = 1 << k; 

        for (int i = 0; i <= (int)s.length() - k; i++) {
            string sub = s.substr(i, k);
            seen.insert(sub);

            if (seen.size() == total_required) return true;
        }

        return seen.size() == total_required;
    }
};