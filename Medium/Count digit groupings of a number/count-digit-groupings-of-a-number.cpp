//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int  solve(string str,int prev,int id,vector<vector<int>>&dp)
	{
	    if(id==str.size())
	    {
	        return 1;
	    }
	    
	    if( dp[id][prev]!=-1) return dp[id][prev];
	    int sum=0;
	    int way=0;
	    for(int i=id;i<str.size();i++)
	    {
	        sum=sum+(str[i]-'0');
	        if(sum>=prev)
	        {
	           way=way+solve(str,sum,i+1,dp);
	        }
	    }
	    return dp[id][prev]=way;
	}
	int TotalCount(string str){
	    // Code here
	     int n=str.size();
        vector<vector<int>> dp(n,vector<int>(900+1,-1));
	   
	   return  solve(str,0,0,dp);
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends