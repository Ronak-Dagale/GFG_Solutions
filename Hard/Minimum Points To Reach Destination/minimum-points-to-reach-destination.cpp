//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int m, int n, vector<vector<int>> points,int x,int y,int need,int sum, vector<vector<int>>&dp)
	{
	    if(x==m-1 && y==n-1)
	    {
	         sum=sum+points[x][y];
	         need=min(need,sum);
	         
	        if(need<0) return (-need+1);
	        return 1;
	    }
	   // if(dp[x][y]!=-1)
	   // return dp[x][y];
	    
	    int ch1=INT_MAX,ch2=INT_MAX;
	    if(x+1<m)
	    ch1=solve(m,n,points,x+1,y,min(need,sum+points[x][y]),sum+points[x][y],dp);
	    if(y+1<n)
	    ch2=solve(m,n,points,x,y+1,min(need,sum+points[x][y]),sum+points[x][y],dp);
	    
	    return dp[x][y]=min(ch1,ch2);
	    
	}
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(m,vector<int>(n,0));
	    int sum=0;
	    for(int i=n-1;i>=0;i--)
	    {
	        dp[m-1][i]=sum+points[m-1][i];
	        sum=sum+points[m-1][i];
	    }
	   for(int i=m-2;i>=0;i--)
	   {
	       for(int j=n-1;j>=0;j--)
	       {
	          if(j+1<n)
	          {
	              dp[i][j]=min(points[i][j],points[i][j]+max(dp[i+1][j],dp[i][j+1]));
	          }
	          else
	          dp[i][j]=points[i][j]+dp[i+1][j];
	       }
	   }
	   //for(int i=0;i<m;i++)
	   //{
	   //    for(int j=0;j<n;j++)
	   //    {
	   //        cout<<dp[i][j]<<" ";
	   //    }
	   //    cout<<endl;
	   //}
	   return dp[0][0]<=0?(-dp[0][0]+1):1;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends