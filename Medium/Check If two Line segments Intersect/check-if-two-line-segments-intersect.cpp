//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
double fnct(int x1, int y1, int x2, int y2, int x, int y) {
    return (double)((x2 - x1) * (y - y1) - (y2 - y1) * (x - x1));
}

string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
    // Checking the orientations
    string ans="";
        long long int x1l1=p1[0];
        long long int y1l1=p1[1];
        long long int x2l1=q1[0];
        long long int y2l1=q1[1];
        long long int x1l2=p2[0];
        long long int y1l2=p2[1];
        long long int x2l2=q2[0];
        long long int y2l2=q2[1];
        long long int a=((x2l1-x1l2)*(y1l1-y1l2))-((x1l1-x1l2)*(y2l1-y1l2));
        long long int b=((x2l1-x2l2)*(y1l1-y2l2))-((x1l1-x2l2)*(y2l1-y2l2));
        long long int c=((x2l2-x1l1)*(y1l2-y1l1))-((x1l2-x1l1)*(y2l2-y1l1));
        long long int d=((x2l2-x2l1)*(y1l2-y2l1))-((x1l2-x2l1)*(y2l2-y2l1));
        if(a==0 && b==0 && c==0 && d==0){
            if((x1l1<=x1l2 && x1l1>=x2l2)||(y1l1<=y1l2 && y1l1>=y2l2)){
                ans+="true";
                return ans;
            }
            else if((x1l1<=x2l2 && x2l1>=x2l2)||(y1l1<=y2l2 && y2l1>=y2l2)){
                ans+="true";
                return ans;
            }
            else{
                return "false";
                return ans;
            }
        }
        if(((a>=0 && b<=0) && (c>=0 && d<=0))||((a<=0 && b>=0) && (c<=0 && d>=0))||((a>=0 && b<=0) && (c<=0 && d>=0))||((a<=0 && b>=0) && (c>=0 && d<=0)))
        {
        ans+="true";
        return ans;
        }
        return "false";
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends