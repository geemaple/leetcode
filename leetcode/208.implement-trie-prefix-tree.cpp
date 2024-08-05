class TrieNode {
public:
    ~TrieNode(){
        for (auto it : children)
        {
            delete it.second; //:Fixme
        }
    }

    unordered_map<char, TrieNode *> children;
    bool isWord;
};

class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    ~Trie() {
        delete root;
    }

    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        
        for(char c : word)
        {
            if (node->children.count(c) == 0)
            {
                node->children[c] = new TrieNode();
            }

            node = node->children[c];
        }

        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        
        for(char c : word){
            if (node->children.count(c) == 0)
            {
                return false;
            }
            node = node->children[c];
        }

        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        
        for(char c : prefix){
            if (node->children.count(c) == 0)
            {
                return false;
            }
            node = node->children[c];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
