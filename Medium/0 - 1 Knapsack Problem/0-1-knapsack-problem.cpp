//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int wt[],int val[],int id,int w,int n, vector<vector<int>>&dp)
    {
        if(w<0)
        return 0;
        
        if(id==n)
        {
            return 0;
        }
        if(dp[id][w]!=-1)
        return dp[id][w];
        
        int incl=0,excl=0;
        
        if(w-wt[id]>=0)
        incl=val[id]+solve(wt,val,id+1,w-wt[id],n,dp);
        
        excl=solve(wt,val,id+1,w,n,dp);
        
        return dp[id][w]=max(incl,excl);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return solve(wt,val,0,W,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends