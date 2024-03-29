/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> visited;

public:
    Node* copyRandomList(Node* head) {
        if(!head)
           return NULL;

        if(visited.find(head)!=visited.end())
            return visited[head];
        
        Node* node = new Node(head->val, NULL, NULL);
        visited[head] = node;

        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);

        return node;
    }
};
