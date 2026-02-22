class Solution {
public:
    int binaryGap(int n) {
        int max_dist = 0;
        int last_pos = -1;
        
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0) {
                if (last_pos != -1) {
                    max_dist = max(max_dist, i - last_pos);
                }
                last_pos = i;
            }
        }
        return max_dist;
    }
};