//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        vector<int>ans;
        int n=matrix.size();
        
        int row=0,col=0;
        while(col<n)
        {
          int i=0,j=col;
          while(i<n && j>=0)
          {
              ans.push_back(matrix[i][j]);
              j--;
              i++;
          }
          col++;
        }
        col--;
        row=1;
        while(row<n)
        {
            int i=row,j=col;
            while(i<n && j>=0)
            {
                ans.push_back(matrix[i][j]);
                j--;
                i++;
            }
            row++;
        }
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
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends