//  Tag: Array, Hash Table, Sorting, Enumeration
//  Time: O(1)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/J_ODVpvGvUg

//  You are given an integer array digits, where each element is a digit. The array may contain duplicates.
//  You need to find all the unique integers that follow the given requirements:
//  
//  The integer consists of the concatenation of three elements from digits in any arbitrary order.
//  The integer does not have leading zeros.
//  The integer is even.
//  
//  For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
//  Return a sorted array of the unique integers.
//   
//  Example 1:
//  
//  Input: digits = [2,1,3,0]
//  Output: [102,120,130,132,210,230,302,310,312,320]
//  Explanation: All the possible integers that follow the requirements are in the output array. 
//  Notice that there are no odd integers or integers with leading zeros.
//  
//  Example 2:
//  
//  Input: digits = [2,2,8,8,2]
//  Output: [222,228,282,288,822,828,882]
//  Explanation: The same digit can be used as many times as it appears in digits. 
//  In this example, the digit 8 is used twice each time in 288, 828, and 882. 
//  
//  Example 3:
//  
//  Input: digits = [3,7,5]
//  Output: []
//  Explanation: No even integers can be formed using the given digits.
//  
//   
//  Constraints:
//  
//  3 <= digits.length <= 100
//  0 <= digits[i] <= 9
//  
//  

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> counter(10, 0);
        for (auto &x: digits) {
            counter[x] += 1;
        }

        vector<int> res;
        helper(0, 0, res, counter);
        return res;
    }

    void helper(int i, int ans, vector<int> &res, vector<int> &counter) {
        if (i == 3) {
            res.push_back(ans);
            return;
        }

        for (int d = 0; d <= 9; d++) {
            if ((i == 0 && d == 0) || (i == 2 && d % 2 == 1) || counter[d] == 0) {
                continue;
            }

            counter[d] -= 1;
            helper(i + 1, ans * 10 + d, res, counter);
            counter[d] += 1;
        }

    }
};