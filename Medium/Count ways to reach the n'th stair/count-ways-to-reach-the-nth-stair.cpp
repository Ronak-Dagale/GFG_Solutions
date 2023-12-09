//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        if(n==0) return 1;
        if(n==1) return 1;
        // if(n==2) return 2;
        
        int mod=1e9+7;
        // return ((countWays(n-1)%mod)+(countWays(n-2)%mod))%mod;
        
        
        int a=1,b=1,c=0;
        
        for(int i=2;i<=n;i++)
        {
            c=(a+b)%mod;
           
            a=b%mod;
            b=c%mod;
            //cout<<a<<" "<<b<<" "<<c<<endl;
        }
        return c%mod;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends