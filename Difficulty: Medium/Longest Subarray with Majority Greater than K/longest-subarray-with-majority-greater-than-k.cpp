//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int cnt=0,ans=0;
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=k) cnt--;
            else cnt++;
            
            if(cnt<=0 && !mp.count(cnt)) mp[cnt]=i;
            if(cnt<=0 && mp.count(cnt-1)) ans=max(ans,i-mp[cnt-1]);
            if(cnt>0) ans=i+1;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends