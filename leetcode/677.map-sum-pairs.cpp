class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    bool isWord = false;
    int sum = 0;

    ~TrieNode(){
        for(auto it: children)
        {
            delete it.second;
        }
    }
};


class MapSum {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    ~MapSum() {
        delete root;
    }

    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *node = root;
        for (auto c: key){
            if (node->children.count(c) == 0){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
        node->sum = val;
    }
    
    int sum(string prefix) {
        TrieNode *node = root;
        for (auto c: prefix){
            if (node->children.count(c) == 0){
                return 0;
            }

            node = node->children[c];
        }
        int sum = 0;

        queue<TrieNode *> q;
        q.push(node);

        while(!q.empty())
        {
            TrieNode *node = q.front();
            q.pop();

            if (node->isWord){
                sum += node->sum;
            }

            for(auto it: node->children){
                q.push(it.second); //:Fixme
            }
        }

        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
