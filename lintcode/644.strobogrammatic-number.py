class Solution:
    """
    @param num: a string
    @return: true if a number is strobogrammatic or false
    """
    def isStrobogrammatic(self, num):
        # write your code here

        if num is None or len(num) == 0:
            return True

        mirror_mapping = {'1': '1', '6': '9', '8': '8', '9': '6', '0': '0'}

        left = 0
        right = len(num) - 1

        while(left <= right):
            if num[left] not in mirror_mapping or mirror_mapping[num[left]] != num[right]:
                return False

            left += 1
            right -= 1

        return True