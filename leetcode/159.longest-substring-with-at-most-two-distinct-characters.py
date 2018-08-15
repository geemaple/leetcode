class Solution(object):
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """

        if s is None:
            return 0

        count_map = {}
        count = 0
        start = 0
        ans = 0

        for end in range(len(s)):
            if (count_map.get(s[end], 0) == 0):
                count += 1
            count_map[s[end]] = count_map.get(s[end], 0) + 1

            while (count > 2):
                count_map[s[start]] -= 1

                if count_map[s[start]] == 0:
                    count -= 1

                start += 1

            ans = max(ans, end - start + 1)

        return ans