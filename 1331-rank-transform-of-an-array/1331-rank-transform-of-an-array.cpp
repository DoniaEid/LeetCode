class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a = arr;
        sort(a.begin(), a.end());

        map<int, int> index;
        int rank = 1;

        for (int i = 0; i < a.size(); i++) {
            if (index.find(a[i]) == index.end()) { 
                index[a[i]] = rank;
                rank++;
            }
        }

        vector<int> result;
        for (int i = 0; i < arr.size(); i++) {
            result.push_back(index[arr[i]]);
        }

        return result;
    }
};