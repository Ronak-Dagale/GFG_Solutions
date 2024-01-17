//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  vector<vector<int>>ans;
  set<vector<int>>sp;
  void solve(vector<int>arr ,int j,int n){
      if(j==n){
        if(sp.find(arr)==sp.end()){
        sp.insert(arr);
        ans.push_back(arr);
        }
      }
      for(int i= j;i<n;i++){
         
            swap(arr[i],arr[j]);
             solve(arr,j+1,n);
              swap(arr[i],arr[j]);
      }
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        solve(arr,0,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends