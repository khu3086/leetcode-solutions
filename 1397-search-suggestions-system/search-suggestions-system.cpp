class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        vector<string> words;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root;

    void insertIntoTrie(string &s) {
        TrieNode* curr = root;

        for (char ch : s) {
            int c = ch - 'a';

            if (!curr->child[c])
                curr->child[c] = new TrieNode();

            curr = curr->child[c];

            if (curr->words.size() < 3)
                curr->words.push_back(s);
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        sort(products.begin(), products.end());

        root = new TrieNode();

        for (auto &s : products)
            insertIntoTrie(s);

        vector<vector<string>> ans;
        TrieNode* curr = root;

        for (char ch : searchWord) {
            if (curr && curr->child[ch - 'a']) {
                curr = curr->child[ch - 'a'];
                ans.push_back(curr->words);
            } else {
                curr = nullptr;
                ans.push_back({});
            }
        }

        return ans;
    }
};