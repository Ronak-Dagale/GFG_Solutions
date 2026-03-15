/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:

    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            
            mp[front.second].push_back(front.first->data);
            if(front.first->left)
            q.push(make_pair(front.first->left,front.second-1));
            
            if(front.first->right)
            q.push(make_pair(front.first->right,front.second+1));
        }
        
        for(auto m:mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};