//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(ele1<arr[i])
            {
                ele2=ele1;
                ele1=arr[i];
            }
            else if(ele2<arr[i])
            {
                ele2=arr[i];
            }
        }
        return ele1+ele2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends