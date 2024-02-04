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
    Node* subLinkedList(Node* head1, Node* head2) {
        long long num1 = 0, num2 = 0;
        while(head1) {
            num1 = num1*10 + head1->data;
            head1 = head1->next;
        }
        while(head2) {
            num2 = num2*10 + head2->data;
            head2 = head2->next;
        }
        long long sub = abs(num1-num2);
        if(sub==0) {
            Node* temp = new Node(0);
            return temp;
        }
        long long rev_sub = 0;
        long long n = 0;
        while(sub>0) {
            rev_sub = rev_sub*10 + sub%10;
            sub /= 10;
            n++;
        }
        Node* list = nullptr;
        Node* start = nullptr;
        long long cn = 0;
        while(rev_sub>0) {
            Node* temp = new Node(rev_sub%10);
            rev_sub /= 10;
            if(!list) {
                list = temp;
                start = list;
            }
            else {
                list->next = temp;
                list = list->next;
            }
            cn++;
        }
        while(cn<n) {
            list->next = new Node(0);
            list = list->next;
            cn++;
        }
        
        return start;
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
