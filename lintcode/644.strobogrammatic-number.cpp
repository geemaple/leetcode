//  Tag: Hash Table, Simulation
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-246
//  Note: -

//  A mirror number is a number that looks the same when rotated 180 degrees (looked at upside down).For example, the numbers "69", "88", and "818" are all mirror numbers.
//  
//  Write a function to determine if a number is mirror.
//  The number is represented as a string.
//  
//  **Example 1:**
//  ```
//  Input : "69"
//  Output : true
//  ```
//  
//  **Example 2:**
//  ```
//  Input : "68"
//  Output : false
//  ```
//  
//  

class Solution {
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        // write your code here
        unordered_map<char, char> mirrors;
        mirrors['0'] = '0';
        mirrors['1'] = '1';
        mirrors['6'] = '9';
        mirrors['8'] = '8';
        mirrors['9'] = '6';

        int i = 0;
        int j = num.size() - 1;
        while (i <= j) {
            if (mirrors.count(num[i]) == 0 || mirrors[num[i]] != num[j]) {
                return false;
            }
            i += 1;
            j -= 1;
        }
        return true;
    }
};