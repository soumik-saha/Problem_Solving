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
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        Node* p1 = reverse(num1);
        Node* p2 = reverse(num2);
        
        Node* preHead = new Node(0);
        Node* temp = preHead;
        
        int carry = 0;
        
        while(p1 or p2 or carry) {
            int sum = 0;
            
            if(carry)   sum += carry;
            
            if(p1) {
                 sum += p1->data;
                 p1 = p1->next;
            }
            
            if(p2) {
                sum += p2->data;
                p2 = p2->next;
            }
            
            temp->next = new Node(sum%10);
            temp = temp->next;
            
            carry = sum/10;
        }
        
        temp->next = NULL;
        Node* head = reverse(preHead->next);
        
        
        while(head && head->next && head->data==0) {
            head = head->next;
        }
        
        return head;
    }
    Node* reverse(Node* head) {
        if(!head || !head->next) {
            return head;
        }
        
        Node* prev = NULL, *curr = head;
        
        while(curr) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
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
