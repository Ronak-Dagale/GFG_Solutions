//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

int solve(vector<vector<int>> &mat,int r,int c,int cr,int cc,int cost,vector<vector<int>> &vis)
{
     int ans=INT_MAX;
    if(cc==c-1)
    return cost+1;
    if(vis[cr][cc]==1)
    return ans;
    if(cr<0 || cc<0 || cr>=r || cc>=c || (cr+1<r && mat[cr+1][cc]==0) || 
    (cr-1>=0 && mat[cr-1][cc]==0) || (cc+1<c && mat[cr][cc+1]==0) || (cc-1>=0 && mat[cr][cc-1]==0))
    return INT_MAX;
     vis[cr][cc]=1;
   
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    
        for(int j=0;j<4;j++)
        {
            
                 int nx=cr+dx[j];
                 int ny=cc+dy[j];
            if(nx>=0 && ny>=0 && nx<r && ny<c && mat[nx][ny]==1) 
{               ans=min(ans,solve(mat,r,c,nx,ny,cost+1,vis)); }
        }
       vis[cr][cc]=0;
     return ans;
}
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int r=mat.size();
       int c=mat[0].size();
       int ans=INT_MAX;
        vector<vector<int>> vis(r, vector<int>(c, 0));
       for(int i=0;i<r;i++)
       {
           if(mat[i][0]==1)
           {
             ans=min(ans,solve(mat,r,c,i,0,0,vis));   
           }
       }
       
       return ans==INT_MAX?-1:ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends