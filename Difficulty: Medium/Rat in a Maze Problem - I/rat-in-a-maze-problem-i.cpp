//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  void solve(vector<vector<int>> &mat, vector<vector<bool>>vis,string s, vector<string>&ans,int x,int y)
  {
       int n=mat.size();
      if(x==n-1 && y==n-1)
      {
        ans.push_back(s);
        return;
      }
      
      int dx[]={1,0,-1,0};
      int dy[]={0,1,0,-1};
     
      for(int i=0;i<4;i++)
      {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<n && ny<n && mat[nx][ny]==1 && vis[nx][ny]==0)
        {
          if(dx[i]==1) s.push_back('D');
          else if(dx[i]==-1) s.push_back('U');
          else if(dy[i]==1) s.push_back('R');
          else s.push_back('L');
          
          vis[nx][ny]=1;
          solve(mat,vis,s,ans,nx,ny);
          vis[nx][ny]=0;
          s.pop_back();
        }
      }
  }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>ans;
        string s;
        int n=mat.size();
        
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        
        if(mat[0][0]==0 || mat[n-1][n-1]==0)
        return {};
        
        vis[0][0]=1;
        solve(mat,vis,s,ans,0,0);
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends