//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool chk(int v,int m,bool graph[101][101],vector<int>&col)
    {
        for(int i=0;i<col.size();i++)
        {
          if(graph[v][i] && col[i]==m)
          return 0;
        }
        return 1;
    }
    void solve(bool graph[101][101],int v,vector<int>&col,bool &flag,int m,int n)
    {
        if(v==n)
        {
            flag=1;
            return;
        }
        
        for(int i=0;i<m;i++)
        {
            if(chk(v,i,graph,col))
            {
                col[v]=i;
                solve(graph,v+1,col,flag,m,n);
                col[v]=-1;
            }
            if(flag)
            break;
        }
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        bool flag=0;
        vector<int>col(n,-1);
        solve(graph,0,col,flag,m,n);
        return flag;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends