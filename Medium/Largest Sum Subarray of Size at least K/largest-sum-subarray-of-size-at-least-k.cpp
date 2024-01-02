//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int v[n];
        for(long long int i=0;i<n;i++)
        v[i]=a[i];
        
        long long int ans=INT_MIN;
        for(long long int i=n-2;i>=0;i--)
        {
            if(v[i+1]>=0)
            v[i]=v[i]+v[i+1];
        }
        if(v[1]>=0)
        v[0]=v[0]+v[1];
        
        // for(long long int i=0;i<n;i++)
        // cout<<v[i]<<" ";
        
        long long int sum=0;
        for(long long int i=0;i<k;i++)
        {
            sum=sum+a[i];
        }
        ans=max(ans,sum);
        
        if(k<n && v[k]>=0)
        {
            ans=max(ans,sum+v[k]);
        }
        
        long long int j=0;
        
        for(long long int i=k;i<n;i++)
        {
            sum=sum+a[i];
            sum=sum-a[j++];
            
            ans=max(ans,sum);
            if(i+1<n && v[i+1]>=0)
            {
                ans=max(ans,sum+v[i+1]);
            }
        }
        return ans;;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends