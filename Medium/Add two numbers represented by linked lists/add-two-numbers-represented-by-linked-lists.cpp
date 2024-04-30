//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node*root)
    {
        Node*prev=NULL,*curr=root,*ne;
        while(curr!=NULL)
        {
            ne=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ne;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        Node *t1=reverse(num1);
        Node*t2=reverse(num2);
        
        Node*ans=new Node(-1);
        Node*anstail=ans;
        
        int ca=0;
        while(t1!=NULL || t2!=NULL)
        {
            if(t1!=NULL && t2!=NULL)
            {
               int res=t1->data+t2->data+ca;
               Node *newnode=new Node(res%10);
               ca=(t1->data+t2->data+ca)/10;
               
               anstail->next=newnode;
               anstail=newnode;
               t1=t1->next;
               t2=t2->next;
            }
            else if(t1!=NULL)
            {
                 int res=t1->data+ca;
               Node *newnode=new Node(res%10);
               ca=(t1->data+ca)/10;
               
                anstail->next=newnode;
               anstail=newnode;
               t1=t1->next;
            
            }
            else
            {
                 int res=t2->data+ca;
               Node *newnode=new Node(res%10);
               ca=(t2->data+ca)/10;
               
                anstail->next=newnode;
               anstail=newnode;
               t2=t2->next;
            }
        }
        if(ca)
        {
            Node *newnode=new Node(ca);
             anstail->next=newnode;
               anstail=newnode;
        }
        Node*fans=reverse(ans->next);
        
        while(fans->next!=NULL && fans->data==0)
        fans=fans->next;
        
        return fans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends