//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given a string word and an integer k.
//  A substring s of word is complete if:
//  
//  Each character in s occurs exactly k times.
//  The difference between two adjacent characters is at most 2. That is, for any two adjacent characters c1 and c2 in s, the absolute difference in their positions in the alphabet is at most 2.
//  
//  Return the number of complete substrings of word.
//  A substring is a non-empty contiguous sequence of characters in a string.
//   
//  Example 1:
//  
//  Input: word = "igigee", k = 2
//  Output: 3
//  Explanation: The complete substrings where each character appears exactly twice and the difference between adjacent characters is at most 2 are: igigee, igigee, igigee.
//  
//  Example 2:
//  
//  Input: word = "aaabbbccc", k = 3
//  Output: 6
//  Explanation: The complete substrings where each character appears exactly three times and the difference between adjacent characters is at most 2 are: aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc.
//  
//   
//  Constraints:
//  
//  1 <= word.length <= 105
//  word consists only of lowercase English letters.
//  1 <= k <= word.length
//  
//  

class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        vector<string> splits;
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (abs(word[j] - word[j - 1]) > 2) {
                splits.push_back(word.substr(i, j - i));
                i = j;
            }
        }
        splits.push_back(word.substr(i, n));

        int res = 0;
        for (auto &s: splits) {
            for (int r = 1; r <= 26; r++) {
                int win_size = r * k;
                if (win_size > s.size()) {
                    break;
                }
                vector<int> counter(26, 0);
                for (int i = 0; i < s.size(); i++) {
                    if (i >= win_size) {
                        counter[s[i - win_size] - 'a'] -= 1;
                    }
                    counter[s[i] - 'a'] += 1;

                    if (i >= win_size - 1) {
                        if (checkCount(counter, k)) {
                            res += 1;
                        }
                    }
                }
            }
        }
        return res;
    }

    bool checkCount(vector<int> &counter, int target) {
        for (int i = 0; i < 26; i++) {
            if (counter[i] != 0 && counter[i] != target) {
                return false;
            }
        }
        return true;
    }
};