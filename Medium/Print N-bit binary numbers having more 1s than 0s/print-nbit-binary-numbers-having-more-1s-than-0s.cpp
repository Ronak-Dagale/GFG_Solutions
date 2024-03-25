//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
void solve(vector<string>&ans,int one,int zero,string t,int n)
{
    if(zero+one>=n)
    {
        ans.push_back(t);
        return;
    }
    solve(ans,one+1,zero,t+'1',n);
    if(one>zero)
    solve(ans,one,zero+1,t+'0',n);
    
}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>ans;
	    solve(ans,0,0,"",n);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends