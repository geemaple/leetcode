//  Tag: Depth First Search/DFS, Trie
//  Time: O(N * P^5)
//  Space: O(N)
//  Ref: Leetcode-425
//  Note: -

//  Given a set of words **without duplicates**, find all [`word squares`](https://en.wikipedia.org/wiki/Word_square "Word square") you can build from them.
//  
//  A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
//  
//  For example, the word sequence `["ball","area","lead","lady"]` forms a word square because each word reads the same both horizontally and vertically.
//  ```
//  b a l l
//  a r e a
//  l e a d
//  l a d y
//  ```
//  
//  **Example 1:**
//  ```
//  Input:
//  ["area","lead","wall","lady","ball"]
//  Output:
//  [["wall","area","lead","lady"],["ball","area","lead","lady"]]
//  
//  Explanation:
//  The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
//  ```
//  
//  **Example 2:**
//  ```
//  Input:
//  ["abat","baba","atan","atal"]
//  Output:
//   [["baba","abat","baba","atan"],["baba","abat","baba","atal"]]
//  ```
//  
//  - There are at least 1 and at most 1000 words.
//  - All words will have the exact same length.
//  - Word length is at least 1 and at most 5.
//  - Each word contains only lowercase English alphabet `a-z`.

class TrieNode {
public:
    vector<TrieNode *> children;
    bool is_word;
    vector<string> prefix;
    TrieNode(): children(26, nullptr), is_word(false), prefix() {}
    ~TrieNode() {
        for (auto p: children) {
            delete p;
        }
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }

    void add(string word) {
        TrieNode *cur = root;
        for (auto ch: word) {
            if (!cur->children[ch - 'a']) {
                cur->children[ch - 'a'] = new TrieNode();
            }
            
            cur = cur->children[ch - 'a'];
            cur->prefix.push_back(word);
        }
        cur->is_word = true;
    }

    vector<string> prefix(string word) {
        TrieNode *cur = root;
        for (auto ch: word) {
            if (!cur->children[ch - 'a']) {
                return vector<string>{};
            }
            cur = cur->children[ch - 'a'];
        }
        return cur->prefix;
    };

};


class Solution {
public:
    /**
     * @param words: a set of words without duplicates
     * @return: all word squares
     *          we will sort your return value in output
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        // write your code here
        int n = words[0].size();

        Trie tree = Trie();
        for (auto word: words){
            tree.add(word);
        }

        vector<vector<string>> res;
        for (auto word: words) {
            vector<string> ans = vector<string>{word};
            dfs(n, tree, ans, res);
        }
        return res;
    }

    void dfs(int n, Trie &tree, vector<string> &ans, vector<vector<string>> &res) {
        if (ans.size() == n) {
            res.push_back(ans);
            return;
        }
        int k = ans.size();
        string pre = "";
        for (int i = 0; i < k; i++) {
            pre += ans[i][k];
        }

        for (auto word: tree.prefix(pre)) {
            ans.push_back(word);
            dfs(n, tree, ans, res);
            ans.pop_back();
        }
    }
};