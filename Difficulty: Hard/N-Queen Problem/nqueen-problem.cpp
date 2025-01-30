//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool chk(int x,int y,vector<vector<bool>>&chess,int n)
  {
      // column chk
      for(int i=0;i<=y;i++)
      if(chess[x][i]) return 1;
      
      // row check
      for(int i=0;i<=x;i++)
      if(chess[i][y]) return 1;
      
      // uper diagonal
      for(int i=x,j=y;i>=0 && j>=0;i--,j--)
      {
          if(chess[i][j]) return 1;
      }
      
      for(int i=x,j=y;i>=0 && j<n;i--,j++)
      {
          if(chess[i][j]) return 1;
      }
      
      return 0;
  }
  void solve(int n,vector<vector<bool>>chess,vector<int>tmp,vector<vector<int>>&ans,int id)
  {
     if(id==n)
     {
         if(tmp.size()==n)
         ans.push_back(tmp);
         
         return;
     }
     
     for(int i=0;i<n;i++)
     {
         if(!chk(id,i,chess,n))
         {
            chess[id][i]=1;
            tmp.push_back(i+1);
            solve(n,chess,tmp,ans,id+1);
            tmp.pop_back();
            chess[id][i]=0;
         }
     }
  }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<int>tmp;
        vector<vector<bool>>chess(n,vector<bool>(n,0));
        
        solve(n,chess,tmp,ans,0);
        
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
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends