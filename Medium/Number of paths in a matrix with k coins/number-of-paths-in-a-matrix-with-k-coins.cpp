//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long  solve(int n, int k, vector<vector<int>> &arr,int r,int c,long long &ans,vector<vector<vector<int>>>&dp)
    {
        if(k<0) return 0;
        
        if(r>=n || c>=n)
        return 0;
        
        if(dp[r][c][k]!=-1) return dp[r][c][k];
        
        if(k==arr[r][c])
        {
            if(r==n-1 && c==n-1) 
            return 1;
            else
            return 0;
        }
        
        
         long long a1=solve(n,k-arr[r][c],arr,r+1,c,ans,dp);
         long long a2=solve(n,k-arr[r][c],arr,r,c+1,ans,dp);
         
         return dp[r][c][k]=a1+a2;
          
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        // Code Here
       long long ans=0,temp=0;
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
      ans =solve(n,k,arr,0,0,ans,dp);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends