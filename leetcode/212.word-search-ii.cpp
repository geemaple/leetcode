//  Tag: Array, String, Backtracking, Trie, Matrix
//  Time: O(NM*4^L)
//  Space: O(MN + KL)
//  Ref: -
//  Note: -

//  Given an m x n board of characters and a list of strings words, return all words on the board.
//  Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//   
//  Example 1:
//  
//  
//  Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
//  Output: ["eat","oath"]
//  
//  Example 2:
//  
//  
//  Input: board = [["a","b"],["c","d"]], words = ["abcb"]
//  Output: []
//  
//   
//  Constraints:
//  
//  m == board.length
//  n == board[i].length
//  1 <= m, n <= 12
//  board[i][j] is a lowercase English letter.
//  1 <= words.length <= 3 * 104
//  1 <= words[i].length <= 10
//  words[i] consists of lowercase English letters.
//  All the strings of words are unique.
//  
//  

class TrieNode {
public:
    vector<TrieNode *> children;
    string word;
    bool is_word;
    TrieNode(): children(26, nullptr), word(""), is_word(false) {
    }

    ~TrieNode() {
        for (auto ptr: children) {
            delete ptr;
        }
    }
};

class Trie {
public:
    TrieNode *root;
    Trie(): root(new TrieNode()) {}
    ~Trie() {
        delete root;
    }

    void add_word(string word) {
        TrieNode *cur = root;
        for (auto ch: word) {
            if (!cur->children[ch - 'a']) {
                cur->children[ch - 'a'] = new TrieNode();
            }
            cur = cur->children[ch - 'a'];
        }

        cur->is_word = true;
        cur->word = word;
    }

};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (auto word: words) {
            trie.add_word(word);
        }

        vector<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                helper(i, j, board, trie.root, res);
            }
        }
        
        return res;
    }
    
    void helper(int i, int j, vector<vector<char>>& board, TrieNode *node, vector<string> &res) {
        char ch = board[i][j];
        if (!node->children[ch - 'a']) {
            return;
        }
        
        TrieNode *next_node = node->children[ch - 'a'];
        if (next_node->is_word) {
            next_node->is_word = false;
            res.push_back(next_node->word);
        }
        
        char val = board[i][j];
        board[i][j] = '#';
        int directions[] = {-1, 0, 1, 0, -1};
        for (int d = 0; d < 4; d++) {
            int x = i + directions[d];
            int y = j + directions[d + 1];
            if (x >=0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] != '#') {
                helper(x, y, board, next_node, res);
            }
            
        }
        
        board[i][j] = val;
    }
};