#  Tag: Binary Search on Answer, Binary Search
#  Time: O(N * logM + M * logN)
#  Space: O(1)
#  Ref: Leetcode-302
#  Note: Graph

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
    @param x: the location of one of the white pixels
    @param y: the location of one of the white pixels
    @return: an integer
    """
    def min_area(self, image: List[List[str]], x: int, y: int) -> int:
        # write your code here

        n = len(image)
        m = len(image[0])

        left = self.search(image, 0, y, self.check_col, False)
        right = self.search(image, y, m, self.check_col, True)
        top = self.search(image, 0, x, self.check_row, False)
        bottom = self.search(image, x, n, self.check_row, True)
        return (bottom - top) * (right - left)

    def check_row(self, image: List[List[str]], row: int, white: bool) -> bool:
        if white:
            return all(image[row][j] == '0' for j in range(len(image[row])))
        else:
            return any(image[row][j] == '1' for j in range(len(image[row])))

    def check_col(self, image: List[List[str]], col: int, white: bool) -> bool:
        if white:
            return all(image[i][col] == '0' for i in range(len(image)))
        else:
            return any(image[i][col] == '1' for i in range(len(image)))

    def search(self, image: List[List[str]], start: int, end: int, check: Callable, oppsite: True) -> int:
        while start < end:
            mid = start + (end - start) // 2
            if check(image, mid, oppsite):
                end = mid
            else:
                start = mid + 1
        return start
    

class Solution:
    """
    @param image: a binary matrix with '0' and '1'
    @param x: the location of one of the black pixels
    @param y: the location of one of the black pixels
    @return: an integer
    """
    def min_area(self, image: List[List[str]], x: int, y: int) -> int:
        # write your code here
        n = len(image)
        m = len(image[0])

        left = 0
        right = y
        while left < right:
            mid = (left + right) // 2
            if any(image[i][mid] == '1' for i in range(n)):
                right = mid
            else:
                left = mid + 1
        
        left_most = left

        left = y
        right = m - 1
        while left < right:
            mid = (left + right) // 2 + 1
            if any(image[i][mid] == '1' for i in range(n)):
                left = mid
            else:
                right = mid - 1
                
        right_most = left


        top = 0
        bottom = x
        while top < bottom:
            mid = (top + bottom) // 2
            if any(image[mid][j] == '1' for j in range(left_most, right_most + 1)):
                bottom = mid
            else:
                top = mid + 1

        top_most = top

        top = x
        bottom = n - 1
        while top < bottom:
            mid = (top + bottom) // 2 + 1
            if any(image[mid][j] == '1' for j in range(left_most, right_most + 1)):
                top = mid
            else:
                bottom = mid - 1
        bottom_most = top

        width = right_most - left_most + 1
        height = bottom_most - top_most + 1
        return width * height