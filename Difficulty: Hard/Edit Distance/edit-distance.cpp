//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(string str1, string str2,int i,int j,vector<vector<int>>&dp)
    {
        if(i==str1.size() && j!=str2.size())
        return str2.size()-j;
        else if(i!=str1.size() && j==str2.size())
        return str1.size()-i;
        else if(i==str1.size() && j==str2.size())
        return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        if(str1[i]==str2[j])
        return solve(str1,str2,i+1,j+1,dp);
        else
        {
            ans=min(ans,solve(str1,str2,i,j+1,dp)+1);
            ans=min(ans,solve(str1,str2,i+1,j+1,dp)+1);
            ans=min(ans,solve(str1,str2,i+1,j,dp)+1);
        }
        return dp[i][j]=ans;
    }
    int editDistance(string str1, string str2) {
        // Code here
        int n=str1.size(),m=str2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve(str1,str2,0,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends