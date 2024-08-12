//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n1=arr1.size(),n2=arr2.size();
        if(n1>n2)
        {
            return SumofMiddleElements(arr2,arr1);
        }
        
        int s=0,e=n1;
        int total=(n1+n2+1)/2;
        while(s<=e)
        {
            int mid1=(s+e)/2;
            int mid2=total-mid1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MIN,r2=INT_MIN;
        
            if(mid1<n1) r1=arr1[mid1];
            if(mid2<n2) r2=arr2[mid2];
            if(mid1-1>=0) l1=arr1[mid1-1];
            if(mid2-1>=0) l2=arr2[mid2-1];
            
            if(l1<=r2 && l2<=r1)
          {
              if((n1+n2)&1)
              return max(l1,l2);
              else
              return max(l1,l2)+min(r1,r2);
          }
          else if(l1>r2)
          e=mid1-1;
          else
          s=mid1+1;
            
        }
        return -1;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends