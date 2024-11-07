//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int i=0,j=arr.size()-1;
        long long sum1=arr[i],sum2=0,sum3=arr[j];
        
        for(int k=0;k<arr.size();k++)
        sum2+=arr[k];
        
        sum2-=sum1;
        sum2-=sum3;
        
        if(sum1==sum2 && sum2==sum3) return {i,j-1};
        i++;
        j--;
        while(i<j)
        {
           if(sum1<sum3)
           {
              sum1+=arr[i];
              sum2-=arr[i];
              i++;
           }
           else
           {
               sum3+=arr[j];
               sum2-=arr[j];
               j--;
           }
           if(sum1==sum2 && sum2==sum3) return {i,j-1};
        }
        return {-1,-1};
    }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends