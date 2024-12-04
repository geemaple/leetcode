#  Tag: String
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-271
#  Note: -

#  Design an algorithm to encode a list of strings to a string.
#  The encoded string is then sent over the network and is decoded back to the original list of strings.
#  
#  Please implement `encode` and `decode`
#  
#  **Example1**
#  ```
#  Input: ["lint","code","love","you"]
#  Output: ["lint","code","love","you"]
#  Explanation:
#  One possible encode method is: "lint:;code:;love:;you"
#  ```
#  **Example2**
#  ```
#  Input: ["we", "say", ":", "yes"]
#  Output: ["we", "say", ":", "yes"]
#  Explanation:
#  One possible encode method is: "we:;say:;:::;yes"
#  ```
#  
#  Because the string may contain any of the **256** legal ASCII characters, your algorithm must be able to handle any character that may appear
#  
#  Do not rely on any libraries, the purpose of this problem is to implement the "encode" and "decode" algorithms on your own

class Solution:
    """
    @param: strs: a list of strings
    @return: encodes a list of strings to a single string.
    """
    def encode(self, strs):
        # write your code here
        res = ''
        for s in strs:
            res += s.replace(':', '::') + ':;'
        return res

    """
    @param: str: A string
    @return: decodes a single string to a list of strings
    """
    def decode(self, str):
        # write your code here
        res = []
        word = ''
        i = 0
        while i < len(str):
            if str[i] == ':':
                if str[i + 1] == ':':
                    word += ':'
                else:
                    res.append(word)
                    word = ''
                i += 2
            else:
                word += str[i]
                i += 1

        return res