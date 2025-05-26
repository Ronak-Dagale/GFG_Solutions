/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       if(!head) 
{
    Node *temp = new Node(data);
    temp->next = temp;
    return temp;
}
       Node *prev=head,*curr=head->next,*ne=NULL;
       
       if(head==NULL)
       {
           return new Node(data);
       }
       else if(data<=head->data)
       {
         Node *newnode=new Node(data);
         newnode->next=head;
         
         curr=head->next;
         prev=head;
         while(curr!=head)
         {
             prev=curr;
             curr=curr->next;
         }
         prev->next=newnode;
         return newnode;
       }
       
       while(curr!=head)
       {
           if(data>=prev->data && data<=curr->data)
           {
               Node *newnode=new Node(data);
               newnode->next=curr;
               prev->next=newnode;
               return head;
           }
           
           prev=curr;
           curr=curr->next;
       }
       
        Node *newnode=new Node(data);
               newnode->next=curr;
          prev->next=newnode;
               return head;
    }
};
