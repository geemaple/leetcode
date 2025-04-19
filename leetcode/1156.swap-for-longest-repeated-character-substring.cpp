//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given a string text. You can swap two of the characters in the text.
//  Return the length of the longest substring with repeated characters.
//   
//  Example 1:
//  
//  Input: text = "ababa"
//  Output: 3
//  Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
//  
//  Example 2:
//  
//  Input: text = "aaabaaa"
//  Output: 6
//  Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
//  
//  Example 3:
//  
//  Input: text = "aaaaa"
//  Output: 5
//  Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
//  
//   
//  Constraints:
//  
//  1 <= text.length <= 2 * 104
//  text consist of lowercase English characters only.
//  
//  

class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> counter;
        for (auto &ch: text) {
            counter[ch] += 1;
        } 
        int res = 0;
        for (auto &[k, c]: counter) {
            int tmp = min(c, count(text, k));
            res = max(res, tmp);
        }
        return res;
    }

    int count(string &text, char target) {
        int n = text.size();
        int i = 0;
        int res = 0;
        int count = 0;
        for (int j = 0; j < n; j++) {
            count += text[j] != target;
            while (count > 1) {
                count -= text[i] != target;
                i += 1;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<pair<int, int>> group;
        vector<int> counter(26, 0);
        int count = 1;
        for (int i = 0; i < n; i++) {
            counter[text[i] - 'a'] += 1;
            if (i == n - 1 || text[i] != text[i + 1]) {
                group.emplace_back(text[i] - 'a', count);
                count = 1;
            } else {
                count += 1;
            }
        }

        int res = 0;
        for (auto &[x, count]: group) {
            res = max(res, min(count + 1, counter[x]));
        }

        for (int i = 1; i < group.size() - 1; i++) {
            if (group[i - 1].first == group[i + 1].first && group[i].second == 1) {
                res = max(res, min(group[i - 1].second + group[i + 1].second + 1, counter[group[i - 1].first]));
            }
        }
        return res;
    }
};