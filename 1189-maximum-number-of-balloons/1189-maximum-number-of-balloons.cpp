class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count_b=0;
        int count_o=0;
        int count_a=0;
        int count_l=0;
        int count_n=0;
        for(int i=0;i<text.size();i++){
             if(text[i]=='a'){
                count_a++;
             }
             if(text[i]=='b'){
                count_b++;
             }
             if(text[i]=='l'){
                count_l++;
             }
             if(text[i]=='o'){
                count_o++;
             }
             if(text[i]=='n'){
                count_n++;
             }
        }
        count_l/=2;
        count_o/=2;

        return min({
            count_a,
            count_b,
            count_l,
            count_o,
            count_n
        });
 
    }
};