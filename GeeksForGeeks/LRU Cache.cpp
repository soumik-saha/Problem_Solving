//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    
    Node(int key, int data) {
        this->key = key; 
        this->val = data;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
  private:
  public:
    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        this->size = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(mp.find(key)==mp.end()) {
            return -1;
        }
        else {
            auto ptr = mp[key];
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            
            ptr->prev = tail->prev;
            ptr->next = tail;
            tail->prev->next = ptr;
            tail->prev = ptr;
            
            return ptr->val;
        }
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(mp.find(key)!=mp.end()) {
            auto node = mp[key];
            node->val = value;
            
            node->prev->next = node->next;
            node->next->prev = node->prev;
            
            node->next = tail;
            node->prev = tail->prev;
            tail->prev->next = node;
            tail->prev = node;
        }
        else {
            if(mp.size()==size) {
                auto node = head->next;
                head->next = node->next;
                node->next->prev = head;
                mp.erase(node->key);
            }
            
            Node* newNode = new Node(key, value);
            
            newNode->next = tail;
            newNode->prev = tail->prev;
            tail->prev->next = newNode;
            tail->prev = newNode;
            
            mp[key] = newNode;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
