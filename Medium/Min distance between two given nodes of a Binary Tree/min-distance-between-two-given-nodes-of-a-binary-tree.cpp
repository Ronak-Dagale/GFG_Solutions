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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* parent(Node* root, int a,map<Node*,Node*>&mp)
    {
        Node *ans;
        if(root->data==a)
        ans=root;
        
        mp[root]=NULL;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            Node *front=q.front();
            q.pop();
            
            if(front->data==a)
            ans=front;
            
            
            if(front->left)
            {
                q.push(front->left);
                mp[front->left]=front;
            }
            if(front->right)
            {
                q.push(front->right);
                mp[front->right]=front;
            }
        }
        return ans;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        map<Node*,Node*>mp;
        Node*an=parent(root,a,mp);
        map<Node*,bool>vis;
        queue<Node*>q;
        q.push(an);
        vis[an]=1;
        int ans=0;
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                Node *front=q.front();
                q.pop();
                if(front->data==b)
                return ans;
                
                if(front->left && vis[front->left]==0)
                {
                    q.push(front->left);
                    vis[front->left]=1;
                }
                
                if(front->right && vis[front->right]==0)
                {
                      q.push(front->right);
                      vis[front->right]=1;
                }
              
                if(mp[front] && vis[mp[front]]==0)
                {
                   q.push(mp[front]);
                   vis[mp[front]]=1;
                }
                
            }
            ans++;
        }
        return ans;
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
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends