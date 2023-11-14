//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   void pushsoln(int n,vector<vector<bool>>&board,vector<vector<int>>&ans)
   {
       vector<int>temp;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(board[j][i])
                temp.push_back(j+1); 
           }
       }
       ans.push_back(temp);
   }
   bool issafe(int col,int row,vector<vector<bool>>&board,int n)
   {
       // row wise chk
       int x=row;
       int y=col;
       y--;
       while(y>=0)
       {
           if(board[x][y])
           return 0;
           
           y--;
       }
       
       x=row;
       y=col;
       
       // upper diagonal
       x--;
       y--;
       while(x>=0 && y>=0)
       {
          if(board[x][y]) return 0;
          
          x--;
          y--;
       }
       
        x=row;
       y=col;
       y--;
       x++;
       // lower diagonal
       
       while(y>=0 && x<n)
       {
           if(board[x][y]) return 0;
           
           y--;
           x++;
       }
       return 1;
   }
   void solve(int col, vector<vector<int>>&ans,vector<vector<bool>>board,int n)
   {
       if(col==n)
       {
           pushsoln(n,board,ans);
           return;
       }
       
       for(int i=0;i<n;i++)
       {
           if(issafe(col,i,board,n))
           {
               board[i][col]=1;
               solve(col+1,ans,board,n);
               board[i][col]=0;
           }
       }
   }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<vector<bool>>board(n,vector<bool>(n,0));
        
        solve(0,ans,board,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends