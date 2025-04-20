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
        int i = 0;
        vector<int> counter(26, 0);
        int max_freq = 0;
        int res = 0;

        for (int j = 0; j < n; j++) {
            counter[s[j] - 'A'] += 1;
            max_freq = max(max_freq, counter[s[j] - 'A']);

            // length - most_frequent <= k
            // kepp most_frequent unchanged since smaller frequnt won't contribute to the result
            while (j - i + 1 - max_freq > k) {
                counter[s[i] - 'A']--;
                i++;   
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res = max(res, count(s, 'A' + i, k));
        }
        return res;
    }

    int count(string &s, char target, int k) {
        int n = s.size();
        int i = 0;
        int count = 0;
        int res = 0;

        for (int j = 0; j < n; j++) {
            count += s[j] != target;
            while (count > k) {
                count -= s[i] != target;
                i++;   
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};