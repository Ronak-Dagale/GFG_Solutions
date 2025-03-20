//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &price) {
        // code here
         int s1=0,s2=0;
            int b1=INT_MAX,b2=INT_MAX;
            
            for(int i=0;i<price.size();i++)
            {
                b1=min(b1,price[i]);
                s1=max(s1,price[i]-b1);
                b2=min(b2,price[i]-s1);
                s2=max(s2,price[i]-b2);
            }
            return s2;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends