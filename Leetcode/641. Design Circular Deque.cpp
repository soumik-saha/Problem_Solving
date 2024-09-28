class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
class MyCircularDeque {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int curr=0;
    int n;
    MyCircularDeque(int k) {
        this->n = k;
    }
    
    bool insertFront(int value) {
        if(curr>=n) return false;
        Node* node = new Node(value);
        if(curr==0) {
            head = node;
            tail = node;
            node->next = head;
        }
        else {
            node->next = head;
            head = node;
            tail->next = head;
        }
        curr++;
        return true;
    }
    
    bool insertLast(int value) {
        if(curr>=n) return false;
        Node* node = new Node(value);
        if(curr==0) {
            head = node;
            tail = node;
            node->next = head;
        }
        else {
            tail->next = node;
            tail = node;
            tail->next = head;
        }
        curr++;
        return true;
    }
    
    bool deleteFront() {
        if(curr==0) return false;
        Node* temp = head;
        if(curr==1) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            tail->next = head;
        }
        delete(temp);
        curr--;
        return true;
    }
    
    bool deleteLast() {
        if(curr==0) return false;
        if(curr==1) {
            delete head;
            head = tail = NULL;
        }
        else {
            Node* t = head;
            while(t->next != tail) {
                t = t->next;
            }
            delete(tail);
            tail = t;
            tail->next = head;
        }
        curr--;
        return true;
    }
    
    int getFront() {
        return head == NULL ? -1 : head->val;
    }
    
    int getRear() {
        return tail == NULL ? -1 : tail->val;
    }
    
    bool isEmpty() {
        return curr == 0;
    }
    
    bool isFull() {
        return curr == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
