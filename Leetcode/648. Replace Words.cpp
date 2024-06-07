class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        string ans = "";

        unordered_set<string> st(dictionary.begin(), dictionary.end());

        for(int i=0; i<n; i++) {
            int start = i;
            string smaller = "";

            while(i<n && sentence[i]!=' ') {
                smaller += sentence[i];
                if(st.find(smaller)!=st.end()) {
                    break;
                }
                i++;
            }

            while(i<n && sentence[i]!=' ') {
                i++;
            }

            if(ans=="") {
                ans += smaller;
            }
            else {
                ans += " " + smaller;
            }
        }

        return ans;
    }
};
