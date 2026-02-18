#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());

        vector<int> missing;
        int current = nums[0];
        int last = nums[nums.size() - 1]; 

        set<int> s(nums.begin(), nums.end());

        for (int x = current; x <= last; x++) {
            if (s.find(x) == s.end()) {
                missing.push_back(x); 
            }
        }

        return missing; 
    }
};