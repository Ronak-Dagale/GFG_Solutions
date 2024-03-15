//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    Node *reverse(Node *head)
    {
        if(head==NULL) return NULL;
        
        Node*ne,*curr,*prev;
        prev=NULL;
        curr=head;
        
        while(curr)
        {
          ne=curr->next;
          curr->next=prev;
          prev=curr;
          curr=ne;
        }
        return prev;
    }
    void sort(Node **head)
    {
         // Code here
         Node *odd=new Node(-1);
         Node*oddtail=odd;
         
         Node *even=new Node(-1);
         Node*eventail=even;
         
         int cnt=0;
         Node*temp=*head;
         while(temp!=NULL)
         {
             if(cnt&1)
             {
                oddtail->next=temp;
                oddtail=temp;
             }
             else
             {
               eventail->next=temp;
               eventail=temp;
             }
             cnt++;
             temp=temp->next;
              oddtail->next=NULL;
              eventail->next=NULL;
         }
        
        
          Node *oddrev=reverse(odd->next);
          eventail->next=oddrev;
         
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends