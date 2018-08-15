class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_set = set()
        ans = 0
        start = 0
        for end in range(len(s)):
            if s[end] in char_set:
                ans = max(ans, end - start)
                while(s[start] != s[end]):
                    char_set.remove(s[start])
                    start += 1
                start += 1
            else:
                char_set.add(s[end])

        ans = max(ans, len(s) - start)
        return ans