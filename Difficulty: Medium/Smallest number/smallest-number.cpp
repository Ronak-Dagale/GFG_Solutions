//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     int digitSum(int n){
        int sum = 0;
        while(n>0){
            int rem = n%10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    string smallestNumber(int s, int d) {
        // code here
        for(int i = pow(10,d-1); i<=pow(10,d)-1;i++){
            if(digitSum(i) == s){
                return to_string(i);
            }
        }
        return to_string(-1);
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends