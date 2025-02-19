//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(K)
//  Ref: -
//  Note: -

//  You are given a string s and an array of strings words. All the strings of words are of the same length.
//  A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
//  
//  For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
//  
//  Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
//   
//  Example 1:
//  
//  Input: s = "barfoothefoobarman", words = ["foo","bar"]
//  Output: [0,9]
//  Explanation:
//  The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
//  The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
//  
//  Example 2:
//  
//  Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//  Output: []
//  Explanation:
//  There is no concatenated substring.
//  
//  Example 3:
//  
//  Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//  Output: [6,9,12]
//  Explanation:
//  The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
//  The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
//  The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 104
//  1 <= words.length <= 5000
//  1 <= words[i].length <= 30
//  s and words[i] consist of lowercase English letters.
//  
//  

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int k = words.size();
        int l = words[0].size();
        vector<int> res;
        unordered_map<string, int> counter;
        for (auto x: words) {
            counter[x] += 1;
        }

        for (int index = 0; index < l; index++) {
            int left = index;
            int count = 0;
            int hit = 0;
            unordered_map<string, int> current_counter = counter;
            for (int i = index; i <= n - l; i += l) {
                string sub = s.substr(i, l);
                count += 1;
                if (current_counter.count(sub) > 0) {
                    current_counter[sub] -= 1;
                    if (current_counter[sub] >= 0) {
                        hit += 1;
                    }
                }

                if (count == k) {
                    if (hit == k) {
                        res.push_back(left);
                    }
                    string pre = s.substr(left, l);
                    if (current_counter.count(pre) > 0) {
                        current_counter[pre] += 1;
                        if (current_counter[pre] >= 1) {
                            hit -= 1;
                        }
                    }
                    count -= 1;
                    left += l;
                }
            }
        }

        return res;
    }
};