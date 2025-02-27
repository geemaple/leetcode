//  Tag: Array, Hash Table, Dynamic Programming
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/TPkKMcx4zwA

//  A sequence x1, x2, ..., xn is Fibonacci-like if:
//  
//  n >= 3
//  xi + xi+1 == xi+2 for all i + 2 <= n
//  
//  Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
//  A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].
//   
//  Example 1:
//  
//  Input: arr = [1,2,3,4,5,6,7,8]
//  Output: 5
//  Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
//  Example 2:
//  
//  Input: arr = [1,3,7,11,12,14,18]
//  Output: 3
//  Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
//   
//  Constraints:
//  
//  3 <= arr.length <= 1000
//  1 <= arr[i] < arr[i + 1] <= 109
//  
//  

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        unordered_set<int> table(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int length = 2;
                int pre = arr[i];
                int cur = arr[j];
                while (table.count(pre + cur) > 0) {
                    int next = pre + cur;
                    pre = cur;
                    cur = next;
                    length += 1;
                }
                res = max(res, length);
            }
        }
        return res >= 3 ? res : 0;
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        unordered_map<int, int> table;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            table[arr[i]] = i;
            for (int j = i + 1; j < n; j++) {
                int pre = arr[j] - arr[i];
                if (table.count(pre) > 0 && pre < arr[i]) {
                    dp[i][j] = dp[table[pre]][i] + 1;
                } else {
                    dp[i][j] = 2;
                }   
                res = max(res, dp[i][j]);
            }   
        }
        return res >= 3 ? res : 0;
    }
};