//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int findmini(vector<int>&ans,vector<bool>&vis)
    {
        int re=-1;
        int mini=INT_MAX;
        
        for(int i=0;i<ans.size();i++)
        {
            if(!vis[i] && mini>ans[i])
            {
                re=i;
                mini=ans[i];
            }
        }
        return re;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<vector<int>>dis(V,vector<int>(V,INT_MAX));
        for(int i=0;i<V;i++)
        {
            int k=0;
            int z=0;
          for(auto j:adj[i])
          {
              z=j[0];
              k=j[1];
              dis[i][z]=k;
              dis[z][i]=k;
             
          }
        }
        
        // for(int i=0;i<V;i++)
        // {
        //     for(int j=0;j<V;j++)
        //     {
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int>ans(V,INT_MAX);
        ans[S]=0;
        
        vector<bool>vis(V,0);
        
        
        for(int i=0;i<V-1;i++)
        {
            int u=findmini(ans,vis);
          //  cout<<u<<endl;
            vis[u]=1;
            
            for(int j=0;j<V;j++)
            {
                if(!vis[j] && dis[u][j]!=INT_MAX && ans[u]+dis[u][j]<ans[j])
                {
                    ans[j]=ans[u]+dis[u][j];
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends