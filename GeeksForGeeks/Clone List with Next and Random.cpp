class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        if (!head) return nullptr;

        // Step 1: Insert new nodes after the original nodes
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Copy the random pointers
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the new list from the interwoven list
        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;
        while (curr) {
            curr->next = curr->next->next;
            if (newCurr->next) {
                newCurr->next = newCurr->next->next;
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
