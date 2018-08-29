class Solution(object):
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        j = 0
        k = 2
        count_map = dict()

        for i in range(len(s)):
            while (j < len(s) and (len(count_map) < k or (len(count_map) == k and s[j] in count_map))):
                count_map[s[j]] = count_map.get(s[j], 0) + 1
                j += 1

            res = max(res, j - i)

            if s[i] in count_map:
                count_map[s[i]] -= 1
                if count_map[s[i]] == 0:
                    del count_map[s[i]]

        return res      

