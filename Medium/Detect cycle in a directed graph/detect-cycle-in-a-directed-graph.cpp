//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool chkcycleDFS(int node,vector<int> adj[],vector<bool>&vis,vector<bool>&dfsvis)
    {
        vis[node]=1;
        dfsvis[node]=1;
        
        for(auto ne:adj[node])
        {
            if(!vis[ne])
            {
                bool cycle=chkcycleDFS(ne,adj,vis,dfsvis);
                if(cycle) return 1;
            }
            else if(dfsvis[ne])
            return 1;
            
        }
        dfsvis[node]=0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,0);
        vector<bool>dfsvis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                bool cycle=chkcycleDFS(i,adj,vis,dfsvis);
                if(cycle)return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends