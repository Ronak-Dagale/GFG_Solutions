//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        int a=1,b=1,c=1;
        int mod=1e9+7;
        if(n<=2) return c;
        int ans=1;
        for(int i=3;i<=n;i++)
        {
            ans=(a+b)%mod;
            a=b%mod;
            b=c%mod;
            c=ans%mod;
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
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends