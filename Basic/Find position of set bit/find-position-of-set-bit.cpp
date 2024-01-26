//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        int ans=-1;
        int cnt=0;
        int pos=0;
        
        while(N!=0)
        {
            pos++;
            if(N&1)
            {
                cnt++;
                if(cnt==1)
                {
                    ans=pos;
                }
                else
                return -1;
            }
            N=N>>1;
        }
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

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends