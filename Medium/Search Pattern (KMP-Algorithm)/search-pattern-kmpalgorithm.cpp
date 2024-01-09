//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int>ans;
            
            string cmp="";
            for(int i=0;i<pat.size();i++)
            {
                cmp.push_back(txt[i]);
            }
            
            if(cmp==pat)
            ans.push_back(1);
            
            int j=1;
            
            for(int i=pat.size();i<txt.size();i++)
            {
                int k=pat.size();
                if(txt[j]==pat[0])
                {
                    string temp(txt.begin()+j,txt.begin()+i+1);
                     j++;
                if(temp==pat)ans.push_back(j);
                }
                else
                j++;
                
               
               
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends