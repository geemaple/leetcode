#  Tag: Binary Search, Dynamic Programming/DP, Binary Search on Answer, Partition DP
#  Time: O(N*logP)
#  Space: O(1)
#  Ref: -
#  Note: Answer | DP

#  Given `n` books and the `i-th` book has `pages[i]` pages.
#  There are `k` persons to copy these books.
#  
#  These books list in a row and each person can claim a continous range of books.
#  For example, one copier can copy the books from `i-th` to `j-th` continously, but he can not copy the 1st book, 2nd book and 4th book (without 3rd book).
#  
#  They start copying books at the same time and they all cost 1 minute to copy 1 page of a book.
#  What's the best strategy to assign books so that the slowest copier can finish at earliest time? 
#  
#  Return the shortest time that the slowest copier spends.
#  
#  ---
#  
#  **Example 1:**
#  
#  ```
#  Input: pages = [3, 2, 4], k = 2
#  Output: 5
#  Explanation: 
#      First person spends 5 minutes to copy book 1 and book 2.
#      Second person spends 4 minutes to copy book 3.
#  ```
#  
#  **Example 2:**
#  
#  ```
#  Input: pages = [3, 2, 4], k = 3
#  Output: 4
#  Explanation: Each person copies one of the books.
#  ```
#  
#  The sum of book pages is less than or equal to 2147483647

from typing import (
    List,
)

class Solution:
    """
    @param pages: an array of integers
    @param k: An integer
    @return: an integer
    """
    def copy_books(self, pages: List[int], k: int) -> int:
        # write your code here
        if len(pages) == 0:
            return 0

        left = max(pages)
        right = sum(pages)
        while left < right:
            mid = (left + right) // 2
            if self.can_finish(pages, k, mid):
                right = mid
            else:
                left = mid + 1

        return left


    def can_finish(self, pages: list, k: int, minites: int)-> bool:
        assign = 0
        worker = 1
        for p in pages:
            if assign + p <= minites:
                assign += p
            else:
                worker += 1
                assign = p

        return worker <= k
    
class Solution:
    """
    @param pages: an array of integers
    @param k: An integer
    @return: an integer
    """
    def copy_books(self, pages: List[int], k: int) -> int:
        # write your code here
        n = len(pages)
        dp = [[float('inf')] * (n + 1) for i in range(k + 1)]

        for i in range(k + 1):
            dp[i][0] = 0

        for i in range(1, k + 1):
            for j in range(1, n + 1):
                work_load = 0
                for p in range(j - 1, -1, -1):
                    work_load += pages[p]
                    cost = max(dp[i - 1][p], work_load)
                    dp[i][j] = min(dp[i][j], cost)

        return dp[k][n]