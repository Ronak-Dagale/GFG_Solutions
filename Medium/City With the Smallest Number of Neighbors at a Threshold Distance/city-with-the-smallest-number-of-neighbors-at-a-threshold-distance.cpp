//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int djs(vector<pair<int,int>>adj[],int n,int k,int src)
  {
      priority_queue<int>q;
      q.push(src);
      
      vector<int>dis(n,INT_MAX);
      dis[src]=0;
      while(!q.empty())
      {
          int front=q.top();
          q.pop();
          
          for(auto v:adj[front])
          {
              int x=v.first;
              int y=v.second;
              
              if(dis[x]>dis[front]+y)
              {
                  dis[x]=dis[front]+y;
                  q.push(x);
              }
          }
      }
      
      int ans=0;
      for(int i=0;i<n;i++)
      {
          if(dis[i]<=k)ans++;
      }
      return ans;
  }
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int>dis(n,0);
        for(int i=0;i<n;i++)
        {
            dis[i]=djs(adj,n,distanceThreshold,i);
        }
        
        int ans=INT_MAX;
        int id=-1;
        
        for(int i=0;i<n;i++)
        {
            if(ans>=dis[i])
            {
                ans=dis[i];
                id=i;
            }
        }
        return id;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends