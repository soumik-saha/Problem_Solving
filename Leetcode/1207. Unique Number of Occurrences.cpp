class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>chonk;
        for(int i=0; i<arr.size(); i++){
            chonk[arr[i]]++;
        }
        for(auto it : chonk){
            int cnt=0;
            for(auto it2 : chonk){
                if(it.second == it2.second){
                    cnt++;
                }
                if(cnt>1){
                    return false;
                }
            }
        }
        return true;
    }
};
