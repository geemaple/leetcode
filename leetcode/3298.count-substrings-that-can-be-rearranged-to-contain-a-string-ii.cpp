//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(M)
//  Ref: -
//  Note: -

//  You are given two strings word1 and word2.
//  A string x is called valid if x can be rearranged to have word2 as a prefix.
//  Return the total number of valid substrings of word1.
//  Note that the memory limits in this problem are smaller than usual, so you must implement a solution with a linear runtime complexity.
//   
//  Example 1:
//  
//  Input: word1 = "bcca", word2 = "abc"
//  Output: 1
//  Explanation:
//  The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
//  
//  Example 2:
//  
//  Input: word1 = "abcabc", word2 = "abc"
//  Output: 10
//  Explanation:
//  All the substrings except substrings of size 1 and size 2 are valid.
//  
//  Example 3:
//  
//  Input: word1 = "abcabc", word2 = "aaabc"
//  Output: 0
//  
//   
//  Constraints:
//  
//  1 <= word1.length <= 106
//  1 <= word2.length <= 104
//  word1 and word2 consist only of lowercase English letters.
//  
//  

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        int k = word2.size();
        unordered_map<char, int> counter;
        for (auto &ch: word2) {
            counter[ch] += 1;
        }

        int count = 0;
        long long res = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            counter[word1[j]] -= 1;
            if (counter[word1[j]] >= 0) {
                count += 1;
            }
            while (count == k) {
                res += n - j;
                counter[word1[i]] += 1;
                if (counter[word1[i]] >= 1) {
                    count -= 1;
                }
                i += 1;
            }
        }
        return res;
    }
};