/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            auto tmp=q.front();
            q.pop();
            
            if(mp[tmp.second]==0){
                mp[tmp.second]=tmp.first->data;
            }
            
            if(tmp.first->left){
                q.push(make_pair(tmp.first->left,tmp.second-1));
            }
            if(tmp.first->right){
                q.push(make_pair(tmp.first->right,tmp.second+1));
            }
        }
        
        for(auto a:mp){
            ans.push_back(a.second);
        }
        return ans;
    }
};