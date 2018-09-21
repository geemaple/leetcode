class Solution {
private:
    string abbreviateWord(string &word, int pos)
    {
        int size = (int)(word.size());
        if (pos + 2 >= size)
        {
            return word;
        }

        return word.substr(0, pos) + to_string(size - pos - 1) + word.substr(size - 1, 1);
    }
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        
        vector<string> res;
        unordered_map<string, int> coutingMap;
        vector<int> prefixes;
        for (auto word: dict)
        {
            string abbr = abbreviateWord(word, 1);
            prefixes.push_back(1);
            res.push_back(abbr);
            coutingMap[abbr] += 1;
        }

        while(true)
        {
            bool unique = true;
            for (auto i = 0; i < res.size(); ++i)
            {
                if (coutingMap[res[i]] > 1)
                {
                    prefixes[i] ++;
                    res[i] = abbreviateWord(dict[i], prefixes[i]);
                    coutingMap[res[i]] += 1;
                    unique = false;
                }
            }

            if (unique)
            {
                break;
            }
        }

        return res;
    }
};
