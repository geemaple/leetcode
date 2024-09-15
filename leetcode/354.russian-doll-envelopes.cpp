//  Tag: Array, Binary Search, Dynamic Programming, Sorting
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//  One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//  Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//  Note: You cannot rotate an envelope.
//   
//  Example 1:
//  
//  Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
//  Output: 3
//  Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//  
//  Example 2:
//  
//  Input: envelopes = [[1,1],[1,1],[1,1]]
//  Output: 1
//  
//   
//  Constraints:
//  
//  1 <= envelopes.length <= 105
//  envelopes[i].length == 2
//  1 <= wi, hi <= 105
//  
//  

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int>&b){
            return (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]));
        });
        vector<int> res;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(res.begin(), res.end(), envelopes[i][1]);
            if (it == res.end()) {
                res.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }

        return res.size();
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][0] != envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(res.begin(), res.end(), envelopes[i],
                                  [](const vector<int>& a, const vector<int>& b) {
                                      return a[1] < b[1];
                                  });

            if (it == res.end()) {
                res.push_back(envelopes[i]);
            } else {
                *it = envelopes[i];
            }
        }

        return res.size();
    }
};