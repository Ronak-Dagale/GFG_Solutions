class Solution {
  public:
  int mod=1e9+7;
    int distinctSubseq(string &str) {
        // code here
      int n=str.size();
      vector<int>dp(n+1);
      unordered_map<char,int>mp;
      dp[0]=1;
      for(int i=1;i<=n;i++){
          dp[i]=(2*dp[i-1])%mod;
          if(mp[str[i-1]]!=0){
              int id=mp[str[i-1]];
              dp[i]=(dp[i]-dp[id-1]+mod)%mod;
          }
          mp[str[i-1]]=i;
      }
      return dp[n];
    }
};