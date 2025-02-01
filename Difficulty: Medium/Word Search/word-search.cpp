//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool solve(vector<vector<char>> mat, string& word,int x,int y,int id)
  {
      if(id>=word.size()) return 1;
      
      bool ans=0;
      int n=mat.size(),m=mat[0].size();
      
      int dx[]={1,0,-1,0};
      int dy[]={0,1,0,-1};
      
      for(int k=0;k<4;k++)
      {
         int nx=x+dx[k];
         int ny=y+dy[k];
         
         if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==word[id])
         {
             char ch=word[id];
             mat[x][y]=' ';
             ans=solve(mat,word,nx,ny,id+1);
             mat[x][y]=ch;
             
             if(ans) return 1;
         }
      }
      return 0;
  }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            bool ans=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==word[0])
                {
                    char ch=word[0];
                    mat[i][j]=' ';
                    bool ans=solve(mat,word,i,j,1);
                    mat[i][j]=ch;
                    if(ans)
                    return 1;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends