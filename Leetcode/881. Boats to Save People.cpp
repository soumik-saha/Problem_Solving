class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int res=0;
        int j=people.size()-1;
        for(int i=0; i<=j; i++) {
            if(people[i]+people[j]<=limit){
                j--;
                res++;
            }
            else if(people[i]<=limit){
                res++;
            }
        }
        return res;
    }
};
