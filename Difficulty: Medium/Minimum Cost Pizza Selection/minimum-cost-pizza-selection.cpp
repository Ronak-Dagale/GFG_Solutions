class Solution {
  public:
  int solve(int x, int s, int m, int l, int cs, int cm, int cl){
      if(x<=0) return 0;
      
      int res=0;
      res=cs+solve(x-s,s,m,l,cs,cm,cl);
      res=min(res,cm+solve(x-m,s,m,l,cs,cm,cl));
      res=min(res,cl+solve(x-l,s,m,l,cs,cm,cl));
      
      return res;
  }
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        // return solve(x,s,m,l,cs,cm,cl);
        vector<int>dp(x+100,0);
        for(int i=x-1;i>=0;i--){
            dp[i]=min({cs+dp[i+s],cm+dp[i+m],cl+dp[i+l]});
            
        }
        return dp[0];
    }
};