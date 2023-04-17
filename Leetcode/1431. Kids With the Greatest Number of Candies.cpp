class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int>dummy=candies;
        sort(dummy.begin(), dummy.end(), greater<int>());
        int maximum = dummy[0], n=candies.size();
        vector<bool>res;
        for(int i=0; i<n; i++){
            if(maximum<=candies[i]+extraCandies)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};
