#  Tag: String, Simulation
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-158
#  Note: -

#  The API: `int read4(char *buf)` reads `4` characters at a time from a file.
#  
#  The return value is the actual number of characters read.
#  For example, it returns 3 if there is only 3 characters left in the file.
#  
#  By using the read4 API, implement the function `int read(char *buf, int n)` that reads n characters from the file.
#  
#  **Example 1**
#  
#  ```plain
#  Input:
#  "filetestbuffer"
#  read(6)
#  read(5)
#  read(4)
#  read(3)
#  read(2)
#  read(1)
#  read(10)
#  Output:
#  6, buf = "filete"
#  5, buf = "stbuf"
#  3, buf = "fer"
#  0, buf = ""
#  0, buf = ""
#  0, buf = ""
#  0, buf = ""
#  ```
#  
#  **Example 2**
#  
#  ```plain
#  Input:
#  "abcdef"
#  read(1)
#  read(5)
#  Output:
#  1, buf = "a"
#  5, buf = "bcdef"
#  ```
#  
#  The `read` function may be called multiple times.

"""
The read4 API is already defined for you.
@param buf a list of characters
@return an integer
you can call Reader.read4(buf)
"""


class Solution:

    # @param {char[]} buf destination buffer
    # @param {int} n maximum number of characters to read
    # @return {int} the number of characters read
    def __init__(self):
        self.offset = 0
        self.count = 0
        self.tmp = [''] * 4

    def read(self, buf, n):
        # Write your code here
        for i in range(n):
            if self.offset == self.count:
                self.count = Reader.read4(self.tmp)
                self.offset = 0

            if self.offset < self.count:
                buf[i] = self.tmp[self.offset]
                self.offset += 1
            else:
                return i

        return n