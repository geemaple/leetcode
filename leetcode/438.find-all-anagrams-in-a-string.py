class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        size = len(p)
        left = size
        counting = {}
        res = []
        for c in p:
            counting[c] = counting.get(c, 0) + 1

        back = 0
        for i in range(len(s)):
            if s[i] in counting:
                counting[s[i]] -= 1
                if counting[s[i]] >= 0:
                    left -= 1

            if i - back + 1 == size:

                if left == 0:
                    res.append(back)

                if s[back] in counting:
                    counting[s[back]] += 1
                    if counting[s[back]] > 0:
                        left += 1

                back += 1

        return res