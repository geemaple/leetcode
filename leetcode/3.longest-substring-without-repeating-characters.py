class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        res = 0
        j = 0
        unique_set = set()

        for i in range(len(s)):
            while(j < len(s) and s[j] not in unique_set):
                unique_set.add(s[j])
                j += 1

            res = max(res, j - i)

            unique_set.remove(s[i])

        return res