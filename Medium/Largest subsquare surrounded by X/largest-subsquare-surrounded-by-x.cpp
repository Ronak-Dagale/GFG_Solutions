//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        vector<vector<int>>row(n,vector<int>(n,0));
        vector<vector<int>>col(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='X')
                cnt++;
                else
                cnt=0;
                
                row[i][j]=cnt;
            }
        }
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(a[j][i]=='X')
                cnt++;
                else
                cnt=0;
                
                col[j][i]=cnt;
            }
        }
        
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int side=min(row[i][j],col[i][j]);
                while(side>ans)
                {
                    if(row[i-side+1][j]>=side && col[i][j-side+1]>=side)
                    {
                        ans=side;
                    }
                    else
                    side--;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends