//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        long long ans=0;
        int last=2147483647;
        bool neg=0;
        
        
        int i=0;
         while(s[i]!='\0' && s[i]==' ')
            i++;
            
            if(s[i]=='-')
            {
                neg=1;
                last=-2147483648;
                i++;
            }
          
        while(s[i]!='\0')
        {
          if(s[i]>='0' && s[i]<='9')
          {
             ans=ans*10+(s[i]-'0');
             if(neg && -(ans)<last)
             {
               
                 ans=last;
                 break;
             }
             else if(!neg && ans>last)
             {
                 ans=last;
                 break;
             }
             
          }
          else
          break;
          
          i++;
        }
        
        if(neg)
        return -ans;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends