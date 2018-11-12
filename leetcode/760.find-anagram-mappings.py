class Solution(object):
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        mapping = {x: i for i, x in enumerate(B)}
        return [mapping[x] for x in A]