class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if s is None or t is None or len(s) < len(t):
            return ''

        count_set = dict()
        j = 0
        start = 0
        end = float('inf')
        remains = len(t)

        for c in t:
            count_set[c] = count_set.get(c, 0) + 1

        for i in range(len(s)):
            while(j < len(s) and remains > 0):
                if s[j] in count_set:
                    count_set[s[j]] -= 1
                    if count_set[s[j]] >= 0:
                        remains -= 1
                j += 1
            
            if (remains == 0 and j - i < end - start):
                start, end = i, j

            if s[i] in count_set:
                count_set[s[i]] += 1
                if count_set[s[i]] > 0:
                    remains += 1

        return '' if end == float('inf') else s[start: end]
