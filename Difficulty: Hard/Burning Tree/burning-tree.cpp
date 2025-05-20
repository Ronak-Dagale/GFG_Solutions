//User function Template for C++

/*
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
class Solution {
  public:
  Node *createmap(map<Node*,Node*>&nodetoparent,Node *root,int target)
  {
      Node *node=NULL;
      queue<Node*>q;
      q.push(root);
      
      while(!q.empty())
      {
          Node *front=q.front();
          q.pop();
          
          if(front->data==target)
          {
              node=front;
          }
          
          if(front->left)
          {
              nodetoparent[front->left]=front;
              q.push(front->left);
          }
          if(front->right)
          {
              nodetoparent[front->right]=front;
              q.push(front->right);
          }
      }
      return node;
  }
  
  int burntree(map<Node*,Node*>&nodetoparent,Node *root)
  {
      map<Node*,bool>visited;
      int ans=0;
      queue<Node*>q;
      q.push(root);
      visited[root]=1;
      
      while(!q.empty())
      {
         int size=q.size();
         bool flag=0;
         
         while(size)
         {
             size--;
             Node*front=q.front();
             q.pop();
             
             if(front->left && !visited[front->left])
             {
                 flag=1;
                 q.push(front->left);
                 visited[front->left]=1;
             }
             if(front->right && !visited[front->right])
             {
                 flag=1;
                 q.push(front->right);
                 visited[front->right]=1;
             }
             if(nodetoparent[front] && !visited[nodetoparent[front]])
             {
                 flag=1;
                 q.push(nodetoparent[front]);
                 visited[nodetoparent[front]]=1;
             }
         }
         if(flag)ans++;
      }
      return ans;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>nodetoparent;
        nodetoparent[root]=NULL;
        Node *node=createmap(nodetoparent,root,target);
        
        int ans=burntree(nodetoparent,node);
        return ans;
    }
};

