//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
Node* rev(Node*node)
{
    Node *prev=NULL;
    Node*curr=node;
    Node*ne=NULL;
    
    while(curr!=NULL)
    {
      ne=curr->next;
       curr->next=prev;
       prev=curr;
       curr=ne;
    }
    return prev;
}
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
         while(head1 and head1->data==0) head1 = head1->next;
        while(head2 and head2->data==0) head2 = head2->next;
        stack<int>s1,s2,s3;
        Node*temp1=head1,*temp2=head2;
        
        Node *ans=new Node(-1);
        Node *anstail=ans;
        
        while(temp1!=NULL)
        {
            s1.push(temp1->data);
            temp1=temp1->next;
        }
        
        while(temp2!=NULL)
        {
            s2.push(temp2->data);
            temp2=temp2->next;
        }
        temp1=head1;
        temp2=head2;
        if(s2.size()>s1.size())
        {
            s3=s1;
            s1=s2;
            s2=s3;
        }
        else if(s1.size()==s2.size())
        {
            if(!temp1 and !temp2) return new Node(0);
            while(temp1->data==temp2->data){
                temp1 = temp1->next;
                temp2 = temp2->next;
                if(!temp1 or !temp2) return new Node(0);
            }
            if(temp2->data > temp1->data) swap(s1,s2);
        }
        int borr=0;
        while(!s1.empty() || !s2.empty())
        {
            if(!s1.empty() && !s2.empty())
            {
              int a=s1.top();
              int b=s2.top();
              int res=0;
              s1.pop();
              s2.pop();
              if(borr==1)
              {
                  b++;
              }
              
              if(a>=b)
              {
                borr=0;
                res=a-b;
              }
              else
              {
                  borr=1;
                  res=(a-b)+10;
              }
              
              Node *newnode=new Node(res);
              anstail->next=newnode;
              anstail=newnode;
            }
            else if(!s1.empty())
            {
               int a=s1.top();
               int b=0;
               int res=0;
               s1.pop();
               
               if(borr==1)
               b++;
               
               if(a>=b)
               {
                   borr=0;
                   res=a-b;
               }
               else
               {
                   borr=1;
                   res=(a-b)+10;
               }
                Node *newnode=new Node(res);
              anstail->next=newnode;
              anstail=newnode;
            }
            else if(!s2.empty())
            {
               int a=0;
               int b=s2.top();
               int res=0;
               
               s2.pop();
               
               if(borr==1)
               b++;
               
               if(a>=b)
               {
                   borr=0;
                   res=a-b;
               }
               else
               {
                   borr=1;
                   res=(a-b)+10;
               }
               Node *newnode=new Node(res);
              anstail->next=newnode;
              anstail=newnode;
            }
        }
        if(borr==1)
        {
             Node *newnode=new Node(1);
              anstail->next=newnode;
              anstail=newnode;
        }
        
       Node*final= rev(ans->next);
       while(final->next!=NULL && final->data==0)final=final->next;
       return final;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends