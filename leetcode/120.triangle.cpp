//  Tag: Array, Dynamic Programming
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a triangle array, return the minimum path sum from top to bottom.
//  For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
//   
//  Example 1:
//  
//  Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//  Output: 11
//  Explanation: The triangle looks like:
//     2
//    3 4
//   6 5 7
//  4 1 8 3
//  The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
//  
//  Example 2:
//  
//  Input: triangle = [[-10]]
//  Output: -10
//  
//   
//  Constraints:
//  
//  1 <= triangle.length <= 200
//  triangle[0].length == 1
//  triangle[i].length == triangle[i - 1].length + 1
//  -104 <= triangle[i][j] <= 104
//  
//   
//  Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle.back();

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();

        vector<int> dp(m, 0);
        dp[0] = triangle[0][0];

        for (int i = 1; i < n; ++i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                if (j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    dp[j] = dp[j - 1] + triangle[i][j];
                } else {
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
                }
            }
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        unordered_map<int, int> cache;
        return helper(triangle, 0, 0, cache);
    }

    int helper(vector<vector<int>>& triangle, int i, int j, unordered_map<int, int> &cache) {
        if (i == triangle.size()) {
            return 0;
        }

        int index = (1 + i) * i / 2 + j;
        if (cache.count(index) == 0) {
            int left = helper(triangle, i + 1, j, cache);
            int right = helper(triangle, i + 1, j + 1, cache);
            cache[index] = min(left, right) + triangle[i][j];
        }

        return cache[index];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(triangle, 0, 0);
    }

    int helper(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size()) {
            return 0;
        }

        int left = helper(triangle, i + 1, j);
        int right = helper(triangle, i + 1, j + 1);
        return min(left, right) + triangle[i][j];
    }
};