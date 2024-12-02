#  Tag: Hash Table, Simulation
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-246
#  Note: -

#  A mirror number is a number that looks the same when rotated 180 degrees (looked at upside down).For example, the numbers "69", "88", and "818" are all mirror numbers.
#  
#  Write a function to determine if a number is mirror.
#  The number is represented as a string.
#  
#  **Example 1:**
#  ```
#  Input : "69"
#  Output : true
#  ```
#  
#  **Example 2:**
#  ```
#  Input : "68"
#  Output : false
#  ```
#  
#  

class Solution:
    """
    @param num: a string
    @return: true if a number is strobogrammatic or false
    """
    def is_strobogrammatic(self, num: str) -> bool:
        # write your code here
        mirrors = {
            '6': '9',
            '1': '1',
            '8': '8',
            '9': '6',
            '0': '0'
            }

        left = 0 
        right = len(num) - 1
        while left <= right:
            if num[left] not in mirrors or mirrors[num[left]] != num[right]:
                return False
            left += 1
            right -= 1

        return True