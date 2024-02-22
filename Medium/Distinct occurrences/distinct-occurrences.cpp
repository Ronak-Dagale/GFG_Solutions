//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    const int mod=1e9+7;
    int solve(int i,int j,string s,string t,vector<vector<int>>&dp)
    {
        if(j>=t.size())
        {
            return 1;
        }
        if(i>=s.size())
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int ans=0;
        if(s[i]==t[j])
        {
            ans=(ans%mod+solve(i+1,j+1,s,t,dp)%mod)%mod;
        }
        ans=ans%mod+solve(i+1,j,s,t,dp)%mod;
        
        return dp[i][j]=ans%mod;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
       vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
       return solve(0,0,s,t,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends