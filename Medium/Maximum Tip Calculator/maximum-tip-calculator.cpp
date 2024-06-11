//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        long long ans=0;
       vector<pair<int,int>>fre;
       for(int i=0;i<n;i++)
         fre.push_back({arr[i]-brr[i],i});
         
         sort(fre.begin(),fre.end());
         reverse(fre.begin(),fre.end());
         
         for(int i=0;i<n;i++)
         {
             if(fre[i].first>=0)
             {
                 if(x!=0)
                 {
                    ans+=arr[fre[i].second];
                    x--;
                 }
                 else
                 {
                     ans+=brr[fre[i].second];
                     y--;
                 }
             }
             else
             {
                  if(n-i<=y)
                {
                    ans=ans+brr[fre[i].second];
                    y--;
                }
                else{
                    ans=ans+arr[fre[i].second];
                    x--;
                }
             }
         }
         return ans;
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends