//  Tag: String, Depth-First Search, Design, Trie
//  Time: O(26^k * N)
//  Space: O(LN)
//  Ref: -
//  Note: -

//  Design a data structure that supports adding new words and finding if a string matches any previously added string.
//  Implement the WordDictionary class:
//  
//  WordDictionary() Initializes the object.
//  void addWord(word) Adds word to the data structure, it can be matched later.
//  bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
//  
//   
//  Example:
//  
//  Input
//  ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
//  [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
//  Output
//  [null,null,null,null,false,true,true,true]
//  
//  Explanation
//  WordDictionary wordDictionary = new WordDictionary();
//  wordDictionary.addWord("bad");
//  wordDictionary.addWord("dad");
//  wordDictionary.addWord("mad");
//  wordDictionary.search("pad"); // return False
//  wordDictionary.search("bad"); // return True
//  wordDictionary.search(".ad"); // return True
//  wordDictionary.search("b.."); // return True
//  
//   
//  Constraints:
//  
//  1 <= word.length <= 25
//  word in addWord consists of lowercase English letters.
//  word in search consist of '.' or lowercase English letters.
//  There will be at most 2 dots in word for search queries.
//  At most 104 calls will be made to addWord and search.
//  
//  

class TrieNode {
public:
    vector<TrieNode *> children;
    bool is_word;
    TrieNode() : children(26, nullptr), is_word(false){}

    ~TrieNode() {
        for (auto p : children) {
            delete p;
        }
    }
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() {
        delete root;
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        for (auto x: word) {
            if (!cur->children[x - 'a']) {
                cur->children[x - 'a'] = new TrieNode();
            }
            cur = cur->children[x - 'a'];
        }
        cur->is_word = true;
    }
    
    bool search(string word) {
        return search_word(root, word, 0);
    }

    bool search_word(TrieNode *cur, string word, int i) {
        if (i == word.size()) {
            return cur->is_word;
        }

        char x = word[i];
        if (x != '.' && cur->children[x - 'a']) {
            return search_word(cur->children[x - 'a'], word, i + 1);
        }

        if (word[i] == '.') {
            for (auto next: cur->children) {
                if (next && search_word(next, word, i + 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */