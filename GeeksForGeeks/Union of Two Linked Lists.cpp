//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
          vector<int>v;
          
          auto t=head1;
          
          while(t!=NULL)
          {
              v.push_back(t->data);
              if(t->next)
              t=t->next;
              else
              {
                  t->next=head2;
                  t=t->next;
                  break;
              }
          }
          
          while(t)
          {
               v.push_back(t->data);
                t=t->next;
          }
          
          t=head1;
          sort(v.begin(),v.end());
          t->data=v[0];
          
         for(int i=1;i<v.size();i++)
          {
              if(v[i]!=v[i-1])
              {
                   t=t->next;
                  t->data=v[i];
                 
              }
          }
          
           t->next=NULL;
          
          return head1;
    }
};

//{ Driver Code Starts.

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


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
