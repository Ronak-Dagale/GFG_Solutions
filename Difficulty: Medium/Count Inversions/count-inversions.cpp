//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
     void merge(vector<int> &arr,long long s,long long e, long long &ans)
{
  long long mid=s+(e-s)/2;
  long long l1=mid-s+1;
  long long l2=e-mid;
  
  long long *a1=new long long[l1];
  long long *a2=new long long[l2];
  
  long long k=s;
  for(long long i=0;i<l1;i++) 
  a1[i]=arr[k++];
  
  k=mid+1;
  for(long long i=0;i<l2;i++) 
  a2[i]=arr[k++];
  
  long long i=0,j=0;
  k=s;
  
  while(i<l1 && j<l2) 
  {
    if(a1[i]<=a2[j]) 
    arr[k++]=a1[i++];
    else
   {
   ans=ans+l1-i;
   arr[k++]=a2[j++];
   }
    
  }
  while(i<l1)
  {
   arr[k++]=a1[i++];
  }
  while(j<l2)
  arr[k++]=a2[j++];
  
  delete []a1;
  delete []a2;
  
}

void mergesort(vector<int> &arr,long long s, long long e,long long & ans)
{
 if(s>=e) return;
 long long mid=s+(e-s)/2;
  mergesort(arr,s, mid, ans);
  mergesort(arr, mid+1, e, ans);
  merge(arr,s,e,ans);
}

    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int N=arr.size();
        long long ans=0;
        mergesort(arr,0,N-1,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends