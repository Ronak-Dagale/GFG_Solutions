//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int> nextsmallestele(vector<int>&arr,int n)
  {
      stack<int>s;
      s.push(-1);
      
      vector<int>ans(n);
      
      for(int i=n-1;i>=0;i--){
          while(s.top()!=-1 && arr[s.top()]>=arr[i]) s.pop();
          
          ans[i]=s.top();
          s.push(i);
      }
      return ans;
  }
   vector<int> prevsmallestele(vector<int>&arr,int n)
  {
      stack<int>s;
      s.push(-1);
      
      vector<int>ans(n);
      
      for(int i=0;i<n;i++){
          while(s.top()!=-1 && arr[s.top()]>=arr[i]) s.pop();
          
          ans[i]=s.top();
          s.push(i);
      }
      return ans;
  }
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        int ans=0;
        
        vector<int>nextarr=nextsmallestele(arr,n);
        vector<int>prevarr=prevsmallestele(arr,n);
        
        for(int i=0;i<n;i++)
        {
            if(nextarr[i]==-1){
                nextarr[i]=n;
            }
            
            int l=nextarr[i]-prevarr[i]-1;
           
            ans=max(ans,(l*arr[i]));
        }
        return ans;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends