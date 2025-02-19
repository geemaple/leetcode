#  Tag: String, Backtracking
#  Time: O(NK)
#  Space: O(N + K)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/8OpQ-jZ73Hg

#  A happy string is a string that:
#  
#  consists only of letters of the set ['a', 'b', 'c'].
#  s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
#  
#  For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
#  Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
#  Return the kth string of this list or return an empty string if there are less than k happy strings of length n.
#   
#  Example 1:
#  
#  Input: n = 1, k = 3
#  Output: "c"
#  Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
#  
#  Example 2:
#  
#  Input: n = 1, k = 4
#  Output: ""
#  Explanation: There are only 3 happy strings of length 1.
#  
#  Example 3:
#  
#  Input: n = 3, k = 9
#  Output: "cab"
#  Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
#  
#   
#  Constraints:
#  
#  1 <= n <= 10
#  1 <= k <= 100
#  
#  

class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        letter = ['a', 'b', 'c']
        res = []
        self.helper(letter, n, k, 0, res, '')
        return res[-1] if len(res) == k else ''


    def helper(self, letter: list, n: int, k: int, i: int, res: list, tmp: str) -> bool:
        if i == n:
            res.append(tmp)
            return len(res) == k

        for l in letter:
            if i == 0 or l != tmp[-1]:
                if self.helper(letter, n, k, i + 1, res, tmp + l):
                    return True

        return False