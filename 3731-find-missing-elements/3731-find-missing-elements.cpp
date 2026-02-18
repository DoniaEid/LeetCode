
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> missing;
        int x = nums[0];   
        for(int i = 0; i < nums.size(); i++) {
            
            if (find(nums.begin(), nums.end(), x) == nums.end()) {
                missing.push_back(x); 
                 i--;
            }
            x++; 
        }
        return missing; 
    }
};