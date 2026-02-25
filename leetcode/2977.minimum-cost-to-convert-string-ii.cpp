//  Tag: Array, String, Dynamic Programming, Graph Theory, Trie, Shortest Path
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English characters. You are also given two 0-indexed string arrays original and changed, and an integer array cost, where cost[i] represents the cost of converting the string original[i] to the string changed[i].
//  You start with the string source. In one operation, you can pick a substring x from the string, and change it to y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y. You are allowed to do any number of operations, but any pair of operations must satisfy either of these two conditions:
//  
//  The substrings picked in the operations are source[a..b] and source[c..d] with either b < c or d < a. In other words, the indices picked in both operations are disjoint.
//  The substrings picked in the operations are source[a..b] and source[c..d] with a == c and b == d. In other words, the indices picked in both operations are identical.
//  
//  Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
//  Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].
//   
//  Example 1:
//  
//  Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
//  Output: 28
//  Explanation: To convert "abcd" to "acbe", do the following operations:
//  - Change substring source[1..1] from "b" to "c" at a cost of 5.
//  - Change substring source[2..2] from "c" to "e" at a cost of 1.
//  - Change substring source[2..2] from "e" to "b" at a cost of 2.
//  - Change substring source[3..3] from "d" to "e" at a cost of 20.
//  The total cost incurred is 5 + 1 + 2 + 20 = 28. 
//  It can be shown that this is the minimum possible cost.
//  
//  Example 2:
//  
//  Input: source = "abcdefgh", target = "acdeeghh", original = ["bcd","fgh","thh"], changed = ["cde","thh","ghh"], cost = [1,3,5]
//  Output: 9
//  Explanation: To convert "abcdefgh" to "acdeeghh", do the following operations:
//  - Change substring source[1..3] from "bcd" to "cde" at a cost of 1.
//  - Change substring source[5..7] from "fgh" to "thh" at a cost of 3. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation.
//  - Change substring source[5..7] from "thh" to "ghh" at a cost of 5. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation, and identical with indices picked in the second operation.
//  The total cost incurred is 1 + 3 + 5 = 9.
//  It can be shown that this is the minimum possible cost.
//  
//  Example 3:
//  
//  Input: source = "abcdefgh", target = "addddddd", original = ["bcd","defgh"], changed = ["ddd","ddddd"], cost = [100,1578]
//  Output: -1
//  Explanation: It is impossible to convert "abcdefgh" to "addddddd".
//  If you select substring source[1..3] as the first operation to change "abcdefgh" to "adddefgh", you cannot select substring source[3..7] as the second operation because it has a common index, 3, with the first operation.
//  If you select substring source[3..7] as the first operation to change "abcdefgh" to "abcddddd", you cannot select substring source[1..3] as the second operation because it has a common index, 3, with the first operation.
//  
//   
//  Constraints:
//  
//  1 <= source.length == target.length <= 1000
//  source, target consist only of lowercase English characters.
//  1 <= cost.length == original.length == changed.length <= 100
//  1 <= original[i].length == changed[i].length <= source.length
//  original[i], changed[i] consist only of lowercase English characters.
//  original[i] != changed[i]
//  1 <= cost[i] <= 106
//  
//  

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> index;
        for (const string& o : original) {
            if (!index.count(o)) {
                index[o] = index.size();
            }
        }
        for (const string& c : changed) {
            if (!index.count(c)) {
                index[c] = index.size();
            }
        }

        int n = index.size();
        vector<vector<long>> dis(n, vector<long>(n, LONG_MAX));

        for (int i = 0; i < cost.size(); ++i) {
            dis[index[original[i]]][index[changed[i]]] = min(dis[index[original[i]]][index[changed[i]]], (long)cost[i]);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (dis[i][k] < LONG_MAX) {
                    for (int j = 0; j < n; ++j) {
                        if (dis[k][j] < LONG_MAX) {
                            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        }
                    }
                }
            }
        }

        unordered_set<int> substrLengths;
        for (const string& o : original) {
            substrLengths.insert(o.length());
        }

        vector<long> dp(target.length() + 1, LONG_MAX);
        dp[0] = 0;

        for (int i = 0; i < target.length(); ++i) {
            if (dp[i] == LONG_MAX) {
                continue;
            }

            if (target[i] == source[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            for (int t : substrLengths) {
                if (i + t >= dp.size()) {
                    continue;
                }

                string subSource = source.substr(i, t);
                string subTarget = target.substr(i, t);

                int c1 = index.count(subSource) ? index[subSource] : -1;
                int c2 = index.count(subTarget) ? index[subTarget] : -1;

                if (c1 >= 0 && c2 >= 0 && dis[c1][c2] < LONG_MAX) {
                    dp[i + t] = min(dp[i + t], dp[i] + dis[c1][c2]);
                }
            }
        }

        return dp[dp.size() - 1] == LONG_MAX ? -1L : dp[dp.size() - 1];
    }
};