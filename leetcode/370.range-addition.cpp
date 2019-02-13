/*
 * @lc app=leetcode id=370 lang=cpp
 *
 * [370] Range Addition
 *
 * https://leetcode.com/problems/range-addition/description/
 *
 * algorithms
 * Medium (59.19%)
 * Total Accepted:    23.4K
 * Total Submissions: 39.1K
 * Testcase Example:  '5\n[[1,3,2],[2,4,3],[0,2,-2]]'
 *
 * Assume you have an array of length n initialized with all 0's and are given
 * k update operations.
 * 
 * Each operation is represented as a triplet: [startIndex, endIndex, inc]
 * which increments each element of subarray A[startIndex ... endIndex]
 * (startIndex and endIndex inclusive) with inc.
 * 
 * Return the modified array after all k operations were executed.
 * 
 * Example:
 * 
 * 
 * Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
 * Output: [-2,0,3,5,3]
 * 
 * 
 * Explanation:
 * 
 * 
 * Initial state:
 * [0,0,0,0,0]
 * 
 * After applying operation [1,3,2]:
 * [0,2,2,2,0]
 * 
 * After applying operation [2,4,3]:
 * [0,2,5,5,3]
 * 
 * After applying operation [0,2,-2]:
 * [-2,0,3,5,3]
 * 
 */
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length + 1, 0);
        for (int i = 0; i < updates.size(); ++i)
        {
            int start = updates[i][0];
            int end = updates[i][1];
            int inc = updates[i][2];
            
            res[start] += inc;
            res[end + 1] += -inc;
        }
        
        for (int i = 1; i < length; ++i)
        {
            res[i] += res[i - 1];
        }
        
        res.pop_back();
        return res;
    }
};
