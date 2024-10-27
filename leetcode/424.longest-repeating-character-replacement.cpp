//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
//  Return the length of the longest substring containing the same letter you can get after performing the above operations.
//   
//  Example 1:
//  
//  Input: s = "ABAB", k = 2
//  Output: 4
//  Explanation: Replace the two 'A's with two 'B's or vice versa.
//  
//  Example 2:
//  
//  Input: s = "AABABBA", k = 1
//  Output: 4
//  Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
//  The substring "BBBB" has the longest repeating letters, which is 4.
//  There may exists other ways to achieve this answer too.
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s consists of only uppercase English letters.
//  0 <= k <= s.length
//  
//  

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int j = 0;
        vector<int> counter(26, 0);
        int mas_freq = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            counter[s[i] - 'A'] += 1;
            mas_freq = max(mas_freq, counter[s[i] - 'A']);

            // length - most_frequent <= k
            // kepp most_frequent unchanged since smaller frequnt won't contribute to the result
            while (i - j + 1 - mas_freq > k) {
                counter[s[j] - 'A']--;
                j++;   
            }

            res = max(res, i - j + 1);
        }

        return res;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int j = 0;
        vector<int> counter(26, 0);
        int res = 0;

        for (int i = 0; i < n; i++) {
            counter[s[i] - 'A'] += 1;
            while (i - j + 1 - *max_element(counter.begin(), counter.end()) > k) {
                counter[s[j] - 'A']--;
                j++;   
            }

            res = max(res, i - j + 1);
        }

        return res;
    }
};