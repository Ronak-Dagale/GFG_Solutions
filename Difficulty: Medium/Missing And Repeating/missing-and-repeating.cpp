//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int r1,r2;
        for(int i=0;i<arr.size();i++)
        {
           int id=abs(arr[i])-1;
           if(arr[id]<0)
           r1=abs(arr[i]);
           else
           arr[id]=-arr[id];
        }
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>0)
            r2=i+1;
        }
        return {r1,r2};    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends