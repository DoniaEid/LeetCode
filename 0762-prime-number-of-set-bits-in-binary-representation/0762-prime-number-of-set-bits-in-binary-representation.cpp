class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            string t=binary(i);
            int c=0;
            for(int i=0;i<t.size();i++){
                if(t[i]=='1'){
                    c++;
                }
            }
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
    string binary(int num){
        string s="";
        while(num!=0){
            s+=(num%2)+'0';
            num/=2;
        }
        return s;
    }


};