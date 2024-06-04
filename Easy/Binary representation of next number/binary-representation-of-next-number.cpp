//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        reverse(s.begin(), s.end());
    int carry = 1;
    for (int i = 0; i < s.size() && carry == 1; i++)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            carry = 0;
        }
        else
        {
            s[i] = '0';
            carry = 1;
        }
    }
    if (carry)
    {
        s += '1';
    }
    reverse(s.begin(), s.end());
    int i = 0;
    while (s[i] == '0')
    {
        i++;
    }
    return s.substr(i, s.size());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends