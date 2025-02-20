//  Tag: Array, Hash Table, String, Backtracking
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/B7Nl-Lb76JU

//  Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
//   
//  Example 1:
//  
//  Input: nums = ["01","10"]
//  Output: "11"
//  Explanation: "11" does not appear in nums. "00" would also be correct.
//  
//  Example 2:
//  
//  Input: nums = ["00","01"]
//  Output: "11"
//  Explanation: "11" does not appear in nums. "10" would also be correct.
//  
//  Example 3:
//  
//  Input: nums = ["111","011","001"]
//  Output: "101"
//  Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
//  
//   
//  Constraints:
//  
//  n == nums.length
//  1 <= n <= 16
//  nums[i].length == n
//  nums[i] is either '0' or '1'.
//  All the strings of nums are unique.
//  
//  

class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            string res;
            for (int i = 0; i < n; i++) {
                res += nums[i][i] == '0' ? '1': '0';
            }
            return res;
        }
    };

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> table(nums.begin(), nums.end());
        int n = nums[0].size();
        string res;
        helper(table, res, 0, n);
        return res;
    }
    
    bool helper(unordered_set<string>& table, string& res, int i, int n) {
        if (i == n) {
            return table.count(res) == 0;
        }

        for (char ch : {'0', '1'}) {
            res += ch;
            if (helper(table, res, i + 1, n)) {
                return true;
            }
            res.pop_back();
        }

        return false;
    }
    
};