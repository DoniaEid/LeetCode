#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long totalProductWithoutZero = 1;
        int zeroCount = 0;

        for (int x : nums) {
            if (x == 0) {
                zeroCount++;
            } else {
                totalProductWithoutZero *= x;
            }
        }

        vector<int> res(n, 0); 

        for (int i = 0; i < n; i++) {
            if (zeroCount == 0) {
                res[i] = (int)(totalProductWithoutZero / nums[i]);
            } 
            else if (zeroCount == 1) {
                if (nums[i] == 0) {
                    res[i] = (int)totalProductWithoutZero;
                }
                 else {
                    res[i] = 0;
                }
            }
        }

        return res;
    }
};