//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
     int solve(int arr[], int n,int sum1,int sum2, vector<vector<int>>&dp)
     {
         if(n<0) 
         {
             return abs(sum1-sum2);
         }
         if(dp[n][sum1]!=-1)
         return dp[n][sum1];
         
         int incl=solve(arr,n-1,sum1+arr[n],sum2-arr[n],dp);
         int excl=solve(arr,n-1,sum1,sum2,dp);
         
         return dp[n][sum1]=min(incl,excl);
     }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	     int sum=0;
	    
	     for(int i=0;i<n;i++)
	     sum+=arr[i];
	     
	      vector<vector<int>>dp(n,vector<int>(sum+1,-1));
	     return solve(arr,n-1,0,sum,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends