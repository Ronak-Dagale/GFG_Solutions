class Solution {
  public:
  bool solve(vector<vector<int>>&ans,int n,int &cnt,int x,int y){
      if(cnt==(pow(n,2)-1)){
          ans[x][y]=cnt;
          return 1;
      }
      
      int dx[]={2,2,-2,-2,1,1,-1,-1};
      int dy[]={1,-1,1,-1,2,-2,2,-2};
      
      for(int i=0;i<8;i++){
          int nx=x+dx[i];
          int ny=y+dy[i];
          
          if(nx>=0 && ny>=0 && nx<n && ny<n && ans[nx][ny]==-1){
              ans[x][y]=cnt;
              cnt++;
              bool res=solve(ans,n,cnt,nx,ny);
              if(res) return 1;
              else
              {
                  cnt--;
                  ans[x][y]=-1;
              }
          }
      }
      return 0;
  }
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>>ans(n,vector<int>(n,-1));
        int cnt=0;
        vector<vector<int>>tmp;
        if(solve(ans,n,cnt,0,0))
        return ans;
        else 
        return tmp;
    }
};