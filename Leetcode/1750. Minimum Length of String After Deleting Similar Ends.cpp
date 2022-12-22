class Solution {
public:
    int minimumLength(string s) {
        int ptr1 = 0, ptr2 = s.size()-1, res;
        while(ptr1<ptr2 && s[ptr1]==s[ptr2]){
            auto ch = s[ptr1];
            while(ptr1<=ptr2 && s[ptr1]==ch){
                ptr1++;
            }
            while(ptr1<ptr2 && s[ptr2]==ch){
                ptr2--;
            }
        }
        res = ptr2-ptr1+1;
        return res;
    }
};
