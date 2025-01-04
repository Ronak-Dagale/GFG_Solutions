//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int ans=0;
        int n=arr.size();
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                int req = target - (arr[i] + arr[j]);
                
                auto low = lower_bound(arr.begin()+j+1, arr.end(), req);
                auto high = upper_bound(arr.begin()+j+1, arr.end(), req);
                
                ans += (high-low);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends