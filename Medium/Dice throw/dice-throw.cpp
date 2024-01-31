//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long solve(int n,int m,int x, vector<vector<long long>>&dp)
  {
      if(n==0 && x==0) return 1;
      if(n!=0 && x<=0) return 0;
      if(n==0 && x!=0) return 0;
      
      if(dp[n][x]!=-1)return dp[n][x];
      
      long long ways=0;
      for(int i=1;i<=m;i++)
      {
          ways=ways+solve(n-1,m,x-i,dp);
      }
      return dp[n][x]=ways;
  }
    long long noOfWays(int M , int N , int X) {
        // code here
        vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
        return solve(N,M,X,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends