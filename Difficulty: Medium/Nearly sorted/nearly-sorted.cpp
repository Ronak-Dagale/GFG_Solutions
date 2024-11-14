//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
         priority_queue<int, vector<int>, greater<int> > pk;
        int n=arr.size();
        for(int i=0; i<k+1; i++){
            pk.push(arr[i]);
        }
        for(int i=0; i<n-k-1; i++){
            arr[i]=pk.top();
            pk.pop();
            pk.push(arr[i+k+1]);
        }
        for(int i=n-k-1; i<n; i++){
            arr[i]=pk.top();
            pk.pop();
        }
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends