class Solution {
  public:
  int solve(int x,int y,vector<vector<int>>& mat,vector<vector<int>>&dp){
      if(x==mat.size()) return 0;
      if(y<0 || y>=mat[0].size()) return -1e9;
      if(dp[x][y]!=-1) return dp[x][y];
      int res=mat[x][y];
      
      
      for(int j=0;j<mat[0].size();j++){
          if(j==y) continue;
          res=max(res,mat[x][y]+solve(x+1,j,mat,dp));
      }
      return dp[x][y]=res;
  }
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        vector<vector<int>>dp(1005,vector<int>(1005,-1));
        int ans=0;
        for(int j=0;j<mat.size();j++){
            ans=max(ans,solve(0,j,mat,dp));
            
        }
        return ans;
    }
};