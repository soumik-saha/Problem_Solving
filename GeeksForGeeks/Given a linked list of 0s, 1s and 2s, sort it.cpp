//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        unordered_map<int, int> mp;
        Node* ptr = head;
        // int n = 0;
        while(ptr!=NULL) {
            // n++;
            mp[ptr->data]++;
            ptr = ptr->next;
        }
        
        Node* start = NULL;
        ptr = NULL;
        for(int i=0; i<mp[0]; i++) {
            // Node* newnode = new Node(0);
            if(ptr) {
                ptr->next = new Node(0);
                ptr = ptr->next;
            }
            if(start==NULL) {
                start = new Node(0);
                ptr = start;
            }
        }
        
        for(int i=0; i<mp[1]; i++) {
            // Node* newnode = new Node(0);
            if(ptr) {
                ptr->next = new Node(1);
                ptr = ptr->next;
            }
            if(start==NULL) {
                start = new Node(1);
                ptr = start;
            }
        }
        
        for(int i=0; i<mp[2]; i++) {
            // Node* newnode = new Node(0);
            if(ptr) {
                ptr->next = new Node(2);
                ptr = ptr->next;
            }
            if(start==NULL) {
                start = new Node(2);
                ptr = start;
            }
        }
        
        return start;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
