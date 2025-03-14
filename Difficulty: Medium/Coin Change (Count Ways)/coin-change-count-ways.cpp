//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here..
        int N=coins.size();
        
         if(sum==0) return 1;
        vector<long long int>dp(sum+1,0);
        for(long long int i=0;i<N;i++)
        {
            for(long long int j=1;j<=sum;j++)
            {
                int temp=j-coins[i];
                if(temp==0)
                dp[j]++;
                else if(temp>0)
                dp[j]+=dp[temp];
            }
        }
        return dp[sum];
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends