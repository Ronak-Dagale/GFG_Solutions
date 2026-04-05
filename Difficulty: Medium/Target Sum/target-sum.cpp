class Solution {
  public:
  int solve(vector<int>& arr, int target,int tmp,int id,int sum,vector<vector<int>>&dp){
      if(id>=arr.size()) {
          if(sum==target) return 1;
          return 0;
      }
      
      if(dp[id][sum+tmp]!=-1) return dp[id][sum+tmp];
      
      int res=0;
      
      res=solve(arr,target,tmp,id+1,sum+arr[id],dp);
      res+=solve(arr,target,tmp,id+1,sum-arr[id],dp);
      return dp[id][sum+tmp]=res;
      
  }
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int ans=0,tmp=0,n=arr.size();
        for(int i=0;i<arr.size();i++) tmp+=arr[i];
        vector<vector<int>>dp(n,vector<int>(2*tmp+1,-1));
        
        ans=solve(arr,target,tmp,0,0,dp);
        return ans;
    }
};