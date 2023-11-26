//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void solve(int n,vector<int>&ans,bool &flag,int N)
{
     ans.push_back(n);
    if(n<=0)
    {
        flag=1;
    }
    if(n==N && flag)
    {
        return;
    }
    
    if(flag)
    solve(n+5,ans,flag,N);
    else
    solve(n-5,ans,flag,N);
    
}
    vector<int> pattern(int N){
        // code here
        vector<int>ans;
        bool flag=0;
        solve(N,ans,flag,N);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends