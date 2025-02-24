//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n=arr.size();
        stack<pair<int,int>>s;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[i]>=s.top().first) s.pop();
            
            int num=arr[i];
            if(s.empty()) arr[i]=i+1;
            else arr[i]=i-s.top().second;
            
            s.push({num,i});
        }
        return arr;
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends