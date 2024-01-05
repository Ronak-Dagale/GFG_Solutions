//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int mod=1e9+7;
	    if(N==1) return 4;
	    if(N==2) return 9;
	    
	    long long int a=2,b=3,c;
	    for(int i=3;i<=N;i++)
	    {
	        c=(a+b)%mod;
	         a=b%mod;
	         b=c%mod;
	    }
	    return (c*c)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends