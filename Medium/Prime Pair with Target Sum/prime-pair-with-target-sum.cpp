//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  bool isprime(int n)
  {
      if(n==1) return 0;
      for(int i=2;i*i<=n;i++){
          if(n%i==0) return 0;
      }
      return 1;
  }
    vector<int> getPrimes(int n) {
        // code here
        vector<int>ans(2,-1);
        int i=1,j=n-1;
        while(i<=j)
        {
            if(isprime(i) && isprime(j))
            {
                ans[0]=i;
                ans[1]=j;
                break;
            }
            i++;
            j--;
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

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends