//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
int solve(int x,int y, vector<vector<int>>&dp)
{
    if(x==0 && y==0) return 1;
    
    if(dp[x][y]!=-1) return dp[x][y];
    int ans=0;
    int dx[]={-1,0};
    int dy[]={0,-1};
    int mod=1e9+7;
    
    for(int i=0;i<2;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0)
        ans=(ans+solve(nx,ny,dp)%mod)%mod;
        
    }
    return dp[x][y]=ans;
}
    int ways(int x, int y)
    {
        //code here.
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        dp[0][0]=1;
        return solve(x,y,dp);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends