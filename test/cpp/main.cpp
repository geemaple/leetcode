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
    bool is_word;
    vector<string> prefix;
    TrieNode(): children(26, nullptr), is_word(false), prefix() {}
    ~TrieNode() {
        cout << this << endl;
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


int main() {
    vector<string> words= {"area","lead","wall","lady","ball"};
    
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    vector<vector<string>> res = s.wordSquares(words);
//    cout << res << endl;
//    for (auto word : res) {
//        cout << word << ", ";
//    }
    cout << endl;
    
    return 0;
}

