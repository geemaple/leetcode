import sys
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        
        if s is None or t is None or len(s) < len(t):
            return ''

        count_map = {}
        for char in t:
            count_map[char] = count_map.get(char, 0) + 1

        ans = (0, sys.maxint)

        start = 0
        missing = len(t)

        for end in range(len(s)):
            if s[end] in count_map:
                if count_map[s[end]] > 0:
                    missing -= 1
                count_map[s[end]] -= 1

            while (missing == 0):
                if ans[1] - ans[0] > end - start + 1:
                    ans = (start, end + 1)
                
                # remove start
                if s[start] in count_map:
                    if count_map[s[start]] == 0:
                        missing += 1
                    count_map[s[start]] += 1

                start += 1

        return '' if ans[1] == sys.maxint else s[ans[0]: ans[1]]
