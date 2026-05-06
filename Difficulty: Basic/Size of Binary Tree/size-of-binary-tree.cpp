/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if(!root) return 0;
        
        int l=getSize(root->left);
        int r=getSize(root->right);
        return l+r+1;
    }
};