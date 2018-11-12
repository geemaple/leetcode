class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        ans = []
        addon = 1
        i = len(digits) - 1
        
        while i >= 0 or addon > 0:
            number = digits[i] % 10 if i >= 0 else 0
            total = number + addon
            
            ans.append(total % 10)
            addon = total // 10
            
            i -= 1
            
        return ans[::-1]