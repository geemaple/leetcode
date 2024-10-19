#  Tag: Dynamic Programming/DP, Two Sequences DP
#  Time: O(NM)
#  Space: O(NM)
#  Ref: -
#  Note: -

#  Given two strings, find the longest common substring.
#  
#  Return the length of it.
#  
#  **Example 1:**  
#   
#  Input:  
#  ``` 
#  stringA = "ABCD"
#  stringB = "CBCE"
#  ``` 
#  Output:  
#  ``` 
#  2
#  ``` 
#  Explanation:  
#  
#  Longest common substring is "BC"
#  
#  **Example 2:**  
#   
#  Input:  
#  ``` 
#  stringA = "ABCD"
#  stringB = "EACB"
#  ``` 
#  Output:  
#  ``` 
#  1
#  ``` 
#  Explanation:  
#  
#   Longest common substring is 'A' or 'C' or 'B'
#  
#  The characters in **substring** should occur continuously in original string. This is different with **subsequence**.

class Solution:
    """
    @param a: A string
    @param b: A string
    @return: the length of the longest common substring.
    """
    def longest_common_substring(self, a: str, b: str) -> int:
        # write your code here
        n = len(a)
        m = len(b)
        dp = [[0] * m for i in range(n)]

        res = 0
        for i in range(n):
            for j in range(m):
                if a[i] == b[j]:
                    if i > 0 and j > 0:
                        dp[i][j] = dp[i - 1][j - 1] + 1
                    else:
                        dp[i][j] = 1

                    res = max(res, dp[i][j])

        return res