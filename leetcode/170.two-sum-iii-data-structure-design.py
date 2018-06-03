class TwoSum(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hash_map = {}

    def add(self, number):
        """
        Add the number to an internal data structure..
        :type number: int
        :rtype: void
        """
        self.hash_map[number] = self.hash_map.get(number, 0) + 1

    def find(self, value):
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        :type value: int
        :rtype: bool
        """
        for num in self.hash_map:
            
            target = value - num
            count = self.hash_map.get(value - num)

            if (count > 1) or (count == 1 and num != target):
                return True
        
        return False

# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)