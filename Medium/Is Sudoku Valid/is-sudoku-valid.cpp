//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool valid(vector<vector<int>> &mat,int val,int r,int c)
{
    for(int i=0;i<mat.size();i++)
    {
        if(mat[r][i]==val)return 0;
        if(mat[i][c]==val) return 0;
        
        if(mat[3*(r/3)+(i/3)][3*(c/3)+i%3]==val) return 0;
    }
    return 1;
}
    int isValid(vector<vector<int>> mat){
        // code here
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=0)
                {
                    int val=mat[i][j];
                    mat[i][j]=0;
                    
                    if(valid(mat,val,i,j))
                    mat[i][j]=val;
                    else
                    return 0;
                }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends