class Solution {
public:
    bool hasAlternatingBits(int n) {
        stack <int>s;
        while(n!=0){
            s.push(n%2);
            n/=2;
        }
        vector<int>v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop(); 
        }
        bool flag=true;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]==v[i+1]){
                flag=false;
                break;
            }
        }

      if(flag){
        return true;
      }
      else{
        return false;
      }



    }
};