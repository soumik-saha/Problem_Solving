class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<string> ans;
        bool updated = true;

        while(updated) {
            updated = false;
            for(int i=0; i<n; i++) {
                bool canBeDone = true;
                for(int j=0; j<ingredients[i].size(); j++) {
                    if(st.find(ingredients[i][j])==st.end()) {
                        canBeDone = false;
                        break;
                    }
                }
                if(canBeDone && st.find(recipes[i])==st.end()) {
                    st.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    updated = true;
                }
            }
        }

        return ans;
    }
};
