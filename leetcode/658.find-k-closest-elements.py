class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        size = len(arr)
        target = self.searchClosest(arr, x)
        
        start = target
        end = target
        for i in range(1, k):
            if start - 1 < 0 and end + 1 >= size:
                break
                
            if start - 1 >= 0 and end + 1 < size:
                if abs(arr[start - 1] - x) <= abs(arr[end + 1] - x):
                    start -= 1
                else:
                    end += 1
                    
            elif start - 1 >= 0:
                start -= 1
                
            else:
                end += 1
        
        return arr[start: end + 1]
        
        
    def searchClosest(self, nums, target):
        start = 0
        end = len(nums) - 1
        
        while(start + 1 < end):
            mid = start + (end - start) // 2
            
            if (nums[mid] < target):
                start = mid
            else:
                end = mid
                
        return start if abs(nums[start] - target) < abs(nums[end] - target) else end
            