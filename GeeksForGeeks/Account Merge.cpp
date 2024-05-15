class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int index = 0;
        vector<vector<string>> result;

        // Traverse through each account
        for (const auto& account : accounts) {
            const string& name = account[0];
            for (int i = 1; i < account.size(); i++) {
                const string& email = account[i];
                if (emailToIndex.find(email) == emailToIndex.end()) {
                    emailToIndex[email] = index++;
                    emailToName[email] = name;
                }
            }
        }

        // Union-Find
        vector<int> parent(index);
        for (int i = 0; i < index; i++) {
            parent[i] = i;
        }

        for (const auto& account : accounts) {
            const string& firstEmail = account[1];
            int firstIndex = emailToIndex[firstEmail];
            for (int i = 2; i < account.size(); i++) {
                const string& nextEmail = account[i];
                int nextIndex = emailToIndex[nextEmail];
                int root1 = find(parent, firstIndex);
                int root2 = find(parent, nextIndex);
                if (root1 != root2) {
                    parent[root2] = root1;
                }
            }
        }

        // Group emails by their root
        unordered_map<int, vector<string>> tempResult;
        for (const auto& entry : emailToIndex) {
            const string& email = entry.first;
            int index = find(parent, entry.second);
            tempResult[index].push_back(email);
        }

        // Construct the final result
        for (const auto& entry : tempResult) {
            const vector<string>& emails = entry.second;
            vector<string> account;
            account.push_back(emailToName[emails[0]]);
            for (const auto& email : emails) {
                account.push_back(email);
            }
            sort(account.begin() + 1, account.end()); // Sort emails except for the name
            result.push_back(account);
        }

        return result;
    }

private:
    int find(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }
};
