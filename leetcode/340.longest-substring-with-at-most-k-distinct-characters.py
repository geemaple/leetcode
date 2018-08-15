class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        
        ans = 0
        count = 0
        count_map = {}
        start = 0

        for i in range(len(s)):
            if (count_map.get(s[i], 0) == 0):
                count += 1
            count_map[s[i]] = count_map.get(s[i], 0) + 1

            while (count > k):
                count_map[s[start]] -= 1
                if count_map[s[start]] == 0:
                    count -= 1
                start += 1

            ans = max(ans, i - start + 1)

        return ans