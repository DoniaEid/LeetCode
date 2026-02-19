#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int count = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                count++; 
            } else {
                groups.push_back(count); 
                count = 1;
            }
        }
        groups.push_back(count); 

        int total = 0;
        for (int i = 1; i < groups.size(); i++) {
            total += min(groups[i], groups[i-1]);
        }
        //kkk
        return total;
    }
};