//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:

   void Rev(vector<int>&v,int k){

       int i=0;int j=k-1;

       while(i<j){

           swap(v[i],v[j]);

           i++;

           j--;

       }

       i=k;

       j=v.size()-1;

       while(i<j){

           swap(v[i],v[j]);

           i++;

           j--;

       }

       

   }

    Node *reverse(Node *head, int k)

    {

        // code here

        vector<int>v;

        Node *temp=head;

        while(temp!=NULL){

            v.push_back(temp->data);

            temp=temp->next;

        }

        Rev(v,k);

        temp=head;

        int i=0;

        while(temp!=NULL){

            temp->data=v[i];

            i++;

            temp=temp->next;

        }

        return head;

    }


};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends
