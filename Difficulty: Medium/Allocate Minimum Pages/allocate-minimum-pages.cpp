//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isposs(vector<int>&arr,int k,int mid)
  {
      int cnt=1;
      int alloc=0;
      if(arr[0]>mid) return 0;
      for(int i=0;i<arr.size();i++)
      {
          if(alloc+arr[i]<=mid)
          alloc+=arr[i];
          else
          {
              cnt++;
              if(arr[i]>mid)
              return 0;
              
              if(cnt>k) return 0;
              alloc=arr[i];
              
          }
      }
      return 1;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        int s=0,e=0;
        e=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        if(k>arr.size()) return ans;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isposs(arr,k,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
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

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends