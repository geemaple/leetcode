//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/KceY_w1PJ-Y

//  You are given a string word and a non-negative integer k.
//  Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
//   
//  Example 1:
//  
//  Input: word = "aeioqq", k = 1
//  Output: 0
//  Explanation:
//  There is no substring with every vowel.
//  
//  Example 2:
//  
//  Input: word = "aeiou", k = 0
//  Output: 1
//  Explanation:
//  The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".
//  
//  Example 3:
//  
//  Input: word = "ieaouqqieaouqq", k = 1
//  Output: 3
//  Explanation:
//  The substrings with every vowel and one consonant are:
//  
//  word[0..5], which is "ieaouq".
//  word[6..11], which is "qieaou".
//  word[7..12], which is "ieaouq".
//  
//  
//   
//  Constraints:
//  
//  5 <= word.length <= 2 * 105
//  word consists only of lowercase English letters.
//  0 <= k <= word.length - 5
//  
//  

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return count(word, k) - count(word, k + 1);
    }

    long long count(string &word, int k) {
        int n = word.size();
        unordered_map<char, int> vowel;
        int count = 0;
        long long res = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (is_consonant(word[j])) {
                vowel[word[j]] += 1;
            } else {
                count += 1;
            }

            while (vowel.size() == 5 && count >= k) {
                res += n - j;
                if (is_consonant(word[i])) {
                    vowel[word[i]] -= 1;
                    if (vowel[word[i]] == 0) {
                        vowel.erase(word[i]);
                    }
                } else {
                    count -= 1;
                }
                i += 1;
            }
        }
        return res;
    }

    bool is_consonant(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_map<char, int> counter;
        int consonants = 0;
        int vowels = 0;
        vector<int> next_constant = vector<int>(n, 0);
        int val = n;
        for (int i = n - 1; i >= 0; i--) {
            next_constant[i] = val;
            if (!is_consonant(word[i])) {
                val = i;
            }
        }

        int i = 0;
        long long res = 0;
        for (int j = 0; j < n; j++) {
            if (is_consonant(word[j])) {
                counter[word[j]] += 1;
                if (counter[word[j]] == 1) {
                    vowels += 1;
                }
            } else {
                consonants += 1;
            }

            while (consonants > k) {
                if (is_consonant(word[i])) {
                    counter[word[i]] -= 1;
                    if (counter[word[i]] == 0) {
                        vowels -= 1;
                    }
                } else {
                    consonants -= 1;
                }

                i += 1;
            }

            while (vowels == 5 && consonants == k) {
                res += next_constant[j] - j;

                if (is_consonant(word[i])) {
                    counter[word[i]] -= 1;
                    if (counter[word[i]] == 0) {
                        vowels -= 1;
                    }
                } else {
                    consonants -= 1;
                }

                i += 1;
            }
        }
        return res;
    }

    bool is_consonant(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};