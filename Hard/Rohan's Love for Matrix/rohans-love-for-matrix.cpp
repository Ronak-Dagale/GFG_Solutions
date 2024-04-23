//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int ele1=1,ele2=1;
        int mod=1e9+7;
        
        for(int i=0;i<n-1;i++)
        {
            int res1=(ele1+ele2)%mod;
            int res2=ele1%mod;
            
            ele1=res1;
            ele2=res2;
        }
        return ele2;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends