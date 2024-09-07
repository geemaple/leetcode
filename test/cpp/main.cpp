#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

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

int main() {
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    Solution s;
    vector<string> res = s.findWords(board, words);
    
    for (auto &word : res) {
        cout << word << ", ";
    }
    cout << endl;

    return 0;
}

