class Solution {
  public:
    int maxProduct(int n) {
        // code here
       if(n==2) return 1;
       if(n==3) return 2;
       
       int ans=1;
       while(n){
           if(n>=3){
               ans=ans*3;
               n=n-3;
           }
           else if(n==2){
               ans=ans*2;
               n=n-2;
           }
           else if(n==1){
               ans/=3;
               ans*=4;
               n--;
           }
       }
       return ans;
    }
};