class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = 0
        visited = set()
        res = 0
        
        for i in range(len(s)):

            while (s[i] in visited):
                visited.remove(s[left])
                left +=1
                
            visited.add(s[i])
            
            if i - left + 1 > res:
                res = i - left + 1
                
        return res

class Solution2(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = 0
        visited = dict()
        res = 0
        
        for i in range(len(s)):
            if (s[i] in visited):
                left = max(left, visited[s[i]] + 1)
                
            visited[s[i]] = i
            
            if i - left + 1 > res:
                res = i - left + 1
                
        return res