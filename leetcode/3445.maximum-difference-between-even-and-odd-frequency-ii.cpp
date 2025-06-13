//  Tag: String, Sliding Window, Enumeration, Prefix Sum
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/cAP-Qe1DduI

//  You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:
//  
//  subs has a size of at least k.
//  Character a has an odd frequency in subs.
//  Character b has an even frequency in subs.
//  
//  Return the maximum difference.
//  Note that subs can contain more than 2 distinct characters.
//   
//  Example 1:
//  
//  Input: s = "12233", k = 4
//  Output: -1
//  Explanation:
//  For the substring "12233", the frequency of '1' is 1 and the frequency of '3' is 2. The difference is 1 - 2 = -1.
//  
//  Example 2:
//  
//  Input: s = "1122211", k = 3
//  Output: 1
//  Explanation:
//  For the substring "11222", the frequency of '2' is 3 and the frequency of '1' is 2. The difference is 3 - 2 = 1.
//  
//  Example 3:
//  
//  Input: s = "110", k = 3
//  Output: -1
//  
//   
//  Constraints:
//  
//  3 <= s.length <= 3 * 104
//  s consists only of digits '0' to '4'.
//  The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.
//  1 <= k <= s.length
//  
//  

class Solution {
public:
    int maxDifference(string s, int k) {
        int res = INT_MIN;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i != j) {
                    res = max(res, find('0' + i, '0' + j, s, k));
                }
            }
        }
        return res;
    }

    int find(char a, char b, string &s, int k) {
        int n = s.size();
        int count_a = 0, count_b = 0;
        int pre_a = 0, pre_b = 0;
        int res = INT_MIN;
        vector<vector<int>> minDiff(2, vector<int>(2, INT_MAX)); 
        int l = 0;
        for (int r = 0; r < n; r++) {
            count_a += s[r] == a;
            count_b += s[r] == b;
            while (r - l + 1 >= k && count_b - pre_b >= 2) {
                int i = pre_a % 2;
                int j = pre_b % 2;
                minDiff[i][j] = min(minDiff[i][j], pre_a - pre_b);
                pre_a += s[l] == a;
                pre_b += s[l] == b;
                l += 1;
            }

            int i = count_a % 2;
            int j = count_b % 2;
            if (minDiff[i ^ 1][j] != INT_MAX) {
                res = max(res, count_a - count_b - minDiff[i ^ 1][j]);
            }
        }
        return res;
    }
};