//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int binarysearchleft(vector<int>&arr,int x)
  {
      int l=0,r=arr.size()-1;
      int ans=-1;
      while(l<=r)
      {
          int mid=l+(r-l)/2;
          if(arr[mid]==x)
          {
              ans=mid;
              r=mid-1;
          }
          else if(arr[mid]<x)
          l=mid+1;
          else
          r=mid-1;
      }
      return ans;
  }
  int binarysearchright(vector<int>&arr,int x)
  {
      int l=0,r=arr.size()-1;
      int ans=-1;
      while(l<=r)
      {
          int mid=l+(r-l)/2;
          if(arr[mid]==x)
          {
              ans=mid;
              l=mid+1;
          }
          else if(arr[mid]<x)
          l=mid+1;
          else
          r=mid-1;
      }
      return ans;
  }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int left=binarysearchleft(arr,target);
        int right=binarysearchright(arr,target);
        
        return left==-1?0:right-left+1;
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
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends