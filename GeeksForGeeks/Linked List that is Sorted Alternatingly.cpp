
/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
        Node* n1 = *head;
        Node* n2 = (*head)->next;
        while(n2 || n1->next) {
            if(n1->data>n2->data) {
                swap(n1->data, n2->data);
            }
            n2 = n2->next;
            if(!n2) {
                n1 = n1->next;
                n2 = n1->next;
            }
        }
    }
};
