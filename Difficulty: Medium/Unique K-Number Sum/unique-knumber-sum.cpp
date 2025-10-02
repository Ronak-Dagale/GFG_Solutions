class Solution {
  public:
  void solve( int n,int k,vector<vector<int>>&ans,vector<int>tmp,int sum,int curr){
      if(curr>9) {
          if(sum==n && tmp.size()==k) ans.push_back(tmp);
          return;
      }
      if(tmp.size()>k) return;
      
     
          solve(n,k,ans,tmp,sum,curr+1);
          tmp.push_back(curr);
          solve(n,k,ans,tmp,sum+curr,curr+1);
      
      return;
  }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>>ans;
        vector<int>tmp;
        solve(n,k,ans,tmp,0,1);
        return ans;
    }
};