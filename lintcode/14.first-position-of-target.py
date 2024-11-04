#  Tag: Binary Search
#  Time: O(logN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a sorted array (ascending order) and a `target` number, find the first index of this number in $O(log n)$ time complexity.
#  
#  If the `target` number does not exist in the array, return `-1`.
#  
#  **Example 1:**  
#   
#  Input:  
#  ``` 
#  tuple = [1,4,4,5,7,7,8,9,9,10]
#  target = 1
#  ``` 
#  Output:  
#  ``` 
#  0
#  ``` 
#  Explanation:  
#  
#  The first index of  1 is 0.
#  
#  **Example 2:**  
#   
#  Input:  
#  ``` 
#  tuple = [1, 2, 3, 3, 4, 5, 10]
#  target = 3
#  ``` 
#  Output:  
#  ``` 
#  2
#  ``` 
#  Explanation:  
#  
#  The first index of 3 is 2.
#  
#  **Example 3:**  
#   
#  Input:  
#  ``` 
#  tuple = [1, 2, 3, 3, 4, 5, 10]
#  target = 6
#  ``` 
#  Output:  
#  ``` 
#  -1
#  ``` 
#  Explanation:  
#  
#  There is no 6 in the array，return -1.
#  
#  

from typing import (
    List,
)

class Solution:
    """
    @param nums: The integer array.
    @param target: Target to find.
    @return: The first position of target. Position starts from 0.
    """
    def binary_search(self, nums: List[int], target: int) -> int:
        # write your code here
        n = len(nums)
        if n == 0:
            return -1

        left = 0
        right = n - 1

        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid

        return left if nums[left] == target else -1