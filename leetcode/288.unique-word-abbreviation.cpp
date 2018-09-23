class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> wordMap;

    string abbreviate(string &word)
    {
        int size = word.size();
        if (size < 3)
        {
            return word;
        }

        return word.front() + to_string(size - 2) + word.back();
    }

public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto word: dictionary)
        {
            string abbr = abbreviate(word);
            wordMap[abbr].insert(word);
        }
    }
    
    bool isUnique(string word) {
        string abbr = abbreviate(word);
        return wordMap[abbr].count(word) == wordMap[abbr].size();
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
