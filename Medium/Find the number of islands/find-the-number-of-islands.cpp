//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void solve(vector<vector<bool>>&vis,int n,int m,int i,int j,vector<vector<char>>& grid)
    {
        vis[i][j]=1;
        
        int dx[]={1,-1,0,0,1,1,-1,-1};
        int dy[]={0,0,1,-1,1,-1,-1,1};
        
        for(int k=0;k<8;k++)
        {
            int nx=dx[k]+i;
            int ny=dy[k]+j;
            
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1' && vis[nx][ny]==0)
            {
                solve(vis,n,m,nx,ny,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    ans++;
                    solve(vis,n,m,i,j,grid);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends