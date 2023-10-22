#  Category: Binary Search on Answer, Binary Search
#  Time: O(N * logM + M * logN)
#  Space: O(1)
#  Ref: -
#  Note: Leetcode-302

#  An image is represented by a binary matrix with `0` as a white pixel and `1` as a black pixel.
#  The black pixels are connected, i.e., there is only one black region.
#  Pixels are connected horizontally and vertically.
#  Given the location `(x, y)` of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
#  
#  ---
#  
#  **Example 1:**
#  ```
#  Input：["0010","0110","0100"]，x=0，y=2
#  Output：6
#  Explanation：
#  The upper left coordinate of the matrix is (0,1), and the lower right coordinate is (2,2).
#  ```
#  
#  **Example 2:**
#  ```
#  Input：["1110","1100","0000","0000"], x = 0, y = 1
#  Output：6
#  Explanation：
#  The upper left coordinate of the matrix is (0, 0), and the lower right coordinate is (1,2).
#  ```
#  
#  

from typing import (
    List,
    Callable
)

class Solution:
    """
    @param image: a binary matrix with '0' and '1'
    @param x: the location of one of the black pixels
    @param y: the location of one of the black pixels
    @return: an integer
    """
    def min_area(self, image: List[List[str]], x: int, y: int) -> int:
        # write your code here

        left = self.search(image, 0, y, self.check_col, False)
        right = self.search(image, y, len(image[0]), self.check_col, True)
        top = self.search(image, 0, x, self.check_row, False)
        bottom = self.search(image, x, len(image), self.check_row, True)
        return (bottom - top) * (right - left)

    def check_row(self, image: List[List[str]], row: int, opposite: bool) -> bool:
        island = False
        for col in image[row]:
            if col == '1':
                island = True
                break
        return not island if opposite else island

    def check_col(self, image: List[List[str]], col: int, opposite: bool) -> bool:
        island = False
        for row in image:
            if row[col] == '1':
                island = True
                break
        return not island if opposite else island

    def search(self, image: List[List[str]], start: int, end: int, check: Callable, oppsite: True) -> int:
        while start < end:
            mid = start + (end - start) // 2
            if check(image, mid, oppsite):
                end = mid
            else:
                start = mid + 1
        return start