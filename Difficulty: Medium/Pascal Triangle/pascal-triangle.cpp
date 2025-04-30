//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
          int mod=1e9+7;
        vector<vector<int>>Triangle;
        
        Triangle.push_back({1});
        
        for(int i=1;i<n;i++)
        {
            vector<int>row;
            row.push_back(1);
            for(int j=0;j<Triangle[i-1].size()-1;j++)
            {
                int cal=((Triangle[i-1][j])%mod+(Triangle[i-1][j+1])%mod)%mod;
                row.push_back(cal);
            }
            row.push_back(1);
            Triangle.push_back(row);
        }
        
        return Triangle[n-1];
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends