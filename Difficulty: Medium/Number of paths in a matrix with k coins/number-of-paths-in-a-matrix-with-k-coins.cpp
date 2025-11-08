class Solution {
  public:
  int dx[2]={1,0};
  int dy[2]={0,1};
  void solve(vector<vector<int>>& mat, int k,int x,int y,int sum,int &ans){
      int n=mat.size(),m=mat[0].size();
      sum+=mat[x][y];
      if(x==n-1  && y==m-1 && sum==k)
      {
          ans++;
          return;
      }
      if(sum>k) return;
      
      for(int i=0;i<2;i++){
          int nx=x+dx[i];
          int ny=y+dy[i];
          
          if(nx>=0 && ny>=0 && nx<n && ny<m){
              solve(mat,k,nx,ny,sum,ans);
          }
      }
  }
  int solve1(vector<vector<int>>& mat, int k,int x,int y,int sum, vector<vector<vector<int>>>&dp){
            int n=mat.size(),m=mat[0].size();
            sum+=mat[x][y];
            if(x==n-1  && y==m-1 && sum==k)
            return 1;
            
            if(sum>k) return 0;
            if(dp[x][y][sum]!=-1) return dp[x][y][sum];
            
            int res=0;
            for(int i=0;i<2;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    res+=solve1(mat,k,nx,ny,sum,dp);
                }
            }
            dp[x][y][sum]=res;
            return res;
  }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int ans=0;
        int n=mat.size(),m=mat[0].size();
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        
        ans=solve1(mat,k,0,0,0,dp);
        // solve(mat,k,0,0,0,ans);
        return ans;
    }
};