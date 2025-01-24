bool detectLoop(Node* head) {
        // your code here
        if(!head->next) return false;
        
        Node* fast = head;
        Node* slow = head->next;
        
        while(fast && slow) {
            if(fast==slow)  return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return true;
    }
