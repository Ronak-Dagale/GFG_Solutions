//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   class Trienode
   {
       public:
        char data;
        Trienode *child[26];
        bool isend;
        
        Trienode(char ch)
        {
            data=ch;
            
            for(int i=0;i<26;i++)
            child[i]=NULL;
            
            isend=false;
            
        }
   };
   
   class Trie
   {
     public:
       Trienode *root;
       
       Trie()
       {
           root=new Trienode('\0');
       }
       
       void insert(string s)
       {
           Trienode *node=root;
           
           for(int i=0;i<s.size();i++)
           {
               int idx=s[i]-'a';
               
               if(node->child[idx]==NULL)
               {
                   node->child[idx]=new Trienode(s[i]);
                   node=node->child[idx];
               }
               else
               node=node->child[idx];
           }
           node->isend=1;
       }
       
       void findcontact(string temp,Trienode *node,vector<string>&contact)
       {
           if(node->isend) contact.push_back(temp);
           
           for(char c='a';c<='z';c++)
           {
               if(node->child[c-'a']!=NULL)
               {
                   findcontact(temp+c,node->child[c-'a'],contact);
               }
           }
       }
       vector<string> searchcontact(string temp)
       {
           Trienode *node=root;
           
           for(int i=0;i<temp.size();i++)
           {
               int idx=temp[i]-'a';
               
               if(node->child[idx]==NULL)
               return {"0"};
               node=node->child[idx];
           }
           
           vector<string>contact;
           
           findcontact(temp,node,contact);
           
           return contact;
       }
       
   };
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>ans;
        
        Trie tree;
        
        for(int i=0;i<n;i++)
        tree.insert(contact[i]);
        
        string temp="";
        
        
        for(int i=0;i<s.size();i++)
        {
            temp.push_back(s[i]);
            
            vector<string> coll=tree.searchcontact(temp);
            ans.push_back(coll);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends