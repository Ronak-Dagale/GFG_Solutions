class Solution {
  public:
    int countStrings(int n) {
        // code here
        int a=2,b=3,ans=0;
        if(n==1) return a;
        if(n==2) return b;
        
        n=n-2;
        while(n--){
            ans=a+b;
            a=b;
            b=ans;
        }
        return ans;
    }
};