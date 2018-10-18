class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        res = 0
        i = 0
        count_map = {}

        for j in range(len(s)):

            count_map[s[j]] = count_map.get(s[j], 0) + 1

            while len(count_map) > k:
                count_map[s[i]] -= 1
                if count_map[s[i]] == 0:
                    del count_map[s[i]]

                i += 1

            res = max(res, j - i + 1)

        return res
