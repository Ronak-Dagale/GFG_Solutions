//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans=0;
	    map<int,int>mp;
	    
	    for(int i=a;i<=b;i++)
	    {
	        int n=i;
	        
	        while(n!=0)
	        {
	            int temp=n;
	           if(n==1) break;
	           
	           for(int j=2;j*j<=n;j++)
	           {
	               if(n%j==0)
	               {
	                   mp[j]++;
	                   n=n/j;
	                   break;
	               }
	           }
	           if(temp==n)
	           {
	               mp[n]++;
	               n=0;
	           }
	        }
	    }
	    
	    for(auto v:mp)
	    {
	        ans=ans+(v.second);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends