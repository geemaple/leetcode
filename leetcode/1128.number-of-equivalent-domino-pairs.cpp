//  Tag: Array, Hash Table, Counting
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/oMfhRGhz-VY

//  Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
//  Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
//   
//  Example 1:
//  
//  Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
//  Output: 1
//  
//  Example 2:
//  
//  Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
//  Output: 3
//  
//   
//  Constraints:
//  
//  1 <= dominoes.length <= 4 * 104
//  dominoes[i].length == 2
//  1 <= dominoes[i][j] <= 9
//  
//  

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        unordered_map<int, int> counter;
        int res = 0;

        for (int i = 0; i < n; i++) {
            int key = min(dominoes[i][0], dominoes[i][1]) * 10 + max(dominoes[i][0], dominoes[i][1]);
            if (counter.find(key) != counter.end()) {
                res += counter[key];
            }
            counter[key] += 1;
        }
        return res;
    }
};