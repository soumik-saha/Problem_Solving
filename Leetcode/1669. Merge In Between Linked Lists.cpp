class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* anode;
        ListNode* bnode;

        for(int i=0; i<b+1 && temp; i++, temp = temp->next) {
            if(i==a-1) {
                anode = temp;
            }
            if(i==b) {
                bnode = temp->next;
            }
        }
        anode->next  = list2;
        temp = list2;
        while(temp && temp->next) {
            temp = temp->next;
        }
        temp->next = bnode;
        return list1;
    }
};
