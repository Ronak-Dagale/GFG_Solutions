/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        q.push({root,root->data});
        int ans=0;
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int>leaf;
            
            while(size--)
            {
                auto front=q.front();
                q.pop();
                
                if(front.first->left)
                q.push({front.first->left,front.second+front.first->left->data});
                 if(front.first->right)
                q.push({front.first->right,front.second+front.first->right->data});
                
                if(front.first->left==NULL && front.first->right==NULL)
                leaf.push_back(front.second);
            }
            
            if(leaf.size()>0)
            {
                int maxi=0;
                for(int i=0;i<leaf.size();i++)
                maxi=max(maxi,leaf[i]);
                
                ans=maxi;
            }
        }
        return ans;
    }
};