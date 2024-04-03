//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
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
//User function Template for C++

/*// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};*/


class Solution
{
    public:
    
    /*You are required to complete below function */
    pair<Node*,Node*> solve(Node *root, int &k,int x, int y,int &ans)
    {
        if(!root) return {NULL,NULL};
        
        pair<Node*,Node*>l=solve(root->left,k,x,y,ans);
        pair<Node*,Node*>r=solve(root->right,k,x,y,ans);
        
        Node *p1=NULL;
        Node *p2=NULL;
        
        // if((l.first!=NULL && r.second!=NULL) || (l.first!=NULL && l.second!=NULL) && (r.first!=NULL && l.second!=NULL) && (r.first!=NULL && r.second!=NULL) )
        // {
        //     k--;
        //     if(k==0)
        //     ans=root->data;
        // }
        
        if(l.first!=NULL || r.first!=NULL || root->data==x)
        p1=root;
        
        if(l.second!=NULL || r.second!=NULL || root->data==y )
        p2=root;
        
        if(p1!=NULL && p2!=NULL)
        {
            k--;
            //cout<<p1->data<<" "<<p2->data<<" "<<k<<endl;
            if(k==0)
            ans=root->data;
        }
        return {p1,p2};
        
    }
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        int ans=-1;
        Node*xe=NULL;
        Node*ye=NULL;
        
        pair<Node*,Node*>p=solve(root,k,x,y,ans);
       // cout<<p.first->data<<" "<<p.second->data<<endl;
        return ans;
    }
};



//{ Driver Code Starts.

int main ()
{

	int t;
	cin >> t;
	cin.ignore();

	while (t--)
	{
	
		string inp;
		getline(cin, inp);
		
		int k,x,y;
		cin>>k>>x>>y;
		cin.ignore();

		struct Node* root = buildTree(inp);

        Solution ob;
		int ans = ob.kthCommonAncestor(root,k,x,y);
		cout<<ans<<endl;

	}

	return 0;
}
// } Driver Code Ends