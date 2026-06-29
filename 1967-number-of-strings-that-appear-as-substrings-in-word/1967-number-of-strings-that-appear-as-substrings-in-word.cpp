class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
       int count = 0;

        for (int i = 0; i < patterns.size(); i++) {
            int num = patterns[i].size();
            string s = patterns[i];

            for (int j = 0; j + num <= word.size(); j++) {
                if (word.substr(j, num) == s) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};