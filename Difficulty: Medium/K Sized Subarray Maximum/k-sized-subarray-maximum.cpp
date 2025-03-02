//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<int>q;
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
            q.push(arr[i]);
        }
        
        for(int i=0,j=k;j<arr.size();j++,i++){
           while(!q.empty() && mp[q.top()]<=0){
               q.pop();
           }
           
           ans.push_back(q.top());
            mp[arr[i]]--;
            mp[arr[j]]++;
            q.push(arr[j]);
        }
        
        while(!q.empty() && mp[q.top()]<=0) q.pop();
        
        ans.push_back(q.top());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends