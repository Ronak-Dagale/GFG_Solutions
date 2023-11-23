//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        int mod=1e9+7;
        vector<vector<long long>>v;
        v.push_back({1});
        
        for(int i=1;i<n;i++)
        {
            vector<long long>temp;
            temp.push_back(1);
            for(int j=0;j<v[i-1].size()-1;j++)
            {
                long long cal=((v[i-1][j])%mod+(v[i-1][j+1])%mod)%mod;
                temp.push_back(cal);
            }
            temp.push_back(1);
            v.push_back(temp);
        }
        
        return v[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
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
    }
    return 0;
}

// } Driver Code Ends