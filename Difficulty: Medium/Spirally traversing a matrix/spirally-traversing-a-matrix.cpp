//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int>ans;
        int n=matrix.size(),m=matrix[0].size();
        int sr=0,sc=0,er=n-1,ec=m-1;
        int i=0,j=0;
        
        while((ans.size())!=(n*m))
        {
            while((ans.size())!=(n*m) && j<=ec)
            {
                ans.push_back(matrix[i][j++]);
            }
            i++;
            j--;
            sr++;
            while((ans.size())!=(n*m) && i<=er)
            {
                ans.push_back(matrix[i++][j]);
            }
            i--;
            j--;
            ec--;
            while((ans.size())!=(n*m) && j>=sc)
            {
                ans.push_back(matrix[i][j--]);
            }
            j++;
            i--;
            er--;
            while((ans.size())!=(n*m) && i>=sr)
            {
                ans.push_back(matrix[i--][j]);
            }
            i++;
            j++;
            sc++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends