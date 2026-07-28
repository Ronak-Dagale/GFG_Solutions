class Solution {
  public:
    int shortestPath(int n, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<int>dist(n,INT_MAX);
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:edges){
            int u=e[0],v=e[1],w=e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,src});
        
        dist[src]=0;
        
        while(!q.empty()){
            
            auto [w,u]=q.top();
            q.pop();
            
            for(auto& [v,wt] : adj[u]){
                if(wt + w < dist[v]){
                    dist[v] = wt + w;
                    q.push({dist[v],v});
                }
            }
        }
        return dist[dest]==INT_MAX?-1:dist[dest];
    }
};