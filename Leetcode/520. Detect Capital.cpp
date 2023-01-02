class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1){
            return true;
        }
        // Case - 1 
        if(isupper(word[0]) && isupper(word[1])){
            for(int i=2; i<word.size(); i++){
                if(islower(word[i]))   
                    return false;
            }
        }
        // Case - 2 && Case - 3
        else{
            for(int i=1; i<word.size(); i++){
                if(isupper(word[i]))
                    return false;
            }
        }
        // If upper cases are not true;
        return true;
    }
};
