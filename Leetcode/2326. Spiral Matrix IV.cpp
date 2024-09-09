/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int dir = 0;
        int p = 0, q = 0;

        while(head) {
            
            dir = dir%4;
            cout<<dir<<endl;

            switch(dir) {
                case 0:
                    for(int i=q; i<n && head; i++) {
                        mat[p][i] = head->val;
                        head = head->next;
                    }
                    dir++;
                    p++;
                    break;
                case 1:
                    for(int i=p; i<m && head; i++) {
                        mat[i][n-1] = head->val;
                        head = head->next;
                    }
                    dir++;
                    n--;
                    break;
                case 2:
                    for(int i=n-1; i>=q && head; i--) {
                        mat[m-1][i] = head->val;
                        head = head->next;
                    }
                    dir++;
                    m--;
                    break;
                case 3:
                    for(int i=m-1; i>=p && head; i--) {
                        mat[i][q] = head->val;
                        head = head->next;
                    }
                    dir++;
                    q++;
                    break;
            }
        }

        return mat;
    }
};
