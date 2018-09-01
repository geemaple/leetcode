class TrieNode {
public:
    ~TrieNode(){
        for(auto it: children)
        {
            delete it.second;
        }
    }
    
    unordered_map<char, TrieNode *> children;
    bool isWord = false;
};

class WordDictionary {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    ~WordDictionary() {
        delete root;
    }
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        for (char c: word)
        {
            if (node->children.count(c) == 0)
            {
                node->children[c] = new TrieNode();
            }
            
            node = node->children[c];
        }
        
        node->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_dfs(root, word, 0);
    }
    
    bool search_dfs(TrieNode* node, string word, int index)
    {
        if (node == NULL){
            return false;
        }
        
        if (index >= word.size())
        {
            return node->isWord;
        }
        
        char c = word[index];
        
        if (c != '.')
        {
            node = (node->children.count(c) == 0) ? NULL : node->children[c];
            return search_dfs(node, word, index + 1);
        }
        else
        {
            for (auto it: node->children)
            {
                bool result = search_dfs(it.second, word, index + 1);
                if (result)
                {
                    return result;
                }
            }
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */