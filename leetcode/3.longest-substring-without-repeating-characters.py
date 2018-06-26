class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        if s is None:
            return 0

        aSet = set()
        count = 0
        start = 0
        end = 0

        for i in range(len(s)):
            end = i
            if s[end] in aSet:
                count = max(count, end - start)

                while(s[start] != s[end]):
                    aSet.remove(s[start])
                    start += 1

                start += 1

            else:
                aSet.add(s[end])

        end = len(s) # end won't eqaul to len(s) in range
        count = max(count, end - start)

        return count