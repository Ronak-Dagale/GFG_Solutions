//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int k=0;
        while(arr.size()>1)
        {
            int n=arr.size();
            int tmp=arr[n-1];
            arr.pop_back();
            arr.insert(arr.begin(),tmp);
            int del=n-(k+1);
            if(k>=n)
            arr.erase(arr.begin());
            else
            {
                arr.erase(arr.begin()+del);
                k++;
            }
        }
        return arr[0];
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends