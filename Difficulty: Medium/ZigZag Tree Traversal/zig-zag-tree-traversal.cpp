/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
   void solve(Node* root,map<int,vector<int>>&mp,int le)
    {
        if(!root)
        return;
        
        mp[le].push_back(root->data);
        solve(root->left,mp,le+1);
        solve(root->right,mp,le+1);
    }
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>ans;
    	map<int,vector<int>>mp;
    	solve(root,mp,0);
    	
    	bool flag=1;
    	for(auto v:mp){
    	    if(flag)
    	    {
    	        for(auto x:v.second)
    	        ans.push_back(x);
    	    }
    	    else
    	    {
    	        for(int i=v.second.size()-1;i>=0;i--)
    	        {
    	            ans.push_back(v.second[i]);
    	        }
    	    }
    	    flag=!flag;
    	}
    	return ans;
    }
};