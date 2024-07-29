//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  int bs(vector<vector<int> > &arr,int i)
  {
      int s=0;
      int e=arr[0].size()-1;
      int ans=-1;
      while(s<=e)
      {
          int mid=s+(e-s)/2;
          if(arr[i][mid]==1)
          {
              ans=mid;
              e=mid-1;
          }
          else
          {
              s=mid+1;
          }
      }
      return ans;
  }
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int ans=-1;
        int cnt=0;
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++)
        {
          int id=bs(arr,i);
          if(id!=-1 && cnt<(m-id))
          {
              ans=i;
              cnt=m-id;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends