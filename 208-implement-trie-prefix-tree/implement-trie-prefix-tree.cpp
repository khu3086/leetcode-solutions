class Trie {
public:
    struct TrieNode{
        TrieNode* child[26];
        bool isWord;
        TrieNode(){
            for(auto& a: child) a=nullptr;
            isWord=false;
        }
    };
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        int n=word.size();
        TrieNode* curr=root;
        for(int i=0;i<n;i++){
            int chr=word[i]-'a';
            if(curr->child[chr]==nullptr){
                curr->child[chr]=new TrieNode();
            }
            curr=curr->child[chr];
        }
        curr->isWord=true;
    }
    
    bool search(string word) {
        int n=word.size();
        TrieNode* curr=root;
        for(int i=0;i<n;i++){
            int chr=word[i]-'a';
            if(curr->child[chr]==nullptr){
                return false;
            }
            curr=curr->child[chr];
        }
        return curr->isWord;
    }
    
    bool startsWith(string word) {
        int n=word.size();
        TrieNode* curr=root;
        for(int i=0;i<n;i++){
            int chr=word[i]-'a';
            if(curr->child[chr]==nullptr){
                return false;
            }
            curr=curr->child[chr];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */