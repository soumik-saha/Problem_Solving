//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
         Node* temp = head;
    vector<int> v;
    while (temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int lo = 0, hi = v.size() - 1;
    while (lo <= hi) {
        int temp = v[lo];
        v[lo] = v[hi] - v[lo];
        v[hi] = temp;
        lo++;
        hi--;
    }
    Node* nw = new Node(v[0]);
    Node* hd = nw;
    for (int i = 1; i < v.size(); i++) {
        Node* temp_nw = new Node(v[i]);
        hd->next = temp_nw;
        hd = temp_nw;
    }
    hd->next = NULL; 
    return nw; 
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends
