class Solution {
public:
    int maxNumberOfBalloons(string text) {
       map<char,int>freq;
        for(int i=0;i<text.size();i++){
            freq[text[i]]++;
        }
        freq['l']/=2;
        freq['o']/=2;

        return min({
            freq['a'],
            freq['b'],
            freq['l'],
            freq['o'],
            freq['n']
        });
 
    }
};