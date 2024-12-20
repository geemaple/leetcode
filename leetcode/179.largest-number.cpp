//  Tag: Array, String, Greedy, Sorting
//  Time: O(NlogN * K)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//  Since the result may be very large, so you need to return a string instead of an integer.
//   
//  Example 1:
//  
//  Input: nums = [10,2]
//  Output: "210"
//  
//  Example 2:
//  
//  Input: nums = [3,30,34,5,9]
//  Output: "9534330"
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 100
//  0 <= nums[i] <= 109
//  
//  

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int x: nums) {
            strs.push_back(to_string(x));
        }

        sort(strs.begin(), strs.end(), [](string x, string y) {
            return x + y > y + x; 
        });

        string res;
        for (auto &s: strs) {
            res += s;
        }   

        return res[0] == '0' ? "0" : res;
    }
};