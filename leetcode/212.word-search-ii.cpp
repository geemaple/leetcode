class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    string word;
    bool isWord;
    ~TrieNode(){
        for(auto it: children){
            delete it.second; //:Fixme
        }
    }
};

class Trie {
public:
    
    TrieNode *root;
    ~Trie(){
        delete root;
    }
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string& word)
    {
        TrieNode *node = root;
        for (auto c : word)
        {
            if (node->children.count(c) == 0)
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
        node->word = word;
    }
    
    TrieNode *search(TrieNode *node, char c)
    {
        if (node->children.count(c) == 0)
        {
            return NULL;
        }
    
        return node->children[c];
    }
};

class Solution {
    int directions[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
private:
    int convert_point(vector<vector<char>>& board, int x, int y)
    {
        return x * board[0].size() + y;
    }
    
    bool check_in_board(vector<vector<char>>& board, int x, int y)
    {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[x].size());
    }
    
    void search_dfs(vector<vector<char>>& board, int x, int y, unordered_set<int>& visted, Trie& trie, TrieNode *node, vector<string>& res)
    {
        
        node = trie.search(node, board[x][y]);
        
        if (node == NULL)
        {
            return;
        }
        
        if (node->isWord)
        {
            node->isWord = false;
            res.push_back(node->word);
        }
        
        int point = convert_point(board, x, y);
        visted.insert(point);
        for (auto direction: directions)
        {
            int new_x = x + direction[0];
            int new_y = y + direction[1];
            int new_point = convert_point(board, new_x, new_y);
            if (check_in_board(board, new_x, new_y) && visted.count(new_point) == 0){
                search_dfs(board, new_x, new_y, visted, trie, node, res);
            }
        }
        
        visted.erase(point);
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<int> visted;
        vector<string> res;
        Trie trie;
        
        for (auto word: words){
            trie.insert(word);
        }
        
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++ j)
            {
                search_dfs(board, i, j, visted, trie, trie.root, res);
            }
        }

        return res;
    }
};