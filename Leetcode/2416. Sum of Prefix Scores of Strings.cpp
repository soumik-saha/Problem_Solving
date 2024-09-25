class TrieNode {
public:
    int count;
    unordered_map<char, TrieNode*> children;

    TrieNode(): count(0) {}
};
class Trie {
public: 
    TrieNode* root;

    Trie() {
        root = new TrieNode;
    }

    void insert(string& word) {
        TrieNode* node = root;
        for(char c:word) {
            if(!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;
        }
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        for(auto word:words) {
            trie.insert(word);
        } 

        vector<int> ans;

        for(auto word:words) {
            int res = 0;
            TrieNode* node = trie.root;
            for(char c:word) {
                node = node->children[c];
                res += node->count;
            }
            ans.push_back(res);
        } 

        return ans;
    }
};
