//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
          int count=0;
   int n=str.length();
   int arr[26]={0};
   for(int i=0;i<n;i++){
       if(str[i]!=' '){
           arr[str[i]-'a']++;
           count++;
       }
   }
   if(count<26){
       return false;
   }
   int not_present=0;
   for(int i=0;i<26;i++){
       if(arr[i]==0){
           not_present++;
       }
   }
   return not_present<=k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends