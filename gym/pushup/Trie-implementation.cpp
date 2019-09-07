// TODO
struct TrieNode{
    TrieNode *childrens[26];
    bool isleaf;
};

class Trie {
private:
    const int ALPHABET_SIZE = 26;
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    TrieNode *newTrieNode(){
        TrieNode *root = new TrieNode;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            root->childrens[i] = nullptr;
        root->isleaf = false;
        return root;
    }

    Trie() {
        TrieNode *root = newTrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < word.length(); i++){
            if (!pCrawl->childrens[word[i]-97])
                pCrawl->childrens[word[i]-97] = newTrieNode();
            pCrawl = pCrawl->childrens[word[i]-97];
        }
        pCrawl->isleaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < word.length();i++){
            if (!pCrawl->childrens[word[i]-97]) return false;
        }
        if (pCrawl->isleaf) return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < prefix.length();i++){
            if (!pCrawl->childrens[prefix[i]-97]) return false;
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
