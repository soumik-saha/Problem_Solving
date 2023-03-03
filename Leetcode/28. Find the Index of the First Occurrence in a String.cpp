class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size())
            return -1;
    
        int x = 0;
        for(int i=0; i<haystack.size(); i++) {
            if(haystack[i] == needle[0]){
                for(int j=1; j<needle.size(); j++){
                    if(haystack[i+j] != needle[j]){
                        break;
                    }
                    x++;
                }
                if(x==needle.size()-1){
                    return i;
                }
                else{
                    x=0;
                }
            }
        }
        return -1;
    }
};
