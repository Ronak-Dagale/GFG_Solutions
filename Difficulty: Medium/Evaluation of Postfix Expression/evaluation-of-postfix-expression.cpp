//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<string>s;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=="+" || arr[i]=="-" || arr[i]=="*" || arr[i]=="/"){
                int n1=stoi(s.top());
                s.pop();
                int n2=stoi(s.top());
                s.pop();
                
                int res=0;
                if(arr[i]=="+") res=n1+n2;
                else if(arr[i]=="-") res=n2-n1;
                else if(arr[i]=="*") res=n1*n2;
                else res=floor(n2/n1);
                
                s.push(to_string(res));
            }
            else
            s.push(arr[i]);
        }

        return stoi(s.top());
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends