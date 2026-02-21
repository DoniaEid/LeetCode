class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int c=binary(i);
            if(prime(c)){
                count++;
            }
        }
        return count;
    }
    bool prime(int num){
        if(num<=1){
            return false;
        }
        bool found=true;
        for(int i=2;i*i<=num;i++){
          if(num%i==0){
            found=false;
            break;
          }
        }
        return found;
    }
    int binary(int num){
        string s="";
        int c=0;
        while(num!=0){
            s+=(num%2)+'0';
            num/=2;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                   c++;
            }
        }
        return c;
    }


};