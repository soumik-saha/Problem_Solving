class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        Node* temp = head;
        
        // Make sure the first element is vowel
        bool hasVowel = false;
        while(temp) {
            if(isVowel(temp->data)) {
                hasVowel = true;
                break;
            }
            temp = temp->next;
        }
        if(!hasVowel) {
            return head;
        }
        temp = head;
        Node* preTemp = NULL;
        while(hasVowel &&!isVowel(head->data) && temp) {
            if(isVowel(temp->data)) {
                preTemp->next = temp->next;
                temp->next = head;
                head = temp;
                break;
            }
            preTemp = temp;
            temp = temp->next;
        }
        
        // Now make changes to get the required sequence
        Node* vowel = head;
        temp = vowel->next;
        preTemp = vowel;
        
        while(vowel && isVowel(vowel->data) && temp) {
            if(isVowel(vowel->next->data)) {
                vowel = vowel->next;
                preTemp = vowel;
                temp = vowel->next;
                continue;
            }
            if(isVowel(temp->data)) {
                Node* t = vowel->next;
                preTemp->next = temp->next;
                vowel->next = temp;
                temp->next = t;
                vowel = vowel->next;
                temp = preTemp->next;
            }
            else {
                preTemp = temp;
                temp = temp->next;
            }
        }
        
        return head;
    }
    bool isVowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            return true;
        }
        return false;
    }
};
