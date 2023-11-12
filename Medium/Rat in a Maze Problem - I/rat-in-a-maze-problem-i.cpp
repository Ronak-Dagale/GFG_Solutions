//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
     void solve(vector<vector<int>> &m,vector<vector<int>>v,string temp,vector<string>&ans,int i,int j)
    {
        int n=m.size()-1;
        if(i==n && j==n)
        {
            ans.push_back(temp);
            return;
        }
         v[i][j]=1;
        int dx[]={1,0,0,-1};
        int dy[]={0,1,-1,0};
        
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            
            if(x>=0 && x<=n && y>=0 && y<=n && m[x][y]==1 && v[x][y]==0)
            {
                    if(dx[k]==1)
                    temp.push_back('D');
                    else if(dx[k]==-1)
                    temp.push_back('U');
                    else if(dy[k]==1)
                    temp.push_back('R');
                    else if(dy[k]==-1)
                    temp.push_back('L');
                
               
                solve(m,v,temp,ans,x,y);
                temp.pop_back();
                //v[x][y]=0;
                // x=x-dx[k];
                // y=y-dy[k];
            }
            
        }
         v[i][j]=0;
       

    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
       vector<string>ans;
        if(m[0][0]==0 || m[n-1][n-1]==0)
        return ans;
        
        vector<vector<int>>v(n,vector<int>(n,0));
        string temp;
        solve(m,v,temp,ans,0,0);
      
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends