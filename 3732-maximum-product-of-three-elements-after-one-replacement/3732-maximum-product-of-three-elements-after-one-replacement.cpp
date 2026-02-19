class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        vector<long long> p;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] < 0){
                p.push_back((long long)nums[i] * -1); 
            }
            else{
                p.push_back((long long)nums[i]);
            }
        }
        
        sort(p.rbegin(), p.rend());
        
        long long num1 = p[0];
        long long num2 = p[1];
        
if (find(nums.begin(), nums.end(), (int)num1 * -1) != nums.end()) {
    num1 *= -1; 
}

if (find(nums.begin(), nums.end(), (int)num2 * -1) != nums.end()) {
    num2 *= -1;
}
        
        long long t = num1 * num2;
        
        if(t < 0){
            return t * -100000;
        }
        else{
            return t * 100000;
        }
    }
};
