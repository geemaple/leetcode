#  Tag: Simulation
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-157
#  Note: -

#  In this question, you need to design the `read()` function to read and save the first n characters of the file into `buf`, and return the length of the read string.
#  
#  You cannot access the file directly, you need to read the file indirectly through the `read4()` function.
#  Among them, the `read4()` function reads 4 characters at a time, and if it is called multiple times, it will continue to read from the last read result.
#  Similarly, this function will also return the length of the string actually read.
#  
#  You can see more explanation in the Example.
#  
#  **Example 1**
#  
#  Input:
#  
#  ```plaintext
#  "lintcode"
#  5
#  ```
#  
#  Output:
#  
#  ```plaintext
#  5
#  lintc
#  ```
#  
#  Explanation:
#  
#  The content of file is **lintcode**, the first call to `read4()` reads **lint**, and the second call only needs to read the fifth character (**c**). So the final read string is **lintc** with a length of 5.
#  
#  **Example 2**
#  
#  Input:
#  
#  ```plaintext
#  "lintcode"
#  9
#  ```
#  
#  Output:
#  
#  ```plaintext
#  8
#  lintcode
#  ```
#  
#  **Example 3**
#  
#  Input:
#  
#  ```plaintext
#  "lintcode"
#  0
#  ```
#  
#  Output:
#  
#  ```plaintext
#  0
#  ""
#  ```
#  Note: `""` is actually an empty string.
#  
#  

from typing import (
    List,
)

# You can use read4() function by self.read4()
class Solution(Reader):
    """
    @param buf: destination
    @param n: the number of characters that need to be read
    @return: the number of characters read
    """
    def read(self, buf: List[str], n: int) -> int:
        # write you code here
        total = 0
        tmp = [''] * 4
        while total < n:
            count = self.read4(tmp)
            if count == 0:
                break

            read = min(count, n - total)
            for i in range(read):
                buf[total + i] = tmp[i]
            total += read

        return total

# You can use read4() function by self.read4()
class Solution(Reader):
    """
    @param buf: destination
    @param n: the number of characters that need to be read
    @return: the number of characters read
    """
    def read(self, buf: List[str], n: int) -> int:
        # write you code here
        tmp = [''] * 4
        offset = 0
        count = 0

        for i in range(n):
            if offset == count:
                count = self.read4(tmp)
                offset = 0

            if offset < count:
                buf[i] = tmp[offset]
                offset += 1
            else:
                return i

        return n
    