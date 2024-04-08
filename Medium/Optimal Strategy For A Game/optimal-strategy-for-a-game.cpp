//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(vector<vector<long long>>&dp,int i,int j,int arr[])
    {
        if(i>j) return 0;
         if(dp[i][j] != -1) return dp[i][j];
        int left=arr[i],right=arr[j];
        
        left+=min(solve(dp,i+2,j,arr),solve(dp,i+1,j-1,arr));
        right+=min(solve(dp,i+1,j-1,arr),solve(dp,i,j-2,arr));
        return dp[i][j]=max(left,right);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        return solve(dp,0,n-1,arr);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends