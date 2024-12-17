//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isposs(vector<int>&stalls,int k,int mid)
    {
        int cnt=1;
        int prev=0,i=0;
        
        while(i<stalls.size())
        {
            if(stalls[i]-stalls[prev]<mid)
            i++;
            else 
            {
                cnt++;
                if(cnt>=k) return 1;
                prev=i;
                i++;
            }
        }
        if(cnt>=k) return 1;
        return 0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int s=0,e=stalls[n-1]-stalls[0];
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            if(isposs(stalls,k,mid))
            {
                ans=mid;
                s=mid+1;
            }
            else
            e=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends