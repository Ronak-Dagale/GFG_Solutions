//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>nums={1,2,5, 10, 20, 50, 100, 200, 500, 2000 };
        
        vector<int>dp(N+1,INT_MAX);
        vector<int>cnt(N+1,0);
        dp[0]=0;
        
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                int temp=dp[i];
            if(i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX)
           {
               dp[i]=min(dp[i],1+dp[i-nums[j]]);
               if(temp!=dp[i])
                cnt[i]=nums[j];
           }
            }
        }
        
        
        vector<int>ans;
        int p=cnt[N];
        
        while(N>0)
        {
            ans.push_back(cnt[N]);
            N=N-cnt[N];
        }
        reverse(ans.begin(),ans.end());
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
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends