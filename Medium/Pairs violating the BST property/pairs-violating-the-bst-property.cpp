//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

    /*You are required to complete below function */
    int ans=0;
    void merge(vector<int>&arr,int s,int mid,int e)
    {
        vector<int>temp1;
        vector<int>temp2;
        
        for(int i=s;i<=mid;i++)
        temp1.push_back(arr[i]);
        
        for(int i=mid+1;i<=e;i++)
        temp2.push_back(arr[i]);
        
        int i=0,j=0,k=s;
        
        while(i<temp1.size() || j<temp2.size())
        {
            if(i<temp1.size() && j<temp2.size())
            {
                if(temp1[i]<=temp2[j])
                {
                    arr[k]=temp1[i];
                    i++;
                    k++;
                }
                else
                {
                    ans+=(temp1.size()-i);
                    arr[k]=temp2[j];
                    j++;
                    k++;
                    
                }
            }
            else if(i<temp1.size())
            {
                arr[k]=temp1[i];
                k++;
                i++;
            }
            else
            {
                arr[k]=temp2[j];
                k++;
                j++;
            }
        }
    }
    
    void mergesort(vector<int>&arr,int s,int e)
    {
        if(s>=e) return;
        
        int mid=s+(e-s)/2;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        
        merge(arr,s,mid,e);
    }
    void inorder(Node*root,vector<int>&arr)
    {
        if(root==NULL) return;
        
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        
        vector<int>arr;
        inorder(root,arr);
        mergesort(arr,0,n-1);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends