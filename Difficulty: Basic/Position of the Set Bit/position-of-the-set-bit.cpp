class Solution {
  public:
    int findPosition(int n) {
        // code here
        int cnt=0,ans=-1,pos=0;
        while(n!=0){
            pos++;
            if(n&1) {
                cnt++;
                ans=pos;
            }
            n=n/2;
            if(cnt>1) return -1;
        } 
        return ans;
    }
};