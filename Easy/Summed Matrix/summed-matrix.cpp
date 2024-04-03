//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if(q>n+n)
        return 0;
        if(q==1)
        return 0;
        
        long long mid=(n+n+2)/2;
        long long occ=mid-1;
        
        if(q<=mid)
        {
            return (occ-(mid-q));
        }
        else
        return (occ-(q-mid));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends