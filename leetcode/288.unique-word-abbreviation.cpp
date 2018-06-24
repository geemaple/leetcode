class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> map;
    string abbreivate(string s){
        
        int start = 1;
        int end = s.size() - 2;
        
        int count = end - start + 1;
        
        return s.front() + to_string(count) + s.back();
    }
public:
    // O(N)
    ValidWordAbbr(vector<string> dictionary) {
        for (auto s: dictionary){
            string abbr = abbreivate(s);
            map[abbr].insert(s);
        }
    }
    
    // O(1)
    bool isUnique(string word) {
        string abbr = abbreivate(word);
        return map[abbr].count(word) == map[abbr].size();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */