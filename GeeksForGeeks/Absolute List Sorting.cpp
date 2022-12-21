/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    Node* sortList(Node* head)
    {
        // Your Code Here
        Node* prev = head;
        Node* curr = head->next;
        
        while(curr != NULL){
            if(curr->data <prev->data){
                prev->next = curr->next;
                curr->next = head;
                head = curr;
                curr = prev;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};
