class Solution {
  public:
  int solve(int x,int y,vector<vector<int>>& mat,vector<vector<int>>&dp)
  {
      int m=mat.size(),n=mat[0].size();
      
      if(x>=m || y>=n) return 0;
      
      if(dp[x][y]!=-1) return dp[x][y];
      int dx[]={-1,0,1},dy[]={1,1,1};
      int res=0;
      for(int k=0;k<3;k++)
      {
          int nx=x+dx[k],ny=y+dy[k];
          
          if(nx>=0 && ny>=0 && nx<m && ny<n)
          {
              res=max(res,solve(nx,ny,mat,dp)+mat[nx][ny]);
          }
      }
      return dp[x][y]=res;
  }
    int maxGold(vector<vector<int>>& mat) {
        // code here
      int ans=INT_MIN;
      int m=mat.size(),n=mat[0].size();    
      vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
      for(int i=0;i<m;i++)
      {
          ans=max(ans,solve(i,0,mat,dp)+mat[i][0]);
      }
      return ans;
    }
};