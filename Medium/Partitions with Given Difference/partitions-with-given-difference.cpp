//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int s1=0,s2=0;
        int ans=0;
        long long int sum=0;
        for(int i=0;i<n;i++)
        sum+=arr[i];
        
        vector<int>dp1(sum+1,0);
        vector<int>dp2(sum+1,0);
        dp1[0]=1;
        dp2[0]=1;
        long long int temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=arr[i];
            for(int j=0;j<=temp;j++)
            {
                if(j-arr[i]>=0)
                dp2[j]=(dp1[j]+dp1[j-arr[i]])%mod;
            }
            dp1=dp2;
            // for(int j=0;j<=sum;j++)
            // {
            //     cout<<dp1[j]<<" ";
            // }
            // cout<<endl;
        }
        
        for(int i=0,j=sum;i<=sum;i++,j--)
        {
           if(i-j==d)
           ans=dp1[i];
        }
       
            
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends