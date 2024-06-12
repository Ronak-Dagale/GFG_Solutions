//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool iscon(int n)
  {
      while(n)
      {
          if(n%10==4) return 1;
          n=n/10;
      }
      return 0;
  }
    int countNumberswith4(int n) {
        // code here
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(iscon(i))ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends