//  Tag: Simulation
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-163
//  Note: -

//  Given a sorted integer array where **the range of elements are in the inclusive range [lower, upper]**, return its missing ranges.
//  
//  **Example 1**
//  ```
//  Input:
//  nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99
//  Output:
//  ["2", "4->49", "51->74", "76->99"]
//  Explanation:
//  in range[0,99],the missing range includes:range[2,2],range[4,49],range[51,74] and range[76,99]
//  ```
//  **Example 2**
//  ```
//  Input:
//  nums = [0, 1, 2, 3, 7], lower = 0 and upper = 7
//  Output:
//  ["4->6"]
//  Explanation:
//  in range[0,7],the missing range include range[4,6]
//  ```
//  
//  

class Solution {
public:
    /**
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        // write your code here
        vector<string> res;
        long long low = lower;
        for (int x: nums) {
            if (low < x) {
                res.push_back(output(low, x - 1));
            }
            low = x + 1LL;
        }
        if (low <= upper) {
            res.push_back(output(low, upper));
        }
        return res;
    }

    string output(int low, int high) {
        if (low == high) {
            return to_string(low);
        } else {
            return to_string(low) + "->" + to_string(high);
        }

    }
};