class Solution {
public:
    int binary(int num) {
        int count = 0;
        int temp = num; 
        while (temp != 0) {
            if (temp % 2 == 1) count++;
            temp /= 2;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> helper;

        for (int i = 0; i < arr.size(); i++) {
            int bits = binary(arr[i]);
            helper.push_back({bits, arr[i]});
        }

        sort(helper.begin(), helper.end());

        vector<int> result;
        for (int i = 0; i < helper.size(); i++) {
            result.push_back(helper[i].second); 
        }

        return result;
    }
};