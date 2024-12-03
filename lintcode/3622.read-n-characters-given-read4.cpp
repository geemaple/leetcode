//  Tag: Simulation
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-157
//  Note: -

//  In this question, you need to design the `read()` function to read and save the first n characters of the file into `buf`, and return the length of the read string.
//  
//  You cannot access the file directly, you need to read the file indirectly through the `read4()` function.
//  Among them, the `read4()` function reads 4 characters at a time, and if it is called multiple times, it will continue to read from the last read result.
//  Similarly, this function will also return the length of the string actually read.
//  
//  You can see more explanation in the Example.
//  
//  **Example 1**
//  
//  Input:
//  
//  ```plaintext
//  "lintcode"
//  5
//  ```
//  
//  Output:
//  
//  ```plaintext
//  5
//  lintc
//  ```
//  
//  Explanation:
//  
//  The content of file is **lintcode**, the first call to `read4()` reads **lint**, and the second call only needs to read the fifth character (**c**). So the final read string is **lintc** with a length of 5.
//  
//  **Example 2**
//  
//  Input:
//  
//  ```plaintext
//  "lintcode"
//  9
//  ```
//  
//  Output:
//  
//  ```plaintext
//  8
//  lintcode
//  ```
//  
//  **Example 3**
//  
//  Input:
//  
//  ```plaintext
//  "lintcode"
//  0
//  ```
//  
//  Output:
//  
//  ```plaintext
//  0
//  ""
//  ```
//  Note: `""` is actually an empty string.
//  
//  

int read4(char* buf);

class Solution {
public:
    /**
     * @param buf: destination
     * @param n: the number of characters that need to be read
     * @return: the number of characters read
     */
    
    int read(char* buf, int n) {
        // write you code here
        int total = 0;
        char tmp[4];
        while (total < n) {
            int count = read4(tmp);
            if (count == 0) {
                break;
            }
            int read = min(count, n - total);
            for (int i = 0; i < read; i++) {
                buf[total + i] = tmp[i];
            }
            total += read;
        }
        return total;
    }
};

int read4(char* buf);

class Solution {
public:
    /**
     * @param buf: destination
     * @param n: the number of characters that need to be read
     * @return: the number of characters read
     */
    
    int read(char* buf, int n) {
        // write you code here
        char tmp[4];
        int offset = 0;
        int count = 0;

        for(auto i = 0; i < n; ++i) {
            if (offset == count) {
                count = read4(tmp);
                offset = 0;
            }

            if (offset < count) {
                buf[i] = tmp[offset++];
            } else {
                return i;
            }
        }

        return n;
    }
};