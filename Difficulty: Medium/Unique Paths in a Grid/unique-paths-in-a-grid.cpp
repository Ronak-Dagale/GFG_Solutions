class Solution {
  public:
  int solve(vector<vector<int>> &grid,int x,int y,int n,int m,vector<vector<int>>&dp)
  {
      if(x==n-1 && y==m-1) return 1;
      if(x>=n || y>=m || x<0 || y<0) return 0;
      
      if(grid[x][y]==1) return 0;
      if(dp[x][y]!=-1) return dp[x][y];
      
      int res=0;
      res=solve(grid,x+1,y,n,m,dp);
      res+=solve(grid,x,y+1,n,m,dp);
      
      return dp[x][y]=res;
  }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return solve(grid,0,0,n,m,dp);
    }
};