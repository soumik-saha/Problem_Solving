//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (!head) return NULL;
    
        vector<int> v;
        Node* temp = head;
        do {
            v.push_back(temp->data);
            temp = temp->next;
        } while (temp != head);
    
        std::reverse(v.begin(), v.end());
    
        temp = head;
        int i = 0;
        do {
            temp->data = v[i++];
            temp = temp->next;
        } while (temp != head);
    
        return head;
    }


    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if (!head) return NULL;
    
        Node* current = head;
        Node* prev = nullptr;
    
        do {
            if (current->data == key) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    Node* tail = head;
                    while (tail->next != head) {
                        tail = tail->next;
                    }
                    tail->next = current->next; 
                    head = current->next; 
                }
                delete current;
                return head;
            }
            prev = current;
            current = current->next;
        } while (current != head);
    
        return head;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
