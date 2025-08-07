//  Tag: Array, Dynamic Programming
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/gZNCnr7jzJk

//  Given an integer numRows, return the first numRows of Pascal's triangle.
//  In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
//  
//   
//  Example 1:
//  Input: numRows = 5
//  Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//  Example 2:
//  Input: numRows = 1
//  Output: [[1]]
//  
//   
//  Constraints:
//  
//  1 <= numRows <= 30
//  
//  

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (auto r = 1; r <= numRows; ++r) {
            vector<int> ans(r, 1);
            for (auto i = 1; i < r - 1; ++i) {
                vector<int> previous = res[res.size() - 1];
                ans[i] = previous[i - 1] + previous[i];
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};