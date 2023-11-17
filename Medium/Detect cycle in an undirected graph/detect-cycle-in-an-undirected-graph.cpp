//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscyclicbfs(int src,vector<bool>&vis, vector<int> adj[])
    {
         unordered_map<int,int>parent;
         parent[src]=-1;
         vis[src]=1;
         
         queue<int>q;
         q.push(src);
         
         while(!q.empty())
         {
             int front=q.front();
             q.pop();
             
             for(auto n:adj[front])
             {
                 if(vis[n] && n!=parent[front]) return 1;
                 else if(!vis[n])
                 {
                     vis[n]=1;
                     q.push(n);
                     parent[n]=front;
                 }
             }
         }
         return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,0);
        
       // to handle disconnected component
       
       for(int i=0;i<V;i++)
      {
          if(!vis[i])
          {
              bool ans=iscyclicbfs(i,vis,adj);
              if(ans)
              return 1;
          }
      }
      return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends