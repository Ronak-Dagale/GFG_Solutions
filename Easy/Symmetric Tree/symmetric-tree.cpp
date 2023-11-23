//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool chk(vector<int>v)
    {
        int i=0,j=v.size()-1;
        while(i<j)
        {
            if(v[i]!=v[j])
            return 0;
            
            i++;
            j--;
        }
        return 1;
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL)
	    return 1;
	    
	    queue<Node*>q;
	    q.push(root);
	    
	    while(!q.empty())
	    {
	        int size=q.size();
	        vector<int>v;
	        while(size--)
	        {
	            Node *front=q.front();
	            q.pop();
	            
	            if(front->left!=NULL)
	            {
	                q.push(front->left);
	                v.push_back(front->left->data);
	            }
	            else
	            {
	               v.push_back(-1);
	            }
	            
	            if(front->right!=NULL)
	            {
	                q.push(front->right);
	                v.push_back(front->right->data);
	            }
	            else
	            {
	                 v.push_back(-1);
	            }
	        }
	        if(!chk(v))
	        return 0;
	    }
	    return 1;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        if(ob.isSymmetric(root)){
            cout<<"True"<<endl;
        }
        else{ 
            cout<<"False"<<endl;
        }
    }
    return 0;
}

// } Driver Code Ends