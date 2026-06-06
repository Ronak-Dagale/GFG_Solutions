class Solution {
  public:
  bool issafe(int nx,int ny,int n,int m){
      if(nx>=0 && ny>=0 && nx<n && ny<m) return 1;
      return 0;
  }
    int numOfWays(int n, int m) {
        // code here
        int ans=0;
        int mod=1e9+7;
        int dx[]={1,-1,1,-1,2,2,-2,-2};
        int dy[]={2,2,-2,-2,1,-1,1,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int res=(n*m)-1;
               for(int k=0;k<8;k++){
                   if(issafe(i+dx[k],j+dy[k],n,m)) res--;
               }
            //   cout<<i<<" "<<j<<" "<<res<<endl;
               ans=(ans+res);
            }
        }
        return ans;
    }
};