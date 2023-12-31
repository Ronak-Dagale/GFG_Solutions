//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
     int solve(int ind,int sum,int n,int coins[],vector<vector<int>>&dp){
        if(ind == n){
            if((sum%20==0 || sum%24==0 || sum==2024) && sum > 0){
                return 1;
            }
            return 0;
        }
        if((sum%20==0 || sum%24==0 || sum==2024) && sum > 0){
            return 1;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        return dp[ind][sum] = solve(ind+1,sum,n,coins,dp) | solve(ind+1,sum+coins[ind],n,coins,dp);
    }
    
    int isPossible(int N , int coins[]) 
    {
        int sum = accumulate(coins,coins+N,0ll);
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        int ans = solve(0,0,N,coins,dp);
        if(ans==0)return 0;
        return ans;
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends