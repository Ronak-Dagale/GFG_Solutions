class Solution {
  public:
  struct TrieNode{
      TrieNode* child[26];
      TrieNode(){
          for(int i=0;i<26;i++){
              child[i]=NULL;
          }
      }
  };
    int countSubs(string& s) {
        // code here
        TrieNode*root=new TrieNode();
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            TrieNode*curr=root;
            for(int j=i;j<s.size();j++){
                int req=s[j]-'a';
                if(curr->child[req]==NULL){
                    ans++;
                    curr->child[req]=new TrieNode();
                }
                curr=curr->child[req];
            }
        }
        return ans;
    }
};