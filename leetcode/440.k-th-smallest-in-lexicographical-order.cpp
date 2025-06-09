//  Tag: Trie
//  Time: O((logN) ^ 2)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/un_lgww-7zo

//  Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
//   
//  Example 1:
//  
//  Input: n = 13, k = 2
//  Output: 10
//  Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
//  
//  Example 2:
//  
//  Input: n = 1, k = 1
//  Output: 1
//  
//   
//  Constraints:
//  
//  1 <= k <= n <= 109
//  
//  

class Solution {
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        k = k - 1;
        while (k > 0) {
            int count = count_prefix(prefix, n);
            if (count <= k) {
                k -= count;
                prefix += 1;
            } else {
                prefix *= 10;
                k -= 1;
            }
        }
        return prefix;
    }

    int count_prefix(long long prefix, int n) {
        int res = 0;
        long long next_prefix = prefix + 1;
        while (prefix <= n) {
            res += min(n + 1LL, next_prefix) - prefix;
            prefix *= 10;
            next_prefix *= 10;
        }
        return res;
    }
};