//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
         sort(arr.begin(),arr.end());
         int ans=0;
         int diff=INT_MAX;
         int n=arr.size();
         for(int i=0;i<n-2;i++)
         {
             int s=i+1;
             int e=n-1;
             
             while(s<e)
             {
                 int sum=arr[i]+arr[s]+arr[e];
                 
                 if(abs(sum-target)<abs(target-diff))
                 {
                     diff=sum;
                     ans=sum;
                 }
                 else if(abs(sum-target)==abs(diff-target))
                 {
                     ans=max(sum,diff);
                 }
                 
                 if(sum<target)
                 s++;
                 else
                 e--;
             }
         }
         return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends