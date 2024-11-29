//  Tag: Hash Table, String, Trie, Sorting, Heap (Priority Queue), Bucket Sort, Counting
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an array of strings words and an integer k, return the k most frequent strings.
//  Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
//   
//  Example 1:
//  
//  Input: words = ["i","love","leetcode","i","love","coding"], k = 2
//  Output: ["i","love"]
//  Explanation: "i" and "love" are the two most frequent words.
//  Note that "i" comes before "love" due to a lower alphabetical order.
//  
//  Example 2:
//  
//  Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
//  Output: ["the","is","sunny","day"]
//  Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
//  
//   
//  Constraints:
//  
//  1 <= words.length <= 500
//  1 <= words[i].length <= 10
//  words[i] consists of lowercase English letters.
//  k is in the range [1, The number of unique words[i]]
//  
//   
//  Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
//  

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for (string w: words) {
            counter[w] += 1;
        }
        
        vector<pair<int, string>> word_list;
        for (auto &[word, count]: counter) {
            word_list.emplace_back(-count, word);
        }
            
        sort(word_list.begin(), word_list.end());
        vector<string> res;
 
        for (int i = 0; i < k; i++) {
            res.push_back(word_list[i].second);
        }
        
        return res;
    }
};

// Follow up

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for (string w: words) {
            counter[w] += 1;
        }

        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq;

        for (auto &[word, count]: counter) {
            pq.emplace(count, word);
            if (pq.size() > k) {
                pq.pop();
            }
        }
            
        vector<string> res;
        while (!pq.empty()) {
            pair<int, string> cur = pq.top();
            res.push_back(cur.second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;   
    }
};

class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for (string w: words) {
            counter[w] += 1;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;

        for (auto &[word, count]: counter) {
            pq.emplace(count, word);
            if (pq.size() > k) {
                pq.pop();
            }
        }
            
        vector<string> res;
        while (!pq.empty()) {
            pair<int, string> cur = pq.top();
            res.push_back(cur.second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;   
    }
};