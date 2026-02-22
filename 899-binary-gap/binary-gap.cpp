class Solution {
public:
    int binaryGap(int n) {
       string s= binary(n);
       int m=0;
       for(int i=0;i<s.size();i++){
          if(s[i]=='1'){
            for(int j=i+1;j<s.size();j++){
              if(s[j]=='1'){
                    m=max(m,j-i);
                    break;
               }
                  
            }
          }
       }
       return m;
    }
    string binary(int n){
        string t="";
        while(n!=0){
            t+=(n%2)+'0';
            n/=2;
        }
        return t;
    }

};
