//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
bool solve(vector<vector<int>>& matrix,int row,int l,int r,int target)
    {
        while(l<=r)
        {
          int mid=(r+l)/2;
            
            if(matrix[row][mid]==target) return 1;
            else if(matrix[row][mid]<target)
            {
               l=mid+1;
            }
            else
                r=mid-1;
        }
        return 0;
            
    }
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int row=0,l=0,r=M-1;
	    while(row<N)
	    {
	        if(X>=mat[row][l] && X<=mat[row][r])
	        {
	            bool pre=solve(mat,row,l,r,X);
	            if(pre)
	            return 1;
	        }
	        row++;
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends