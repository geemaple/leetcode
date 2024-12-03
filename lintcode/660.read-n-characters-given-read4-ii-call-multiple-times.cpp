//  Tag: String, Simulation
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-158
//  Note: -

//  The API: `int read4(char *buf)` reads `4` characters at a time from a file.
//  
//  The return value is the actual number of characters read.
//  For example, it returns 3 if there is only 3 characters left in the file.
//  
//  By using the read4 API, implement the function `int read(char *buf, int n)` that reads n characters from the file.
//  
//  **Example 1**
//  
//  ```plain
//  Input:
//  "filetestbuffer"
//  read(6)
//  read(5)
//  read(4)
//  read(3)
//  read(2)
//  read(1)
//  read(10)
//  Output:
//  6, buf = "filete"
//  5, buf = "stbuf"
//  3, buf = "fer"
//  0, buf = ""
//  0, buf = ""
//  0, buf = ""
//  0, buf = ""
//  ```
//  
//  **Example 2**
//  
//  ```plain
//  Input:
//  "abcdef"
//  read(1)
//  read(5)
//  Output:
//  1, buf = "a"
//  5, buf = "bcdef"
//  ```
//  
//  The `read` function may be called multiple times.

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    int count = 0;
    int offset = 0;
    char tmp[4];
    int read(char *buf, int n) {
        // Write your code here
        int length = 0;
        while (length < n) {
            if (count == offset) {
                count = read4(tmp);
                offset = 0;
            }

            if (offset < count) {
                buf[length++] = tmp[offset++];
            } else {
                break;
            }
        }
        return length;
    }
};